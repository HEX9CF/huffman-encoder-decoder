﻿#include "../include/main.h"

/*
初始化（Initialization）。
从终端读入字符集大小n，以及n个字符和n个权值建立哈夫曼树，并将它存于文件hfmTree中。
*/

Status initialization() {
	int n = 0;
	ofstream fout;
	map<char, int> charset;

	// 打开文件
	fout.open("hfmTree", ios::out);
	if (!fout) {
		cerr << "发生错误：无法打开文件 hfmTree 。" << endl;
		system("pause");
		return ERROR;
	}

	// 读入字符集
	system("cls");
	cout << " - 初始化（Initialization） - " << endl;
	cout << "请输入字符集大小：";
	cin >> n;
	cout << "请输入 " << n << " 组字符及其权值：（字符 权值）" << endl;
	for (int i = 1; i <= n; i++) {
		char c;
		int w;
		cin >> c >> w;
		charset[c] = w;
	}

	// 建立哈夫曼树
	if (createHuffmanTree(n, charset)) {
		cout << "已建立哈夫曼树。" << endl;
	}
	else {
		cerr << "发生错误：无法建立哈夫曼树。" << endl;
		system("pause");
		return ERROR;
	}
	if (generateHuffmanCode()) {
		cout << "已生成哈夫曼编码。" << endl;
	}
	else {
		cerr << "发生错误：无法生成哈夫曼编码。" << endl;
		system("pause");
		return ERROR;
	}

	// 写入文件
	map<char, string> code = getHuffmanCode();
	for (const auto i : code) {
		fout << i.first << " " << i.second << endl;
	}
	fout.close();
	cout << "已将哈夫曼树存于文件 hfmTree 中。" << endl;
	system("pause");
	return OK;
}
