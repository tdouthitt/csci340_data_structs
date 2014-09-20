#include "/home/turing/onyuksel/courses/340/progs/10f/p7/prog7.h"


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
	   insert(heap, item, pred);   
	   inFile >> item;
	}
   inFile.close();
}

template<class T, class P>
void print_list(vector<T> & heap, const int, const int, P)
{
   while(heap.size() > 1)
   {
      T item;
      item = remove(heap, predicate);
      cout << item << " ";
   }
   cout << endl;
}

template <class T, class P>
void insert(vector<T> & heap, const T& item, P predicate)
{
   heap.push_back(item);
   upheap(heap, (int) heap.size() -1,predicate);
}

template <class T, class P>
T remove(vector<T> & heap, P predicate)
{
   int temp = heap[1];
   swap(heap[1], heap[heap.size()-1);
   heap.pop_back();
   downheap(heap, 1, predicate);
   
   return temp;	
}

template <class T, class P>
void upheap(vector<T> & heap, int start, P predicate)
{
   while(start != 1 && predicate(heap[start], heap[start/2]))
   {
      swap(heap[start],heap[start -1]);
      start = start /2
   }
}

template <class T, class P>
void downheap(vector<T> & heap, int start, P predicate)
{
   int child = 2 * start;

   while(child <= (int) heap.size() -1)
   {
      if(child < (int) heap.size() -1 && predicate(heap[child], heap[child +1]))
      {
         child++;
      }
      
      if(predicate(heap[start], heap[child]))
      {
         swap(heap[start],heap[child]);
         start = child;
         child = 2 * start;
      }
      else 
         child = (int) heap.size();
    }
}

template <class T>
void swap(vector<T> & heap, int first, int second)
{
   int temp;
   temp = heap[first];
   heap[first] = heap[second];
   heap[second] = heap[temp];
}

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