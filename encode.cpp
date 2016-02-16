#include <iostream>
#include <exception>
#include <string>
#include <cstdio>

using namespace std;

#include "encode.h"
#include "heap.h"


treeNode* deleteMin(treeNode* tree[], int lastIndex){
  
  //temp is min node
  treeNode* temp = new treeNode();
  temp->freq = tree[0]->freq;
  temp->stored = tree[0]->stored;
  temp->left=tree[0]->left;
  temp->right=tree[0]->right;
  temp->isleaf=tree[0]->isleaf;
  //cout<<temp->freq<<endl;

  //overwrite min node with right most leaf on bottom layer
  tree[0]->freq = tree[lastIndex]->freq;
//cout<<"tree last index freq: "<<tree[lastIndex]->freq<<endl;
  //cout<<tree[size]->freq<<endl;
  tree[0]->stored = tree[lastIndex]->stored;
  tree[0]->left=tree[lastIndex]->left;
  tree[0]->right=tree[lastIndex]->right;
  tree[0]->isleaf=tree[lastIndex]->isleaf;
 /* if(tree[0]->isleaf==0){
    cout<<"isnotleaf"<< tree[0]->freq<<endl;

  }*/
  //cout<<"tree[0] freq: "<<tree[0]->freq;
  //lowest rightest node is virtually deleted outside of this function with lastIndex--
  //percolate top node down to satistfy tree
  
  percolateDown(tree, lastIndex+1);

  return temp;
}
void percolateDown(treeNode* tree[], int size){
int satisfied = 0;

  int j=0;
  while (satisfied==0){ 
      if(j>=size/2){
      satisfied=1;
      }
    if (j*2+2>=size){ // if current node's calculated right child >= size
      if(tree[j]->freq>tree[j*2+1]->freq){   //if current node's freq is larger than it's left child's
        
        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left=tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;


        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        tree[j]->left= tree[j*2+1]->left;
        tree[j]->right= tree[j*2+1]->right;
        tree[j]->isleaf=tree[j*2+1]->isleaf;
        
        tree[j*2+1]->freq=temp->freq;

        tree[j*2+1]->stored=temp->stored;
        tree[j*2+1]->left=temp->left;
        tree[j*2+1]->right=temp->right;
        tree[j*2+1]->isleaf=temp->isleaf;

      }
      satisfied=1;
    }
    else{
      if(((tree[j*2+1]->freq)<(tree[j]->freq))&&((tree[j*2+2]->freq<tree[j]->freq))){ // if both left and right children are less than parent
        if((tree[j*2+1]->freq)<(tree[j*2+2]->freq)) { // if left child is less than right, swap left with parent
        
        //temp node for swap
        treeNode* temp= new treeNode;
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left=tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;

        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        tree[j]->left= tree[j*2+1]->left;
        tree[j]->right= tree[j*2+1]->right;
        tree[j]->isleaf=tree[j*2+1]->isleaf;

        tree[j*2+1]->freq=temp->freq;
        tree[j*2+1]->stored=temp->stored;
        tree[j*2+1]->left=temp->left;
        tree[j*2+1]->right=temp->right;
        tree[j*2+1]->isleaf=temp->isleaf;

        j=j*2+1;

      }
      else{ // if right child is less than left, swap right with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left=tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;

        tree[j]->freq = tree[j*2+2]->freq;
        tree[j]->stored = tree[j*2+2]->stored;
        tree[j]->left= tree[j*2+2]->left;
        tree[j]->right= tree[j*2+2]->right;
        tree[j]->isleaf=tree[j*2+2]->isleaf;
        
        tree[j*2+2]->freq=temp->freq;
        tree[j*2+2]->stored=temp->stored;
        tree[j*2+2]->left=temp->left;
        tree[j*2+2]->right=temp->right;
        tree[j*2+2]->isleaf=temp->isleaf;

     j=j*2+2;
        
      }
    }
    else if((tree[j*2+1]->freq)<(tree[j]->freq) && (tree[j*2+2]->freq>=tree[j]->freq)) {   // if left<parent and right>=parent, swap left with parent

        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left=tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;

        tree[j]->freq = tree[j*2+1]->freq;
        tree[j]->stored = tree[j*2+1]->stored;
        tree[j]->left= tree[j*2+1]->left;
        tree[j]->right= tree[j*2+1]->right;
        tree[j]->isleaf=tree[j*2+1]->isleaf;
        
        tree[j*2+1]->freq=temp->freq;
        tree[j*2+1]->stored=temp->stored;
        tree[j*2+1]->left=temp->left;
        tree[j*2+1]->right=temp->right;
        tree[j*2+1]->isleaf=temp->isleaf;
      
        j=j*2+1;

    }
   else if((tree[j*2+1]->freq)>=(tree[j]->freq)&&(tree[j*2+2]->freq<tree[j]->freq)) // if left>=parent and right<parent, swap right with parent
      {


        //temp node for swap
        treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left=tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;

        tree[j]->freq = tree[j*2+2]->freq;
        tree[j]->stored = tree[j*2+2]->stored;
        tree[j]->left= tree[j*2+2]->left;
        tree[j]->right= tree[j*2+2]->right;
        tree[j]->isleaf=tree[j*2+2]->isleaf;
        



        tree[j*2+2]->freq=temp->freq;
        tree[j*2+2]->stored=temp->stored;
        tree[j*2+2]->left=temp->left;
        tree[j*2+2]->right=temp->right;
        tree[j*2+2]->isleaf=temp->isleaf;
//cout<<"if left>=parent and right<parent, swap right with parent. post swap: root: "<<tree[j]->freq<<"leaf: "<<tree[j*2+2]->freq<<" j= "<<j<<endl;
      j=j*2+2;

      }
    else{
      satisfied=1;
      }

    }
      if(j>=size/2){
      satisfied=1;
      }
    }

}

