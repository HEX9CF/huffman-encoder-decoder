#include "../include/main.h"

/*
印哈夫曼树（Tree printing），
将已在内存中的哈夫曼树以直观的方式（树或凹入表形式）显示在终端上，同时将此字符形式的哈夫曼树写入文件TreePrint中。
*/

// 遍历哈夫曼树
void traverse(HuffmanTree T, int d, string c) {
	if (T) {
		if (!d) {
			cout << "root" << endl;
		} else if (T->data == ' ') {
			cout << c << endl;
		}
		else {
			cout << T->data << ": " << c << endl;
		}
		if (T->left) {
			for (int i = 0; i < d; i++) {
				cout << "  ";
			}
			cout << "└─";
			traverse(T->left, d + 1, c + "0");
		}
		if (T->right) {
			for (int i = 0; i < d; i++) {
				cout << "  ";
			}
			cout << "└─";
			traverse(T->right, d + 1, c + "1");
		}
	}
}

Status treePrint() {
	system("cls");
	cout << " - 印哈夫曼树（Tree printing） - " << endl;

	// 读取哈夫曼树
	HuffmanTree huffmanTree = getHuffmanTree();
	if (!huffmanTree) {
		cerr << "发生错误：无法读取哈夫曼树。" << endl;
		system("pause");
		return ERROR;
	}

	traverse(huffmanTree, 0, "");
	system("pause");
	return OK;
}
