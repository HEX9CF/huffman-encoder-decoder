#pragma once
#ifndef MAIN_H
#define MAIN_H
 
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
using Status = int;
using ElemType = int;

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
 
#endif

