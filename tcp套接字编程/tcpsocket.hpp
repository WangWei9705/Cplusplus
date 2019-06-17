#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <Windows.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"Ws2_32.lib")

#define CHECK_RET(q) if((q) == false) {return -1;}

class tcpsocket
{
public:
	tcpsocket()
		: _fd(-1)
	{}
	~tcpsocket() {
		closesocket(_fd);
	}
	// 创建套接字
	bool Scoket() {
		_fd = socket(AF_INET, SOCK_STREAM, 0);    // 使用ipv4协议流式传送方式
		if (_fd < 0) {
			perror("socket error");
			return false;
		}
		return true;
	}
	// 为套接字绑定地址
	bool Bind(string &ip, const int port) {
		SOCKADDR_IN addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
	
		int ret = bind(_fd, (SOCKADDR*)&addr, sizeof(SOCKADDR));
		if (ret < 0) {
			perror("bind error");
			return false;
		}
		return true;
	}

	// 服务端监听
	bool Listen() {
		int ret = listen(_fd, 5);
		if (ret < 0) {
			perror("listen error");
			return false;
		}
		return true;
	}
	// 客户端请求连接
	bool Connect(string &server_ip, const int server_port) {
		SOCKADDR_IN addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.S_un.S_addr = inet_addr(server_ip.c_str());
		addr.sin_port = htons(server_port);

		int ret = connect(_fd, (SOCKADDR*)&addr, sizeof(SOCKADDR));
		if (ret < 0) {
			perror("connect error");
			return false;
		}
		return true;
	}
	// 服务端接受连接请求
	bool Accept(tcpsocket &client, string &client_ip, int &client_port) {
		// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
		// addr 监听到的客户端地址信息       addrlen 监听到的客户端的地址信息长度
		SOCKADDR_IN addr;
		int len = sizeof(SOCKADDR);
		int ret = accept(_fd, (SOCKADDR*)&addr, &len);
		if (ret < 0) {
			perror("accept error");
			return false;
		}

		// 新的cockfd
		client.SetFd(ret);
		client_ip = inet_ntoa(addr.sin_addr);
		client_port = ntohs(addr.sin_port);
		return true;

	}
	void SetFd(int fd) {
		_fd = fd;
	}



	// 接收信息
	bool Recv(string &buf) {
		char temp[1024];
		int ret = recv(_fd, temp, 1024, 0);
		if (ret < 0) {
			perror("recv error");
			return false;
		}
		else if (ret == 0) {
			cout << "perr shutdown" << endl;
			return false;
		}
		buf.assign(temp, ret);
		return true;
	}
	// 发送数据
	bool Send(string &buf) {
		int ret = send(_fd, buf.c_str(), buf.size(), 0);
		if (ret < 0) {
			perror("send error");
			return false;
		}
		return true;
	}
	// 关闭套接字
	bool Closesocket() {
		closesocket(_fd);
		return true;
	}
	// 终止WinSock
	bool Cleanup() {
		WSACleanup();
		return true;
	}

private:

	SOCKET _fd;
};
