#include "tcpsocket.hpp"


int main(int argc, char *argv[]) {
	if (argc < 2) {
		cout << "./tcp_sercer  169.254.29.197 9000" << endl;
		return 0;
	}
	string ip = argv[1];
	const int  port = atoi(argv[2]);

	tcpsocket server_sock;

	// �����׽���
	CHECK_RET(server_sock.Scoket());
	// Ϊ�׽��ְ󶨵�ַ
	CHECK_RET(server_sock.Bind(ip, port));
	// ��ʼ����
	CHECK_RET(server_sock.Listen());
	// ��ʼ���ݴ���
	while (1) {
		tcpsocket client_sock;
		string client_ip;
		int clinet_port;
		if (server_sock.Accept(client_sock, client_ip, clinet_port) == false) {
			continue;
		}
		printf("New Client:%s %d \n", client_ip, clinet_port);

		string buf;
		client_sock.Recv(buf);
		printf("Client say:%s",buf);
		scanf("%s", &buf);
		client_sock.Send(buf);
	}
	// �ر��׽���
	 server_sock.Closesocket();
	 server_sock.Cleanup();

	system("pause");
	return 0;

}