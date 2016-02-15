#ifndef ENCODE_H
#define ENCODE_H
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "heap.h"

treeNode* deleteMin(treeNode* tree, int size);
void percolateDown(treeNode*tree, int size);
void insertnode(treeNode* insert[], treeNode*);
void percolateUp(treeNode*tree, int size);
void makeTrie(treeNode* minheap[], int size){

#endif