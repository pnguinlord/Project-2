#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "heap.h"
#include "encode.h"

using namespace std;

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
}




