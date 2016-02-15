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
  percolateDown(tree, size-1);

  return temp;
}
void percolateDown(treeNode* tree[], int size){
int satisfied = 0;

  int j=0;
  while (satisfied==0){ //is this still applicable?
    if(j>size/2){
      satisfied=1;
    }
    if (j*2+2>=size){
      if(tree[j]->freq>tree[j*2+1]->freq){
        
        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        
        tree[j*2+1]->freq=temp->freq;
        tree[j*2+1]->stored=temp->stored;

      }
      satisfied=1;
    }
    else{
      if((tree[j*2+1]->freq)<(tree[j]->freq)&&(tree[j*2+2]->freq<tree[j]->freq)){ // if both left and right children are less than parent
        if((tree[j*2+1]->freq)<(tree[j*2+2]->freq)) { // if left child is less than right, swap left with parent
        
        //temp node for swap
        treeNode* temp= new treeNode;
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        
        tree[j*2+1]->freq=temp->freq;
        tree[j*2+1]->stored=temp->stored;

        j=j*2+1;

      }
      else{ // if right child is less than left, swap right with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[j*2+2]->freq;
        tree[j]->stored = tree[j*2+2]->stored;
        
        tree[j*2+2]->freq=temp->freq;
        tree[j*2+2]->stored=temp->stored;

     j=j*2+2;
        
      }
    }
    else if((tree[j*2+1]->freq)<(tree[j]->freq) && (tree[j*2+2]->freq>=tree[j]->freq)) {   // if left<parent and right>parent, swap left with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        
        tree[j*2+1]->freq=temp->freq;
        tree[j*2+1]->stored=temp->stored;

        j=j*2+1;

    }
   else if((tree[j*2+1]->freq)>=(tree[j]->freq)&&(tree[j*2+2]->freq<tree[j]->freq)) // if left>parent and right<parent, swap right with parent
      {

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[j*2+2]->freq;
        tree[j]->stored = tree[j*2+2]->stored;
        
        tree[j*2+2]->freq=temp->freq;
        tree[j*2+2]->stored=temp->stored;

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

void insertnode(treeNode* insert[], treeNode* newNode, int lastIndex){
  insert[lastIndex]= newNode;
  percolateUp(insert,lastIndex);


}



void percolateUp(treeNode* tree[], int size){
  int satisfied=0;

  int j=size; 
while (satisfied==0){ //is this still applicable?
    if(j==0){
      satisfied=1;
    }
    if(tree[j]<tree[(j+1)/2-1]){
       treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;

        tree[j]->freq = tree[(j+1)/2-1]->freq;
        tree[j]->stored = tree[(j+1)/2-1]->stored;
        
        tree[(j+1)/2-1]->freq=temp->freq;
        tree[(j+1)/2-1]->stored=temp->stored;

      j=(j+1)/2-1;

    }

else {
  satisfied=1; 
}


  
}
}

treeNode* makeTrie(treeNode* minheap[], int size){
  int lastindex=size-1;
treeNode* first;
treeNode* second;
treeNode* trie=new treeNode;
while(lastindex!=0)
{
   
  trie->freq=0;
  first=deleteMin(minheap, lastindex);

  trie->right=first;
  lastindex--;
  second=deleteMin(minheap,lastindex);
  trie->left=second;
  
  trie->freq=trie->left->freq+trie->right->freq;
  insertnode(minheap,trie,lastindex);
  trie->isleaf=0;
  


}
treeNode* root= new treeNode;
root->right=first;
root->left=second;
root->freq=(first->freq)+(second->freq);
root->stored=NULL;

}
