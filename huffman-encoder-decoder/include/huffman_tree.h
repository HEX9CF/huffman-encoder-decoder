#pragma once
#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

struct TreeNode {
	char data;
	TreeNode *left, *right;
};
using HuffmanTree = TreeNode *;

struct Node {
	int f;
	TreeNode *node;
	bool operator<(const Node &b) const { return f > b.f; }
};

#endif
