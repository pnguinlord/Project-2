#include <iostream>
#include <exception>
#include <string>
#include <cstdio>

using namespace std;

#include "encode.h"
#include "heap.h"

treeNode* deleteMin(treeNode* tree[], int size){
  
  //temp is min node
  treeNode* temp = new treeNode();
  temp->freq = tree[0]->freq;
  temp->stored = tree[0]->stored;

  //overwrite min node with right most leaf on bottom layer
  tree[0]->freq = tree[size]->freq;
  tree[0]->stored = tree[size]->freq;

  //lowest rightest node is virtually deleted outside of this function with lastIndex--
  //percolate top node down to satistfy tree
//  percolateDown(treeNode* tree, size-1);

  return temp;
}
void percolateDown(treeNode*tree, int size){

}

void insertnode(treeNode* insert[], treeNode*){

}
void percolateUp(treeNode*tree, int size){
  
}
