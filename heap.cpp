#include <iostream>
#include <exception>
#include <string>
#include <cstdio>

using namespace std;

#include "heap.h"



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