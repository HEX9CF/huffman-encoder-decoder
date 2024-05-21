#include "../include/main.h"

Status home() {
	char op;
	while (1) {
		system("cls");
		cout << " - 哈夫曼编/译码器 - " << endl;
		cout << "i. 初始化（Initialization）" << endl;
		cout << "e. 编码（Encoding）" << endl;
		cout << "d. 译码（Decoding）" << endl;
		cout << "p. 印代码文件（Print）" << endl;
		cout << "t. 印哈夫曼树（Tree printing）" << endl;
		cout << "q. 退出运行（Quit）" << endl;
		cout << "请输入指令：";
		cin >> op;
		switch (op) {
			case 'i':
				initialization();
				break;
			case 'e':
				encoding();
				break;
			case 'd':
				decoding();
				break;
			case 'p':
				print();
				break;
			case 't':
				treePrint();
				break;
			case 'q':
				return OK;
				break;
			default:
				cout << "未知指令" << endl;
				system("pause");
		}
	}
	return OK;
}
