#include "../include/main.h"

/*
编码（Encoding）。
利用已建好的哈夫曼树（如不在内存，则从文件HfmTree中读入），对文件ToBeTran中的正文进行编码，然后将结果存入文件CodeFile中。
*/

Status encoding() { 
	string text;
	ifstream fin;
	ofstream fout;
 
	system("cls");
	cout << " - 编码（Encoding） - " << endl;

	// 读取哈夫曼编码
	map<char, string> *huffmanCode = getHuffmanCode();
	if (!huffmanCode) {
		cerr << "发生错误：无法读取哈夫曼编码。" << endl;
		system("pause");
		return ERROR;
	}

	// 打开文件
	fin.open("ToBeTran", ios::in);
	if(!fin) {
		cerr << "发生错误：无法打开文件 ToBeTran 。" << endl;
		system("pause");
		return ERROR;
	}
	fout.open("CodeFile", ios::out);
	if(!fout) {
		cerr << "发生错误：无法打开文件 CodeFile 。" << endl;
		system("pause");
		return ERROR;
	} 


	// 编码
	cout << "正在编码..." << "\n" << endl;
	while (fin >> text) {
		string code = "";
		for (const auto i : text) {
			code += (*huffmanCode)[i];
		}
		fout << code << " ";
		cout << code << " ";
	} 
	cout << "\n\n" << "编码完成。" << endl;
	cout << "编码结果已存于文件 CodeFile 中。" << endl;

	fin.close();
	fout.close();
	system("pause");
	return OK;
}
