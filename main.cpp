#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "heap.h"
#include "encode.h"
#include <fstream> 
using namespace std;

int main()
{
  //freopen("input.txt","r",stdin);     // if you use this line, it merely redirects stdin to input.txt file; simple as that
  int end=0;
  int freq[27]={0};
  
  int count=0;
  string str,str2;  
  ifstream input;
  input.open("input.txt");
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
 // cout<<"count: "<<count<<endl;
  /*for(int i=0;i<27;i++){
    
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
    

    for(int i=0;i<count;i++)
  {
    cout<<minheap[i]->stored<<" "<< minheap[i]->freq<<endl;
  }
  heapify(minheap, count); //order the heap based on freq
   for(int i=0;i<count;i++)
  {
    cout<<minheap[i]->stored<<" "<< minheap[i]->freq;
  }
  treeNode* root=makeTrie(minheap,count);



//freopen("encoded.txt","r",stdin);
  ifstream encoded;
  encoded.open("encoded.txt");
std::getline(encoded,str2);//takes in the string input
//string output="";
treeNode* iterator=root;
for (int i=0; i<str2.length();i++) //iterate through the string 
{ //cout<<str2[i];
  if(str2[i]==0){
    iterator=iterator->right;
  }
  else if(str2[i]==1){
    iterator=iterator->left;
  }
  /*if((iterator->left==NULL)&&(iterator->right==NULL)){ 
    cout<<iterator->stored;
    iterator=root;
  }*/

    if(iterator->stored){
      cout<<iterator->stored;
    }
}

input.close();
encoded.close();
  return 0;
}




