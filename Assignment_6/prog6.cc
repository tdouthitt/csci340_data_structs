/************************************************************

       PROGRAM:    Assign 6
	   PROGRAMMER: Andrew Bihner	
	   LOGON ID:   Z156501
	   DUE DATE:   October 21, 2010
	   
	   FUNCTION:   Driver program to run and test the 
				   binSTree class.
	   
***********************************************************/
#include "/home/turing/onyuksel/courses/340/common/340.h"
#include "binSTree.h"
#include <limits>

template<class T>
void print_value(T&);

using namespace std;

int main()
{
   vector<int> vec;
   binSTree<int> bTree;
   int prime[] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
   
   int pathLen;
   int tPathLen = 0;
   int numSSearch= 0;
   int n;
   
   cout << "Number of nodes within the search tree: ";
   cin >> n;
	cout << endl;
	
   srand(1);
   for(int i = 0; i < n; i++)
   {
      int num = rand() % n;
	   vec.push_back(num);
	   bTree.insert(num);
   }
   
   cout << "The size of the tree is "   << bTree.size()   << endl
        << "The number of leaves are "  << bTree.leaves() << endl
        << "The height of the tree is " << bTree.height() << endl;

	for(int j = 0; j < n; j++)
	{
		if(bTree.search(vec[j], pathLen) == true)
		{
		   numSSearch++;
			tPathLen = pathLen;
		}
	}
   cout << "Number of Sucessful Searches: " << numSSearch << endl
        << "Total path lengths: " << tPathLen << endl;	
   
	bTree.inOrder(print_value);
	
	bool nPrime = false;
	
	for(int i = 0; i < n; i++)
	{	
	   for(int k = 0; k < 11; k++)
		{
		   if(vec[i] == prime[k])
			{
				nPrime = true;
				break;
			}
			else if(vec[i] % prime[k] != 0) 
			   nPrime = false;
		}
		
		if(nPrime == false)
			bTree.remove(vec[i]);
	}
	pathLen = 0, tPathLen = 0, numSSearch= 0;
	
	cout << "The size of the tree is "   << bTree.size()   << endl
        << "The number of leaves are "  << bTree.leaves() << endl
        << "The height of the tree is " << bTree.height() << endl << endl;
		  
	for(int j = 0; j < n; j++)
	{
		if(bTree.search(vec[j], pathLen) == true)
		{
		   numSSearch++;
			tPathLen = pathLen;
		}
	}
   cout << "Number of Sucessful Searches: " << numSSearch << endl
        << "Total path lengths: " << tPathLen << endl;	
   
	bTree.inOrder(print_value);
}

template<class T>
void print_value(T& value)
{
	static int count = 0;    

   static T lastValue = numeric_limits<T>::max();

   if (value < lastValue)
      count = 0;

   ++count;
   lastValue = value;

   if(count == 15)
  {
     cout << value << endl;
	  count = 0;
  }
   else
	cout << value << " ";
	
}