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

void heapify(treeNode input[])
{
  int size=ARRAY_SIZE(input);
  for(int i=size/2-1;i>=0;i--){ //verify that the minus one is correct
      int j=i;
      int satisfied=0;
      while (satisfied==0){
        if(j>size/2){
          satisfied=1;
        }
        if (i*2+2>=size){
          if(input[j].freq>input[j*2+1].freq){
            
            //temp node for swap
          	treeNode temp;
          	temp.freq = input[j].freq;
          	temp.stored = input[j].stored;

          	input[j].freq = input[j*2+1].freq;
          	input[j].stored = input[j*2+1].stored;
          	
          	input[j*2+1].freq=temp.freq;
          	input[j*2+1].stored=temp.stored;

/*
            treeNode temp=input[j];
            input[j]=input[j*2+1];
            input[j*2+1]=temp;
*/
          }
          satisfied=1;
        }
        else{
          if((input[j*2+1].freq)<(input[j].freq)&&(input[j*2+2].freq<input[j].freq)){ // if both left and right children are less than parent
          	if((input[j*2+1].freq)<(input[j*2+2].freq)) { // if left child is less than right, swap left with parent
            
            //temp node for swap
          	treeNode temp;
          	temp.freq = input[j].freq;
          	temp.stored = input[j].stored;

          	input[j].freq = input[j*2+1].freq;
          	input[j].stored = input[j*2+1].stored;
          	
          	input[j*2+1].freq=temp.freq;
          	input[j*2+1].stored=temp.stored;

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
          	treeNode temp;
          	temp.freq = input[j].freq;
          	temp.stored = input[j].stored;

          	input[j].freq = input[j*2+2].freq;
          	input[j].stored = input[j*2+2].stored;
          	
          	input[j*2+2].freq=temp.freq;
          	input[j*2+2].stored=temp.stored;

			j=j*2+2;
          	
          	/*
            treeNode temp=input[j];
            input[j]=input[j*2+2];
            input[j*2+2]=temp;
            j=j*2+2;
            */
          }
        }
        else if((input[j*2+1].freq)<(input[j].freq) && (input[j*2+2].freq>input[j].freq)) {   // if left<parent and right>parent, swap left with parent

            //temp node for swap
          	treeNode temp;
          	temp.freq = input[j].freq;
          	temp.stored = input[j].stored;

          	input[j].freq = input[j*2+1].freq;
          	input[j].stored = input[j*2+1].stored;
          	
          	input[j*2+1].freq=temp.freq;
          	input[j*2+1].stored=temp.stored;

            j=j*2+1;


/*
        	treeNode temp=input[j];
            input[j]=input[j*2+1];
            input[j*2+1]=temp;
            j=j*2+1;
  */
        }
       else if((input[j*2+1].freq)>(input[j].freq)&&(input[j*2+2].freq<input[j].freq)) // if left>parent and right<parent, swap right with parent
          {

            //temp node for swap
          	treeNode temp;
          	temp.freq = input[j].freq;
          	temp.stored = input[j].stored;

          	input[j].freq = input[j*2+2].freq;
          	input[j].stored = input[j*2+2].stored;
          	
          	input[j*2+2].freq=temp.freq;
          	input[j*2+2].stored=temp.stored;

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
        }
      }
    }



    /*  if((input[i*2+1].freq>input[i*2+2].freq)&&(input[i*2+1].freq<input[i].freq))
  {
    treeNode temp=input[i];
    input[i]=input[i*2+1];
    input[i*2+1]=temp;
  }
      else if((input[i*2+2].freq>input[i*2+1].freq)&&(input[i*2+2].freq<input[i].freq))
  {
    treeNode temp=input[i];
    input[i]=input[i*2+2];
    input[i*2+2]=temp;
  }
      else if((input[i*2+1].freq==input[i*2+2].freq)&&(input[i*2+1].freq<input[i].freq))
  {
    treeNode temp=input[i];
    input[i]=input[i*2+2];
    input[i*2+2]=temp;
  }
      
    
}
      
  
*/

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
  
  treeNode minheap[count];
  int j=0;
  
  for(int i=0;i<27;i++)
    {
    
    if (freq[i]!=0)
      {
  // cout<<freq[i];
    minheap[j].freq=freq[i];
    if (freq[i]!=32){
      minheap[j].stored=char(i+'a');
      //cout<<minheap[j].stored;
      
    }
    else {
      minheap[j].stored=char(' ');
    }
    j++;
      }
    }
    
  heapify(minheap);
  for(int i=0; i<ARRAY_SIZE(minheap);i++)
    {cout<<minheap[i].freq << " ";
     cout<<minheap[i].stored << "\n";
    }

  return 0;

}
