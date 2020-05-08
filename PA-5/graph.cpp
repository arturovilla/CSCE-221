#include "graph.h"
#include <iostream>

using namespace std;
// to be implemented
void Graph::buildGraph(ifstream &input)
{
    string line;
    int count = 0;
    while(!input.fail())
    {
        int x;
        input>>x;
        this->node_list.push_back(Vertex(x));
         list<int>* y= new list<int>();
        this->adj_list.push_back(y);
        while(x!=(-1))
        {
            input>>x;
            if(x!=(-1))
            {
                this->adj_list.at(count)->push_back(x);
            }
        }
        count++;
    }
}


// // // // // // // // // // // // // // // // // // /// // // // // // // 
void Graph::displayGraph()
{
    for(int i = 0; i < this->node_list.size()-1;i++)
    {
        cout<<node_list.at(i).label<<" : ";
        
        for(auto ptr = this->adj_list.at(i)->begin(); ptr != this->adj_list.at(i)->end(); ptr++)
        {
            cout<<*ptr<<" ";
        }
        cout<<endl;
    }
}

// // // // // // // // // // // // // // // // // // // // // //
void Graph::compute_indegree()
{
    for(int i = 0; i<this->node_list.size()-1;i++)
    {
        for(auto ptr = this->adj_list.at(i)->begin(); ptr != this->adj_list.at(i)->end(); ptr++)
        {
            node_list.at(*ptr-1).indegree++;
        }
    }
    
}
// // // // // // // // // // // // // // // // // /// // // // //

void Graph::printindegree()//testing purposes
{
    for(int i = 0; i<this->node_list.size()-1;i++)
    {
        cout<<" vertex : "<<node_list.at(i).label<<" indegree : "<<node_list.at(i).indegree<<endl;
    }
}

// // // // // // // // // // // // // // // / // //
void Graph::topological_sort()
{
    vector<Vertex> temp = node_list;
    list<Vertex*> q;
    int counter = 0;
    q.clear();
    for(int i =0; i <node_list.size()-1;i++)
    {
        if(node_list.at(i).indegree == 0)
        {
            q.push_back(&node_list.at(i));
        }
    }
    
    while(!q.empty())
    {
        Vertex* v = q.front();
        q.pop_front();
        v->top_num = ++counter;
        
        for(auto ptr = this->adj_list.at(v->label-1)->begin(); ptr != this->adj_list.at(v->label-1)->end(); ptr++)
        {
            if(--(node_list.at( (*ptr)-1).indegree) == 0)
            {
                q.push_back(&node_list.at( (*ptr)-1));
            }
        }

    }
    
    for(int i = 0; i < temp.size()-1; i++)
    {
      node_list.at(i).indegree = temp.at(i).indegree;
    }
    
    try
    {
        if(counter != node_list.size()-1)
        {
            throw 20;
        }
    }
    catch(int v)
    {
        cout<<"Cycle found!"<<endl;
    }

}
 
// // // // // // // // // // // // // // // / // //
 
void Graph::print_top_sort()
{
    int count = 0;
    while(count!=node_list.size())
    {
        for(int i =0; i<node_list.size()-1;i++)
        {
            if(node_list.at(i).top_num == count)
            {
                cout<<node_list.at(i).label<<" ";
            }
        }
        count++;
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // //
