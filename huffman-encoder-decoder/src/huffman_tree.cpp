#include "../include/main.h"

static HuffmanTree huffmanTree;
static map<char, string> huffmanCode;

HuffmanTree getHuffmanTree() {
	return huffmanTree;
}

map<char, string> getHuffmanCode() {
	return huffmanCode;
}

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
	return OK;
}

