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

/*void heapify(treeNode minheap[]){
for(int i=0;i<ARRAY_SIZE(minheap);i++){
if((minheap[i*2+1].freq>minheap[i*2+2].freq)&&(minheap[i*2+1].freq<minheap[i].freq))
{
treeNode temp=minheap[i];
minheap[i]=minheap[i*2+1];
minheap[i*2+1]=temp;
}
else if((minheap[i*2+2].freq>minheap[i*2+1].freq)&&(minheap[i*2+2].freq<minheap[i].freq))
{
treeNode temp=minheap[i];
minheap[i]=minheap[i*2+2];
minheap[i*2+2]=temp;
}
else if((minheap[i*2+1].freq==minheap[i*2+2].freq)&&(minheap[i*2+1].freq<minheap[i].freq))
{
treeNode temp=minheap[i];
minheap[i]=minheap[i*2+2];
minheap[i*2+2]=temp;
}

}

}


*/

int main()
{
	freopen("input.txt", "r", stdin);     // if you use this line, it merely redirects stdin to input.txt file; simple as that
	int end = 0;
	int freq[27] = { 0 };

	int count = 0;
	string str;
	std::getline(std::cin, str);//takes in the string input
	for (int i = 0; i<str.length(); i++) //iterate through the string 
	{
		if (97 <= str[i] && str[i] <= 122) //if the char is a-z
		{
			if (freq[str[i] - 'a'] == 0){
				count++;

			}
			freq[str[i] - 'a']++;//increment respective index 

		}
		else if (str[i] == 32)
		{
			if (freq[26] == 0){
				count++;

			}
			freq[26]++; // if space detected, increment its index


		}
	}
	/*  for(int i=0;i<27;i++){

	cout<<freq[i];
	} */
	cout << count;
	treeNode minheap[count];
	int j = 0;

	for (int i = 0; i<27; i++)
	{

		if (freq[i] != 0)
		{
			// cout<<freq[i];
			minheap[j].freq = freq[i];
			if (freq[i] != 32){
				minheap[j].stored = char(freq[i] + 'a');

			}
			else {
				minheap[j].stored = ' ';
			}
			j++;
		}
	}

	// heapify(minheap);
	for (int i = 0; i<ARRAY_SIZE(minheap); i++)
	{//cout<<minheap[i].freq;
		//cout<<minheap[i].stored;
	}

	return 0;

}