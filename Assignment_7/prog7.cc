/************************************************************

      PROGRAM:    Assign 7	
      PROGRAMMER: Andrew Bihner	
      LOGON ID:   Z156501
      DUE DATE:   November 3, 2010
	   
      FUNCTION:   Creates a heap using a vector and has 
                  multiple functions that will sort different
                  ways and print out the entire heap.
***********************************************************/


#include "/home/turing/onyuksel/courses/340/progs/10f/p7/prog7.h"

/*************************************************************
   FUNCTION: get_list()
	
   USE: Method will fill the set with numbers from 2 to n and 
	     delete all of the non prime numbers
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. const char* - the input file
               3. P general datatype for the less or greater
                  method.
*************************************************************/
template <class T, class P>
void get_list(vector<T> & heap, const char* file, P predicate)
{
   ifstream inFile;
	
   inFile.open(file, ios::binary);
   if (!inFile)
   {
      cerr << "Error - unable to open input file\n";
      exit(1);
   }
   T item;
   inFile >> item;
   
   while(inFile)
   {	   
      insert(heap, item, predicate);   
      inFile >> item;
   }
   inFile.close();
}

/*************************************************************
   FUNCTION: print_list()
	
   USE: prints out all of the items within the entire heap
        by calling remove.
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. int to hold the setw length
               3. int to hold the # of items to print per line
               4. P general datatype for the less or greater
                  method.
*************************************************************/
template<class T, class P>
void print_list(vector<T> & heap, const int iSize, const int lineLength, P predicate)
{
   int count = 0;
   while(heap.size() > 1)
   {
      T item;
      item = remove(heap, predicate);
      cout << setw(iSize) << item << " ";
      count++;
		
      if(count == lineLength)
      {
         cout << endl;
         count = 0;
      }
   }
   cout << endl << endl;
}

/*************************************************************
   FUNCTION: insert()
	
   USE: Will insert the item into the back of the vector, 
        and calls upheap to recreate the heap.
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. T - item to insert.
               3. P general datatype for the less or greater
                  method.
*************************************************************/
template <class T, class P>
void insert(vector<T> & heap, const T& item, P predicate)
{
   heap.push_back(item);
   upheap(heap, (int) heap.size() -1, predicate);
}

/*************************************************************
   FUNCTION: remove()
	
   USE: Will move the first item to the end of the vector, 
        pulls it out of the vector and calls downheap 
        to recreate the heap.
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. P general datatype for the less or greater
                  method.
*************************************************************/
template <class T, class P>
T remove(vector<T> & heap, P predicate)
{
   T temp = heap[1];
   swap(heap[1], heap[heap.size()-1]);
   heap.pop_back();
   downheap(heap, 1, predicate);
   
   return temp;	
}

/*************************************************************
   FUNCTION: upheap()
	
   USE: Method will create a heap
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. int - where to start the recreation
               3. P general datatype for the less or greater
                  method.
*************************************************************/
template <class T, class P>
void upheap(vector<T> & heap, int start, P predicate)
{
   while(start != 1 && predicate(heap[start], heap[start/2]))
   {
      swap(heap[start],heap[start/2]);
      start = start /2;
   }
}

/*************************************************************
   FUNCTION: downheap()
	
   USE: Method will create a heap
	
   ARGUEMENTS: 1. vector<T> & - vector data type to 
                  hold the heap
               2. int - where to start the recreation
               3. P general datatype for the less or greater
                  method.
*************************************************************/
template <class T, class P>
void downheap(vector<T> & heap, int start, P predicate)
{
   int child = 2 * start;

   while(child <= (int) heap.size() -1)
   {
      if(child < (int) heap.size() -1 && predicate(heap[child + 1], heap[child]))
      {
         child++;
      }
      
      if(predicate(heap[child],heap[start]))
      {
         swap(heap[start],heap[child]);
         start = child;
         child = 2 * start;
      }
      else 
         child = (int) heap.size();
    }
} // end of Functions.

int main()
{
    vector<int>    v1(1);   // heap of integers
    vector<float>  v2(1);   // heap of floating-pt nums
    vector<string> v3(1);   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 7 - Output ***\n\n";

    // sort and print first list

    cout << "first list - ascending order:\n\n";
    get_list(v1, D1, less<int>());
    print_list(v1, INT_SZ, INT_LN, less<int>());

    cout << "first list - descending order:\n\n";
    get_list(v1, D1, greater<int>());
    print_list(v1, INT_SZ, INT_LN, greater<int>());

    // sort and print second list

    cout << "second list - ascending order:\n\n";
    get_list(v2, D2, less<float>());
    print_list(v2, FLT_SZ, FLT_LN, less<float>());

    cout << "second list - descending order:\n\n";
    get_list(v2, D2, greater<float>());
    print_list(v2, FLT_SZ, FLT_LN, greater<float>());

    // sort and print third list

    cout << "third list - ascending order:\n\n";
    get_list(v3, D3, less<string>());
    print_list(v3, STR_SZ, STR_LN, less<string>());

    cout << "third list - descending order:\n\n";
    get_list(v3, D3, greater<string>());
    print_list(v3, STR_SZ, STR_LN, greater<string>());

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}