#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <fstream>

using namespace std;

struct Vertex
{
  int label;
  int indegree = 0;
  int top_num = 0;
  Vertex(int l) : label(l) {}
  Vertex(int l, int ind) : label(l), indegree(ind) {}
};

class Graph
{
private:
  vector<Vertex> node_list;
  vector<list<int>*> adj_list;
public:
  Graph(){};
  ~Graph()
    {
        node_list.clear();
        for(int i = 0; i < adj_list.size(); i++)
        {
          delete adj_list.at(i);
        }
    };

  void buildGraph(ifstream &input);
  void displayGraph();
  
  void topological_sort();
  void compute_indegree();
  void print_top_sort();
  void printindegree();
};

#endif




