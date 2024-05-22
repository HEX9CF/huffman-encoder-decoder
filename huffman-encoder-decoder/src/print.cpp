#include "../include/main.h"

/*
印代码文件（Print）。
将文件CodeFile以紧凑格式显示在终端上，每行50个代码。同时将此字符形式的编码文件写入文件CodePrint中。
*/

Status print() { 
	int cnt;
	string code;
	ifstream fin;
	ofstream fout;
	
	system("cls");
	cout << " - 印代码文件（Print） - " << endl;

	// 打开文件
	fin.open("CodeFile", ios::in);
	if(!fin) {
		cerr << "发生错误：无法打开文件 CodeFile 。" << endl;
		system("pause");
		return ERROR;
	}
	fout.open("CodePrint", ios::out);
	if(!fout) {
		cerr << "发生错误：无法打开文件 CodePrint 。" << endl;
		system("pause");
		return ERROR;
	}

	cout << "\n";
	cnt = 0;
	while (fin >> code) {
		cout << code << " ";
		fout << code << " ";
		cnt++;
		if(cnt >= 50) {
			cout << "\n";
			fout << "\n";
			cnt = 0;
		}
	} 

	cout << "\n\n" << "印代码文件完成。" << endl;
	fin.close();
	fout.close();
	system("pause");
	return OK;
}
