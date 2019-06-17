#include "tcpsocket.hpp"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "./tcp_sercer  169.254.29.197 9000" << endl;
		return -1;
	}
	string ip = argv[1];
	const int  port = atoi(argv[2]);
	tcpsocket client_sock;

	// 创建套接字
	CHECK_RET(client_sock.Scoket());
	// 绑定地址信息，客户端不建议手动绑定
	// 开始请求建立连接
	CHECK_RET(client_sock.Connect(ip, port));

	// 开始进行数据交换
	while (1) {
		string buf;
		cout << "client say:";
		fflush(stdout);
		scanf("%s", buf);
		client_sock.Send(buf);

		buf.clear();
		client_sock.Recv(buf);
		printf("Server say: %s", buf);
	}
	client_sock.Closesocket();
	client_sock.Cleanup();
	
	system("pause");
	return 0;

}