void insertnode(treeNode* insert[], treeNode* newNode, int lastIndex){
  
  insert[lastIndex]= newNode;
  //cout<<newNode->left->stored<< " "<< newNode->right->stored;
  //cout<<insert[lastIndex]->freq;
  percolateUp(insert,lastIndex);


}



void percolateUp(treeNode* tree[], int lastindex){
  
  int satisfied=0;

  int j=lastindex; 
while (satisfied==0){ 
    if(j==0){
      satisfied=1;
    }
    if(tree[j]->freq<tree[(j+1)/2-1]->freq){
       treeNode* temp = new treeNode();
        temp->freq = tree[j]->freq;
        temp->stored = tree[j]->stored;
        temp->left= tree[j]->left;
        temp->right=tree[j]->right;
        temp->isleaf=tree[j]->isleaf;

        tree[j]->freq = tree[(j+1)/2-1]->freq;
        tree[j]->stored = tree[(j+1)/2-1]->stored;
         tree[j]->left = tree[(j+1)/2-1]->left;
        tree[j]->right = tree[(j+1)/2-1]->right;
        tree[j]->isleaf = tree[(j+1)/2-1]->isleaf;
        //temp->left= tree[(j+1)/2-1]->left;
        //temp->right=tree[(j+1)/2-1]->right;
        //temp->isleaf=tree[(j+1)/2-1]->isleaf;        
        tree[(j+1)/2-1]->freq=temp->freq;
        tree[(j+1)/2-1]->stored=temp->stored;
        tree[(j+1)/2-1]->right=temp->right;
        tree[(j+1)/2-1]->left=temp->left;
        tree[(j+1)/2-1]->isleaf=temp->isleaf;

      j=(j+1)/2-1;

    }

else {
  satisfied=1; 
}
if(j==0){
      satisfied=1;
    }



  
}
}

treeNode* makeTrie(treeNode* minheap[], int size){
  int lastindex=size-1;

treeNode* first;
treeNode* second;



while(lastindex!=0)
{
   treeNode* trie=new treeNode();
trie->stored=NULL;

  trie->freq=0;

  first=deleteMin(minheap, lastindex);
//cout<<"first del freqs "<<minheap[0]->freq <<" "<<minheap[1]->freq <<" "<<minheap[2]->freq<<" "<<minheap[3]->freq <<" "<<minheap[4]->freq <<" "<<minheap[5]->freq <<endl;
  //cout<<first->stored;
  


  trie->right=first;
  //cout<<"last index: "<<lastindex<<endl;
  lastindex--;
  //cout<<"last index: "<<lastindex<<endl;
  second=deleteMin(minheap,lastindex);
 // cout<<"second del freqs "<<minheap[0]->freq <<" "<<minheap[1]->freq <<" "<<minheap[2]->freq<<" "<<minheap[3]->freq <<" "<<minheap[4]->freq <<" "<<minheap[5]->freq <<endl;
 // cout<<second->stored;
  trie->left=second;
  trie->isleaf=0;
  //cout<<"first freq "<<first->freq<<" second freq"<<second->freq<<endl;
  trie->freq=((trie->left->freq)+(trie->right->freq));
/* if(first->isleaf==1){
cout<<"first: "<<"stored: "<<first->stored<< " freq"<<first->freq<<endl;
  }

else{
cout<<"first: trie freq:"<<first->freq<<endl;
}*/

 /* if(second->isleaf==1){
cout<<"second: "<<"stored: "<<second->stored<< " freq"<<second->freq<<endl;
  }
  else{
cout<<"second: trie freq:"<<second->freq<<endl;
  }*/


//cout<<trie->freq;
  //cout<<trie->left->stored<<" "<<trie->right->stored;
  
  insertnode(minheap,trie,lastindex);
  
 // cout<<"lastindex: "<<lastindex<<endl;
   // cout<<"end freqs "<<minheap[0]->freq <<" "<<minheap[1]->freq <<" "<<minheap[2]->freq<<" "<<minheap[3]->freq <<" "<<minheap[4]->freq <<" "<<minheap[5]->freq <<endl;
  //cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
  //if(minheap[lastindex]->isleaf==0){
  //  cout<<"last index freq"<<minheap[lastindex]->freq;
  //}
 
  
 


}/*
first=deleteMin(minheap, lastindex);
second=deleteMin(minheap,lastindex);
treeNode* root= new treeNode;
root->right=first;
root->left=second;
root->freq=(first->freq)+(second->freq);
root->stored=NULL;
cout<<"root freq"<<root->freq;
*/
//cout<<"minheap freq"<<minheap[0]->freq;
return(*minheap);
}
