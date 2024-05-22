#include "../include/main.h"

/*
印哈夫曼树（Tree printing），
将已在内存中的哈夫曼树以直观的方式（树或凹入表形式）显示在终端上，同时将此字符形式的哈夫曼树写入文件TreePrint中。
*/

static ofstream fout;
 
// 遍历哈夫曼树
void traverse(HuffmanTree T, int d, string c) {
	if (T) {
		if (!d) {
			cout << "root" << endl;
			fout << "root" << endl;
		} else if (T->data == ' ') {
			cout << c << endl;
			fout << c << endl;
		}
		else {
			cout << T->data << ": " << c << endl;
			fout << T->data << ": " << c << endl;
		}
		if (T->left) {
			for (int i = 0; i < d; i++) {
				cout << "  ";
				fout << "  ";
			}
			cout << "└─";
			fout << "  "; 
			traverse(T->left, d + 1, c + "0");
		}
		if (T->right) {
			for (int i = 0; i < d; i++) {
				cout << "  ";
				fout << "  ";
			}
			cout << "└─";
			fout << "  "; 
			traverse(T->right, d + 1, c + "1");
		}
	}
}

Status treePrint() {
	system("cls");
	cout << " - 打印哈夫曼树（Tree printing） - " << endl;

	// 读取哈夫曼树
	HuffmanTree huffmanTree = getHuffmanTree();
	if (!huffmanTree) {
		cerr << "发生错误：无法读取哈夫曼树。" << endl;
		system("pause");
		return ERROR;
	}

	// 打开文件
	fout = ofstream("TreePrint", ios::out);
	if (!fout) {
		cerr << "发生错误：无法打开文件 TreePrint 。" << endl;
		system("pause");
		return ERROR;
	}

	// 遍历哈夫曼树
	cout << "\n";
	traverse(huffmanTree, 0, "");
	cout << "\n" << "已将字符形式的哈夫曼树存于文件 TreePrint 中。" << endl;

	fout.close();
	system("pause");
	return OK;
}
