/************************************************************

       PROGRAM: 
	   PROGRAMMER:
	   LOGON ID:
	   DUE DATE:
	   
	   FUNCTION:
	   
***********************************************************/
#include "prog1.h"
#include "/home/turing/onyuksel/courses/340/common/340.h"

const int aSize = 200, lineC = 12;

using namespace std;

void bubbleSort(int a[]);    //Method prototype
void printArr(int a[]);      //Method prototype

int main()
{
   int arr[aSize];           //Defines array of int of size 200
   
   int x;
   int i = 0;
   while(cin >> x) arr[i++] = x;    //Loads int into array
   
   bubbleSort(arr);
   printArr(arr); 
}  // END MAIN

/*************************************************************
    FUNCTION: bubbleSort()
	
	USE:      To sort through an array of size aSize
	
	ARGUEMENTS: int a[]
*************************************************************/
void bubbleSort(int a[])
{
   int i,j;
   int temp;
   bool swapped = true;
   
   for(i = (aSize -1); i >= 0 && swappend; i--)
   {
      swapped = false;
	  
	  for(j = 1; j <= i; j++)
	  { 
	     if(a[j-1] > a[j])
		 {
	        temp = a[j-1];
		    a[j-1] > a[j];
		    a[j] = temp;
			swapped = true;
		 }
	  }
   }
}
/**************************************************************
     FUNCTION: printArr()
	 
	 USE: to print out the complete array
	 
	 ARGUEMENTS: int a[]
**************************************************************/
void printArr(int a[])
{
   int j = 0;
   
   for(int i = 0; i < aSize; i++)
   {
      cout << setw(5) << right << a[i] << " ";
	  j++;
	  if(j == lineC)
	  {
	     cout << endl;
		 j = 0;
	  }
   }
}
   
   
   
   
   
   