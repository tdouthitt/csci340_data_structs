/************************************************************

      PROGRAM:    Assign 8	
      PROGRAMMER: Andrew Bihner	
      LOGON ID:   Z156501
      DUE DATE:   November 17, 2010
	   
      FUNCTION:   This is the drive class for hashTable.
***********************************************************/

#include "/home/turing/onyuksel/courses/340/progs/10f/p8/Entry.h"
#include "/home/turing/onyuksel/courses/340/progs/10f/p8/hashTable.h"

int main()
{
   hashTable hTable;
   Entry newEntry;
   string tranType;
   string key; 
   string number;
   string description;
   string remainder;
	
	cout << "       *** Hashing with linear probe assignment *** \n" << endl;
	
	while (getline(cin, tranType, ':'))
   {
   // Insert transaction
   if (tranType == "A")
      {
         getline(cin, key, ':');
         getline(cin, number, ':');
         getline(cin, description, ':');
		
         newEntry.key = key;
         int sNumber = atoi(number.c_str());
         newEntry.number = sNumber;
         newEntry.descript = description;
		 
         hTable.insert(newEntry); 
      }
   // Search transaction
   else if (tranType == "S")
      {
         getline(cin, key, ':');
         hTable.search(key);
      }  
   // Print transaction
   else
      hTable.hTable_print();

   // Read the rest of the input line and ignore it
   getline(cin, remainder);
   }
   hTable.pTable_print();
   cout <<"         *** end of program termaination *** \n";
}