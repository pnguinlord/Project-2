#ifndef ENCODE_H
#define ENCODE_H
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "heap.h"
using namespace std;

treeNode* deleteMin(treeNode**, int);
void percolateDown(treeNode**, int );
void insertnode(treeNode**, treeNode*,int );
void percolateUp(treeNode**, int);
treeNode* makeTrie(treeNode** , int);

#endif