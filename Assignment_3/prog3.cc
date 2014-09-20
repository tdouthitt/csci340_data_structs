/************************************************************

      PROGRAM:    Assign 3 	
	   PROGRAMMER: Andrew Bihner	
	   LOGON ID:   Z156501
	   DUE DATE:   September 23, 2010
	   
	   FUNCTION:   To clean up words inserted into the program
		   			and count the number of times a single word
						was entered in.
	   
***********************************************************/
#include "/home/turing/onyuksel/courses/340/common/340.h"

void get_words(map<string, int>&);
void clean_entry(const string&, string&);
void print_words(const map<string, int>&);


using namespace std;

int main()
{ 
   map<string, int> m;
	
	get_words(m);
	print_words(m);
	
	return 0;

}  // END MAIN  

/*************************************************************
   FUNCTION: get_words()
	
	USE: Obtains words from input calls the function 
	     clean_entry on a given word and inserts the new 
	     word into a map
	
	AR GUEMENTS: map<string, int>&
*************************************************************/
void get_words(map<string, int>& container)
{
   string originalWord;
   string cleanedWord;
	
   while(cin)
   {
      cin >> originalWord;
		
      clean_entry(originalWord, cleanedWord);
		
      if(cleanedWord.size() > 0)
      {
         container[cleanedWord]++;
      }
   }
	
}
/*************************************************************
    FUNCTION: print_words()
	 
	 USE: to print out the complete map each word and the 
	      amount of times it showed up throughout get_words
	 
	 ARGUEMENTS: const map<string, int>& -- map object
*************************************************************/
void print_words(const map<string, int>& container)
{
  
   int lineCount = 0;
   typedef map<string,int> mapType;
   mapType::const_iterator iter = container.begin(); // create a constant iterator
	
   while(iter != container.end())
   {
      cout << setw(15)<< left << iter->first << "\t" << setw(3) << iter->second << "\t";
      lineCount++;
      iter++;
		
      if(lineCount == 3) // 3 values per line  
      {
         cout << endl;
         lineCount = 0;
      }	 
   }
}

/*************************************************************
    FUNCTION: clean_entry()
	 
	 USE:  Takes out unnessary items within a given word leaving 
	       only letters and numbers
	 
	 ARGUEMENTS:  1.const string& original -- Word to be cleaned
	              2. string & clean -- Final product of the word
*************************************************************/	   
void clean_entry(const string& original, string& clean)
{
   int startPt = 0; // holds the starting point of the cleaned word in the original String
   int currentPos = 0; // holds the current position of where the loop is at in the String
   int sLength = 0; // holds the length of the new string
	
   // Finds the starting postion of the actual word
   while(startPt < (int) original.size())
   {
      if(isalnum(original[startPt]) )
         break;
      startPt++;
   }
	
   currentPos = startPt;

   // Finds the length of the cleaned word  	  
   while(currentPos < (int) original.size())
   {
      if(isalnum(original[currentPos]) )
      {   
         sLength++; // Increments length of word
	 currentPos++; // Increments subscript
      }
      else
         break; 
   }
   // breaks apart the original word to grab the clean word out.
   if(startPt < (int) original.size())
      clean = original.substr(startPt, sLength);
	
   // Sets all letters in the word to lowercase
   for(int i = 0; i < (int) clean.size(); i++)
   {
      clean[i] = tolower(clean[i]);
   }
}   
