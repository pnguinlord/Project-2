#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
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
};

void heapify(treeNode* input[], int size)
{
  int satisfied,j;
  
  int i;
  for(i=size/2-1;i>=0;i--){ //verify that the minus one is correct
    cout<<"count:"<<i<<"\n";
      j=i;
      satisfied=0;
      while (satisfied==0){
        if(j>size/2){
          satisfied=1;
        }
        if (i*2+2>=size){
          if(input[j]->freq>input[j*2+1]->freq){
            
            //temp node for swap
            treeNode* temp = new treeNode();
            temp->freq = input[j]->freq;
            temp->stored = input[j]->stored;

            input[j]->freq = input[j*2+1]->freq;
            input[j]->stored = input[j*2+1]->stored;
            
            input[j*2+1]->freq=temp->freq;
            input[j*2+1]->stored=temp->stored;

/*
            treeNode temp=input[j];
            input[j]=input[j*2+1];
            input[j*2+1]=temp;
*/
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

/*
            treeNode temp=input[j];
            input[j]=input[j*2+1];
            input[j*2+1]=temp;
            j=j*2+1;
*/

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
            
            /*
            treeNode temp=input[j];
            input[j]=input[j*2+2];
            input[j*2+2]=temp;
            j=j*2+2;
            */
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


/*
          treeNode temp=input[j];
            input[j]=input[j*2+1];
            input[j*2+1]=temp;
            j=j*2+1;
  */
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

            /*
            treeNode temp=input[j];
            input[j]=input[j*2+2];
            input[j*2+2]=temp;
            j=j*2+2;
            */

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
    }


treeNode* deleteMin(treeNode* tree, int size){
  
  //temp is min node
  treeNode* temp = new treeNode();
  temp->freq = tree[0]->freq;
  temp->stored = tree[0]->stored;

  //overwrite min node with right most leaf on bottom layer
  tree[0]->freq = tree[size]->freq;
  tree[0]->stored = tree[size]->freq;

  //lowest rightest node is virtually deleted outside of this function with lastIndex--
  //percolate top node down to satistfy tree
  percolateDown(treeNode* tree, size-1);

  return temp;
}
void percolateDown(treeNode*tree, int size){

}

void insertnode(treeNode* insert[], treeNode*){

}
void percolateUp(treeNode*tree, int size){
  
}



int main()
{
  freopen("input.txt","r",stdin);     // if you use this line, it merely redirects stdin to input.txt file; simple as that
  int end=0;
  int freq[27]={0};
  
  int count=0;
  string str;  
  std::getline(std::cin,str);//takes in the string input
  for (int i=0; i<str.length();i++) //iterate through the string 
    {
      if(97<=str[i]&&str[i]<=122) //if the char is a-z
  {
  if (freq[str[i]-'a']==0){
    count++; // counts unique characters
    
    }
  freq[str[i]-'a']++;//increment respective index 
  
      }
      else if(str[i]==32)
  {
    if( freq[26]==0){
        count++;
        
    }
  freq[26]++; // if space detected, increment its index
  
      
      }
    }
  for(int i=0;i<27;i++){
    
    cout<<freq[i];
    } 
  
  treeNode* minheap[count];
  int j=0;
  
  for(int i=0;i<27;i++)
    {
    
    if (freq[i]!=0)
      {
  // cout<<freq[i];
        minheap[j]=new treeNode();
        minheap[j]->freq=freq[i];
        if (freq[i]!=32){
          minheap[j]->stored=char(i+'a');
      //cout<<minheap[j].stored;
      
      } 
        else {
          minheap[j]->stored=char(' ');
        }
      j++;
      }
    }
    
  heapify(minheap, count);


  return 0;
lastindex=count-1;
treeNode* first;
treeNode* second;
while(lastindex!=0)
{
  treeNode* trie=new treeNode();
  trie->freq=0;
  first=deletemin(minheap);

  trie->right=first
  lastindex--;
  second=deletemin(minheap);
  trie->left=second
  lastindex--;
  trie->freq=left->freq+right->freq;
  insertnode(minheap,trie);
  lastindex++;


}
treeNode* root= new treeNode();
root->right=first;
root->left=second;
root->freq=right->freq+left->freq;

}


