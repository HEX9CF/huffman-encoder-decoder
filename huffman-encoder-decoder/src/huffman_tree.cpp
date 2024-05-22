#include "../include/main.h"

static HuffmanTree huffmanTree;
static map<char, string> huffmanCode;
static bool treeExist = false;
static bool codeExist = false;

// 创建树节点
TreeNode *createTreeNode(char e, TreeNode *l, TreeNode *r) {
	TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
	if (!t) {
		return NULL;
	}
	t->data = e;
	t->left = l;
	t->right = r;
	return t;
}

// 创建哈夫曼树
Status createHuffmanTree(int n, map<char, int> charset) {
	priority_queue<Node> hmin;
	for (const auto i : charset) {
		TreeNode *t = createTreeNode(i.first, nullptr, nullptr);
		hmin.push({i.second, t});
	}
	while (hmin.size() > 1) {
		Node a = hmin.top();
		hmin.pop();
		Node b = hmin.top();
		hmin.pop();
		if (a.f > b.f) {
			swap(a, b);
		}
		TreeNode *t = createTreeNode(' ', a.node, b.node);
		// cout << a.f << " " << b.f << endl;
		hmin.push({a.f + b.f, t});
	}
	 huffmanTree = hmin.top().node;
	 treeExist = true;
	 return OK;
}

// 先序遍历哈夫曼树
void preorder(HuffmanTree T, string c) {
	if (T) {
		if (T->data != ' ') {
			// cout << T->data << ": " << c << endl;
			huffmanCode[T->data] = c;
			return;
		}
		preorder(T->left, c + "0");
		preorder(T->right, c + "1");
	}
}

// 生成哈夫曼编码
Status generateHuffmanCode() {
	preorder(huffmanTree, "");
	codeExist = true;
	return OK;
}

// 从文件读取哈夫曼编码
Status readHuffmanCode() {
	char c;
	string s;
	ifstream fin;

	fin.open("hfmTree", ios::in);
	if (!fin) {
		cerr << "发生错误：无法打开文件 hfmTree 。" << endl;
		system("pause");
		return ERROR;
	}

	while(fin >> c >> s) {
		huffmanCode[c] = s;
	}
	codeExist = true;
	return OK;
}

// 根据哈夫曼编码建立哈夫曼树
Status createTreeByCode() {
	TreeNode* p;

	huffmanTree = createTreeNode(' ', nullptr, nullptr);
	for (const auto i : huffmanCode) {
		p = huffmanTree;
		for (const auto j : i.second) {
			if (j == '0') {
				if (!p->left) {
					p->left = createTreeNode(' ', nullptr, nullptr);
				}
				p = p->left;
			}
			else {
				if (!p->right) {
					p->right = createTreeNode(' ', nullptr, nullptr);
				}
				p = p->right;
			}
		}
		p->data = i.first;
	}
	treeExist = true;
	return OK;
}

HuffmanTree getHuffmanTree() {
	if (!treeExist) {
		if (codeExist) {
			createTreeByCode();
		}
		else {
			readHuffmanCode();
			createTreeByCode();
		}
	}
	return huffmanTree;
}

map<char, string>* getHuffmanCode() {
	if(!codeExist) {
		if (treeExist) {
			generateHuffmanCode();
		}
		else {
			readHuffmanCode();
		}
	}
	return &huffmanCode;
}

