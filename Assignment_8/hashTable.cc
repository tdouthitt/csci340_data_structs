/************************************************************

      PROGRAM:    hashTable
      PROGRAMMER: Andrew Bihner	
      LOGON ID:   Z156501
      DUE DATE:   November 17, 2010
	   
      FUNCTION: This is the table part of the hash function
                it will insert, search, and print the 
                different items within the arrays.
***********************************************************/


#include "/home/turing/onyuksel/courses/340/progs/10f/p8/Entry.h"
#include "/home/turing/onyuksel/courses/340/progs/10f/p8/hashTable.h"

/*************************************************************
   FUNCTION: hashTable()
	
   USE: Constructor method to create a new hash Table
	
   ARGUEMENTS: 1. int newSize - declares the size of the table
*************************************************************/
hashTable::hashTable(int newSize)
{
   size = newSize;
   psize = 0;
   hTable = new Entry [size];
   if(hTable == NULL)
   {
      cout << "Table is NULL";
      exit(1);
   }
   pTable = new Entry* [size];
   if(pTable == NULL)
   {
      cout << "Table is NULL";
      exit(1);
   }
   for(int i = 0; i < size; i++)
   {
      hTable[i].key = FREE;
   }
	
}

/*************************************************************
   FUNCTION: ~hashTable()
	
   USE: destroys the two different arrays.
   
   ARGUEMENTS: NONE
*************************************************************/
hashTable :: ~hashTable()
{
   delete [] hTable;
   delete [] pTable;
}

/*************************************************************
   FUNCTION: insert()
	
   USE: this method will insert the Entry object into the correct
        spot within the hash table based on the key
	
   ARGUEMENTS: 1. const Entry& newEntry - reference to the
                  entry to be added to the hash table
*************************************************************/
void hashTable :: insert(const Entry& newEntry)
{
   int ihash = hash(newEntry.key);
   int sub = ihash;
   cout << "insert: :" << newEntry.key << ":" << setw(4) 
        << right << newEntry.number << ":" << setw(24) << left 
        << newEntry.descript << ": ";
   
   while (true)
   {
      // Check for an empty hash table slot
      if (hTable[sub].key == FREE)
      {
         //copy newEntry into hTable[subscript]
         hTable[sub] = newEntry;
         //set pTable[psize] to the address of hTable[subscript]
         pTable[psize] = &hTable[sub];
         //increment psize
         psize++;
         //print the rest of the successful insert message
         cout << "entry = " << setw(2) << sub << endl;
         break;
      }
	  
      // Check for a duplicate key
      if (hTable[sub].key == newEntry.key)
      {
         cout << "not inserted - duplicate key!!!" << endl;
         break;
      }

      // Increment subscript
      sub = (sub + 1) % size;

      // Check if the table is full
      if (sub == ihash)
      {
         cout << "not inserted = table full!!!" << endl;
         break;
      }
   }
}
/*************************************************************
   FUNCTION: search()
	
   USE: Will move the first item to the end of the vector, 
        pulls it out of the vector and calls downheap 
        to recreate the heap.
	
   ARGUEMENTS: 1. const string& searchKey
*************************************************************/
void hashTable::search(const string& searchKey)
{
   int hashValue = hash(searchKey);
   int sub = hashValue;
 
   while (true)
   {
      // Check for a matching key
      if (hTable[sub].key == searchKey)
      {
         //print the other fields of hTable[subscript]
         cout << "search:  " << "Key " << hTable[sub].key << " ==> number: " 
              << setw(4) << right << hTable[sub].number << " - item: " 
              << hTable[sub].descript << endl;
         break;
      } 


      // Increment subscript
      sub = (sub + 1) % size;

      // Check if the table is full
      if (sub == hashValue)
      {
         cout << "Key " << searchKey << " not in table!!" << endl; 
         break;
      }
   }
}

/*************************************************************
   FUNCTION: hTable_print()
	
   USE: Method will print out all of the data within the hTable
	
   ARGUEMENTS: NONE
*************************************************************/
void hashTable :: hTable_print()
{
   bool lastEmpty = false;
   cout << "\nhTable_print:\n";
   cout << "entry  key    number    description" << endl;
   for(int i = 0; i < size; i++)
   {
      if(hTable[i].key != FREE)
	  {
	     if(lastEmpty)
		    cout << endl;
			
         cout << setw(4) << i <<":  "
              << hTable[i].key << "  - "
              << setw(5) << hTable[i].number << "  -  "
              << hTable[i].descript << endl;

         lastEmpty = false;				 
      }
      else 
         lastEmpty = true;
   }
   cout << endl;
} 

/*************************************************************
   FUNCTION: pTable_print()
	
   USE: Method will print out all of the data within the pTable
	
   ARGUEMENTS: NONE
*************************************************************/
void hashTable :: pTable_print()
{
   sort();
   cout << "sort_print" << endl;
   cout << "   sorted hash table:" << endl
        << "   Key    number    description" << endl;

   for(int i = 0; i < psize; i++)
   {
       cout << "   " << pTable[i]->key
            << "  -  " << right << setw(4) <<pTable[i]->number
            << "  -  " << left << pTable[i]->descript << endl;

   }
   cout << endl;
} 

/*************************************************************
   FUNCTION: sort()
	
   USE:Uses an insertion sort to sort out the entire hash table
   
   ARGUEMENTS: NONE
*************************************************************/
void hashTable :: sort()
{
   int i, j;
   Entry* bucket;
	
   for (i = 1; i < psize; i++)
   {
      bucket = pTable[i];

      for (j = i; (j > 0) && (pTable[j-1]->key > bucket->key); j--)
         pTable[j] = pTable[j-1];
		 
      pTable[j] = bucket;
   }
}

