#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
using namespace std;
struct treeNode{
  int freq;
  treeNode* left;
  treeNode* right;
  char stored;
  int isleaf;
};

void heapify(treeNode* input[], int size);

#endif