/************************************************************

           PROGRAM:     sub2.cc
	   PROGRAMMER:  Andrew Bihner
	   LOGON ID:    z156501
	   DUE DATE:    sept 13, 2010
	   
	   FUNCTION:    This is the Function part of program 2
			Which holds all of the code for the different
			fucntions for Vectors.
	   
***********************************************************/
#include "/home/turing/onyuksel/courses/340/common/340.h"
#include "prog2.h"

/**************************************************************
     FUNCTION: Vecs()
	 
	 USE: Fills both Vectors with random numbers

	 ARGUEMENTS: 1. vector<int>& v1 First vector
		     2. vector<int>& v2 Second vector
		     3. int s1   seed for RNG
		     4. int s2   seed for RNG
**************************************************************/
void Vecs(vector<int>& v1, vector<int>& v2, int s1, int s2)
{
   srand(s1);
   for(int i = 0; i < (int) v1.size(); i++)
   {
      v1[i] = (int) rand() % RND_NO_RANGE + 1;
   }
   srand(s2);
   for(int j = 0; j < (int) v2.size(); j++)
   { 
      v2[j] = (int) rand() % RND_NO_RANGE + 1;  
   }	  
}

/**************************************************************
     FUNCTION: selSort()
	 
     USE: Selection sort method for a vector array
	 
      ARGUEMENTS: vector<int>$ v
**************************************************************/
void selSort(vector<int>& v)
{
   int i, j, min;
   int temp;
 
   for (i = 0; i < ( (int) v.size() - 1); i++)
   {
      min = i;

      for (j = i+1; j < (int) v.size(); j++)
      {
         if(v[j] < v[min])
            min = j;
      }

      temp = v[min];
      v[min] = v[i];
      v[i] = temp;
   }

}

/**************************************************************
     FUNCTION: linSearch()
	 
     USE: A linear search for a vector
	 
    : ARGUEMENTS: 1. const vector<int>& v inputed vector
	         2. int x    item being searched for
		 3. int& cnt
**************************************************************/
int linSearch(const vector<int>& v, int x, int& cnt)
{
    int i;

   for (i = 0; i < (int) v.size(); i++)
   {       
      cnt++;
      if (x == v[i])
      {
         return i;
      }	  
   } 
         return -1;
}

/**************************************************************
     FUNCTION: binSearch()
	 
     USE: A binary search for a vector
	 
     ARGUEMENTS: 1. const vector<int>& v inputed vector
                 2. int x    item being searched for
		 3. int& cnt
**************************************************************/
int binSearch(const vector<int>& v, int x, int& cnt)
{
   int low = 0;
   int high = (int) v.size() - 1;
   int mid;

   while (low <= high)
      {
      mid = (low + high) / 2;
      cnt++;      

      if (x == v[mid])
	  {
             return mid;
	  }	  

      if (x < v[mid])
         high = mid - 1;
      else
         low = mid + 1;
      }

   return -1;

}

/**************************************************************
     FUNCTION: print_vec()
	 
     USE: Method to print out the entire Vector
	 
     ARGUEMENTS: const vector<int>& v inputed vector
**************************************************************/
void print_vec(const vector<int>& v)
{
   int j = 0;
   
   for(int i = 0; i < (int) v.size(); i++)
   {
      cout << setw(5) << right << v[i] << " ";
	  j++;
	  if(j == LINE_SIZE)
	  {
	     cout << endl;
		 j = 0;
	  }
   }
}
