#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "heap.h"
#include "encode.h"
#include <fstream> 
using namespace std;


/*void printTree(treeNode* node, string a){
treeNode*start=node; 
if (node->isleaf==0){
  string b=a.append("0");
  string c=a.append("1");
  printTree(node->right,b);
  printTree(node->left,c);
}
if(node->isleaf==1){
  cout<<"code: "<< a<< " stored: "<<node->stored<<endl;
}
}
*/
void printCode(treeNode*node, string code,char comp){
  treeNode*start=node;
  if (node->isleaf==0){
    string b=code.append("0");
    string c= code.append("1");
    printCode(node->right, b, comp);
    printCode(node->left,c,comp);

  }
  else if(node->isleaf==1){
    if (comp==node->stored){
    cout<<code;
  }
  }
  return;
}

int main()
{ int end=0;
  int freq[27]={0};
  int count=0;
  string str,str2;  
  ifstream input;
  input.open("plain.input");
  std::getline(input,str);//takes in the string input
  for (int i=0; i<str.length();i++) //iterate through the string 
    {//cout<<str[i]<<endl;
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
  /*cout<<"count: "<<count<<endl;
  for(int i=0;i<27;i++){
    
    cout<<freq[i]<<endl;
    } 
  */
  treeNode* minheap[count]; //make minheap size count
  int j=0;
  
  for(int i=0;i<27;i++)
    {
    
    if (freq[i]!=0)
      {
    
        minheap[j]=new treeNode();
        minheap[j]->isleaf=1;
        minheap[j]->freq=freq[i];
        if (i!=26){
          //cout<<char(i+'a');
          minheap[j]->stored=char(i+'a');
      //cout<<minheap[j]->stored<<" "<<minheap[j]->freq<<endl;      
      } 
        else if(i==26){
          minheap[j]->stored=char(' ');
        }
      j++;
      }
    }
    

  /*  for(int i=0;i<count;i++)
  {
    cout<<minheap[i]->stored<<" "<< minheap[i]->freq<<endl;
  }*/
  heapify(minheap, count); //order the heap based on freq
  /* for(int i=0;i<count;i++)
  {
    cout<<minheap[i]->stored<<" "<< minheap[i]->freq<<endl;
  }
*/

  
  treeNode* root=makeTrie(minheap, count);
 //cout<<root->right->left->left->left->isleaf;
  //string print="";
//printTree(root,print);
  for (int i=0; i<str.length();i++)
{

  string code="";
  printCode(root, code,str[i]);



}


//cout<<root->right->right->right->right->right->stored;
//freopen("encoded.txt","r",stdin);
  ifstream encoded;
  encoded.open("encoded.input");
std::getline(encoded,str2);//takes in the string input
//string output="";
treeNode* iterator=root;
//cout<<str2.length();
for (int i=0; i<str2.length();i++) //iterate through the string 
{ //cout<<str2[i];

  if(str2[i]=='0'){
    iterator=iterator->right;
    //cout<<"RIGHT";
  }
  else if(str2[i]=='1'){
    iterator=iterator->left;
    //cout<<"LEFT";
  }
  if(iterator->isleaf==1){ 

    cout<<iterator->stored;
    iterator=root;
  }

    
}
cout<<endl;

input.close();
encoded.close();
  return 0;
}




