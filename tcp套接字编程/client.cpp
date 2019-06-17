#include "tcpsocket.hpp"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "./tcp_sercer  169.254.29.197 9000" << endl;
		return -1;
	}
	string ip = argv[1];
	const int  port = atoi(argv[2]);
	tcpsocket client_sock;

	// �����׽���
	CHECK_RET(client_sock.Scoket());
	// �󶨵�ַ��Ϣ���ͻ��˲������ֶ���
	// ��ʼ����������
	CHECK_RET(client_sock.Connect(ip, port));

	// ��ʼ�������ݽ���
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