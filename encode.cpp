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
void percolateDown(treeNode*tree[], int size){
int satisfied = 0;

  int j=0;
  while (satisfied==0){ //is this still applicable?
    if(j>size/2){
      satisfied=1;
    }
    if (j*2+2>=size){
      if(input[j]->freq>input[j*2+1]->freq){
        
        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = input[j]->freq;
        temp->stored = input[j]->stored;

        input[j]->freq = input[j*2+1]->freq;
        input[j]->stored = input[j*2+1]->stored;
        
        input[j*2+1]->freq=temp->freq;
        input[j*2+1]->stored=temp->stored;

      }
      satisfied=1;
    }
    else{
      if((input[j*2+1]->freq)<(input[j]->freq)&&(input[j*2+2]->freq<input[j]->freq)){ // if both left and right children are less than parent
        if((input[j*2+1]->freq)<(input[j*2+2]->freq)) { // if left child is less than right, swap left with parent
        
        //temp node for swap
        treeNode* temp= new treeNode;
        temp->freq = input[j]->freq;
        temp->stored = input[j]->stored;

        input[j]->freq = input[j*2+1]->freq;
        input[j]->stored = input[j*2+1]->stored;
        
        input[j*2+1]->freq=temp->freq;
        input[j*2+1]->stored=temp->stored;

        j=j*2+1;

      }
      else{ // if right child is less than left, swap right with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = input[j]->freq;
        temp->stored = input[j]->stored;

        input[j]->freq = input[j*2+2]->freq;
        input[j]->stored = input[j*2+2]->stored;
        
        input[j*2+2]->freq=temp->freq;
        input[j*2+2]->stored=temp->stored;

     j=j*2+2;
        
      }
    }
    else if((input[j*2+1]->freq)<(input[j]->freq) && (input[j*2+2]->freq>=input[j]->freq)) {   // if left<parent and right>parent, swap left with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = input[j]->freq;
        temp->stored = input[j]->stored;

        input[j]->freq = input[j*2+1]->freq;
        input[j]->stored = input[j*2+1]->stored;
        
        input[j*2+1]->freq=temp->freq;
        input[j*2+1]->stored=temp->stored;

        j=j*2+1;

    }
   else if((input[j*2+1]->freq)>=(input[j]->freq)&&(input[j*2+2]->freq<input[j]->freq)) // if left>parent and right<parent, swap right with parent
      {

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = input[j]->freq;
        temp->stored = input[j]->stored;

        input[j]->freq = input[j*2+2]->freq;
        input[j]->stored = input[j*2+2]->stored;
        
        input[j*2+2]->freq=temp->freq;
        input[j*2+2]->stored=temp->stored;

      j=j*2+2;

      }
    else{
      satisfied=1;
    }

      }
      if(j>size/2){
      satisfied=1;
    }
    }

}

void insertnode(treeNode* insert[], treeNode*, int lastIndex){

}
void percolateUp(treeNode*tree, int size){
  
}

void makeTrie(treeNode* minheap[], int size){
  int lastindex=size-1;
treeNode* first;
treeNode* second;
while(lastindex!=0)
{
  treeNode* trie=new treeNode();
  trie->freq=0;
  first=deleteMin(minheap, lastindex);

  trie->right=first;
  lastindex--;
  second=deleteMin(minheap);
  trie->left=second;
  lastindex--;
  trie->freq=trie->left->freq+trie->right->freq;
  insertnode(minheap,trie,lastindex);
  lastindex++;


}
treeNode* root= new treeNode();
root->right=first;
root->left=second;
root->freq=right->freq+left->freq;

}