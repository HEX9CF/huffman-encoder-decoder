#include "../include/main.h"

/*
译码（Decoding）。
利用已建好的哈夫曼树将文件CodeFile中的代码进行译码，结果存入文件'TextFile中。
*/

Status decoding() { 
	string code;
	ifstream fin;
	ofstream fout;
	
	system("cls");
	cout << " - 译码（Decoding） - " << endl;

	// 读取哈夫曼树
	HuffmanTree huffmanTree = getHuffmanTree();
	if(!huffmanTree) {
		cerr << "发生错误：无法读取哈夫曼树。" << endl;
		system("pause");
		return ERROR;
	}

	// 打开文件
	fin.open("CodeFile", ios::in);
	if (!fin) {
		cerr << "发生错误：无法打开文件 CodeFile 。" << endl;
		system("pause");
		return ERROR;
	}
	fout.open("TextFile", ios::out);
	if(!fout) {
		cerr << "发生错误：无法打开文件 TextFile 。" << endl;
		system("pause");
		return ERROR;
	}

	cout << "正在译码..." << "\n" << endl;
	while (fin >> code) {
		string text = "";
		TreeNode* p = huffmanTree;
		for (const auto i : code) {
			if (i == '0') {
				p = p->left;
			}
			else {
				p = p->right;
			}
			if (!p) {
				cerr << "发生错误：无法译码。" << endl;
				system("pause");
				return ERROR;
			}
			if (p->data != ' ') {
				text += p->data;
				p = huffmanTree;
			}
		}
		cout << text << " ";
		fout << text << " ";
	} 

	cout << "\n\n" << "译码完成。" << endl;
	cout << "已将译码结果存于文件 TextFile 中。" << endl;
	system("pause");
	fin.close();
	fout.close();
	return OK;
}
