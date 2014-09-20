/************************************************************

      PROGRAM:    Assign 4 	
	   PROGRAMMER: Andrew Bihner	
	   LOGON ID:   Z156501
	   DUE DATE:   September 30, 2010
	   
	   FUNCTION:   Inserts all a range of numbers from 2 to 
						an upper bound set by the user and calculates
						to find all of the prime numbers within the 
						set. Finally it will print all of these out.
	   
***********************************************************/
#include "/home/turing/onyuksel/courses/340/common/340.h"

void sieve(set<int>&, int);
void print_primes(const set<int>&);


using namespace std;

int main()
{ 
   int upperBound;
	set<int> s;  // Creates a set object 
	
	cin >> upperBound;
	
	sieve(s, upperBound);
	print_primes(s);
	
	return 0;

}  // END MAIN  

/*************************************************************
   FUNCTION: sieve()
	
	USE: Method will fill the set with numbers from 2 to n and 
	     delete all of the non prime numbers
	
	ARGUEMENTS: 1. set<int>& s -- a set of ints 
					2. int n -- the upper bound of the ints in the set
*************************************************************/
void sieve(set<int>& s, int n)
{
   int upper = n;
   set<int>:: iterator it;
	
	for(int i = 2; i <= upper; i++)
	{
	   s.insert(i);
	}
	
	for(int current = 2; current < n; current++)
	{
	   if(current * current > n)
		{
		   break;
		}
		
	   for(it = s.begin(); it != s.end(); it++)
	   {
	      if(*it % current == 0 && *it != current)
		      s.erase(*it);
	   }
	   it = s.begin();
	}
	
}
/*************************************************************
    FUNCTION: print_primes()
	 
	 USE: Prints out what is left inside of the set, with 10 in
	 		a row.
	 
	 ARGUEMENTS: const set<int>& s -- const set object
*************************************************************/
void print_primes(const set<int>& s)
{
   int lineCount = 0;
	set<int>:: iterator it;
	it = s.begin();
	
	while(it != s.end())
	{
	   cout << *it << "  ";
		lineCount++;
		it++;
		
		if(lineCount == 10)
		{
		   cout << endl;
			lineCount = 0;
		}
	}
}

