#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
using Status = int;
using ElemType = int;

const int N = 1e6 + 7;
const int TRUE = 1;
const int FALSE = 0;
const int OK = 1;
const int ERROR = 0;
const int INFEASIBLE = -1;
// const int OVERFLOW = -2;

Status initialization() {

	return OK;
}

Status encoding() {

	return OK;
}

Status decoding() {

	return OK;
}

Status print() {

	return OK;
}

Status treePrint() {

	return OK;
}

Status menu() {
	char op;
	while (1) {
		system("cls");
		cout << " - 哈夫曼编/译码器 - " << endl;
		cout << "I. 初始化（Initialization）" << endl;
		cout << "E. 编码（Encoding）" << endl;
		cout << "D. 译码（Decoding）" << endl;
		cout << "P. 印代码文件（Print）" << endl;
		cout << "T. 印哈夫曼树（Tree printing）" << endl;
		cout << "Q. 退出运行（Quit）" << endl;
		cout << "请输入指令：";
		cin >> op;
		switch (op) {
			case 'I':
				initialization();
				break;
			case 'E':
				encoding();
				break;
			case 'D':
				decoding();
				break;
			case 'P':
				print();
				break;
			case 'T':
				treePrint();
				break;
			case 'Q':
				return OK;
				break;
			default:
				cout << "未知指令" << endl;
				system("pause");
		}
	}
	return OK;
}

int main() {
	menu();
	return 0;
}
