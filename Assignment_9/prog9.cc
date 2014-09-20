/************************************************************

      PROGRAM:    prog9.cc
      PROGRAMMER: Andrew Bihner	
      LOGON ID:   Z156501
      DUE DATE:   November 30, 2010
	   
      FUNCTION: This is the driver program for the weighted
	            digraph class and methods.
***********************************************************/
#include "/home/turing/onyuksel/courses/340/progs/10f/p9/wdigraph.h"

/*************************************************************
   FUNCTION: proc_graph()
	
   USE: used to call print_graph on an object
   
   ARGUEMENTS: 1. g - i wdigraph object
*************************************************************/
void proc_graph(wdigraph& g)
{
   cout << endl
        << "A Weighted Digraph" << endl
        << "________________"   << endl << endl;   
   
   g.print_graph();
   
   cout << endl << endl
        << "Paths by Depth-First Search:" << endl
        << "(Skip Every 2nd and 3rd Node to Print)\n\n";
   
   for (int vertex = 0; vertex < g.get_size(); vertex += 3)
   {
      g.depth_first(vertex);
   }

}

int main()
{
  wdigraph graph1(5);
  proc_graph(graph1);
  
  wdigraph graph2;
  proc_graph(graph2);
}

