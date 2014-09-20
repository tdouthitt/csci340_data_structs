/************************************************************

      PROGRAM:    wdigraph2.cc
      PROGRAMMER: Andrew Bihner	
      LOGON ID:   Z156501
      DUE DATE:   November 30, 2010
	   
      FUNCTION:   This class has the depth first method of a 
	              graph an and a print method that will
				  print out the graph in its entirety
***********************************************************/
#include "/home/turing/onyuksel/courses/340/progs/10f/p9/wdigraph.h"

/*************************************************************
   FUNCTION: depth_first()
	
   USE: Will traverse throughout the graph and prints out
        the labels.
	
   ARGUEMENTS: 1. int which is the starting place in the graph
*************************************************************/
void wdigraph::depth_first(int v) const
{ 
      static int firstVertex = -1;
      static bool* visited = NULL;
   
      if (firstVertex == -1)
      {
         firstVertex = v;
         //allocate visited array of size elements
		 visited =  new bool(size);
         //set all elements of visited to false
		 for(int i = 0; i < size; i++)
		 {
            visited[i] = false;
		 }
      }

      cout << label[v];
      visited[v] = true;

      for(int w = 0; w != size; w++)
      {
         if (adj_matrix[v][w] != 0 && visited[w] != true)
         {
            //print an arrow
			cout << "->";

            //call depth_first() with w as the argument
            depth_first(w);
         }
      }
	  
      if (v == firstVertex)
      {
	     cout << endl << endl;
         firstVertex = -1;
         delete[] visited;
         visited = NULL;
      }
}


/*************************************************************
   FUNCTION: print_graph()
	
   USE: Prints out the entire 2d graph
   
   ARGUEMENTS: NONE
*************************************************************/
void wdigraph :: print_graph() const
{
   //Prints out the number of nodes
   cout << "No of Nodes = " << size << endl << endl;
   
   cout << "Adjacency Matrix:" << endl << endl;
   
   cout << "  |";
   for(int i = 0; i < (int) label.size(); i++)
      cout << "  " << label[i];   
   
   cout << endl <<"--|";
   for(int i = 0; i < (int) label.size(); i++)
      cout << "---";
   cout << endl;
   
   for(int i = 0; i < (int) label.size(); i++)
   {
      cout << label[i] << " |";
	  
	  for(int j = 0; j < (int) label.size(); j++)
	  {
	     if(adj_matrix[i][j] != 0)
		    cout << setw(3) << adj_matrix[i][j];
		 else
		    cout << setw(3) << "-";
	  }
	  if(i < (int) label.size() -1)
	     cout << endl << "  |" << endl; 
   }
   
}

