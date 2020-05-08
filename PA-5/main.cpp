// main function

#include <iostream>

#include "graph.h"

using namespace std;

int main(int argc, const char * argv[])
{
  if ( argc != 2 ) {
    cout << "usage: " << argv[0] << " input filename\n";
    exit(1);
  }

 string input_name = argv[1];
   // string input_name = "input-cycle.data";
  ifstream input(input_name);
  if (!input) {
    cout << "Wrong or nonexisting input file\n";
    exit(1);
  }
  
  Graph graph;
  graph.buildGraph(input);
  graph.displayGraph();
    
    
  graph.compute_indegree();
  //graph.printindegree();
  graph.topological_sort();
  graph.print_top_sort();
    cout<<endl;
  return 0;
}
