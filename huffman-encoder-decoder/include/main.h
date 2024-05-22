#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

#include "huffman_tree.h"

using namespace std;
using Status = int;

const int N = 1e6 + 7;
const int TRUE = 1;
const int FALSE = 0;
const int OK = 1;
const int ERROR = 0;
const int INFEASIBLE = -1;
// const int OVERFLOW = -2;

Status initialization();
Status encoding();
Status decoding();
Status print();
Status treePrint();
Status home();

HuffmanTree getHuffmanTree();
Status createHuffmanTree(int n, map<char, int> charset);
map<char, string> *getHuffmanCode();
#endif
