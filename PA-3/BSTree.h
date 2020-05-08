#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_time; //see the problem description

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_time(0) {}
};

class BSTree
{
public:
  // constructors
  BSTree() : size(0), root(nullptr) {}
  BSTree(const BSTree& other);
  // move constructor
  BSTree(BSTree&& other);
  // copy assignment
  BSTree& operator=(const BSTree& other);
  // move assignment
  BSTree operator=(BSTree&& other);
  ~BSTree();

  const Node* get_root() const { return root; }
  const int get_size() const { return size; }
  void insert(int obj);
  Node* search(int obj);
  void update_search_times();
  float get_average_search_time();
  ostream& inorder(ostream& out);
  ostream& print_level_by_level(ostream& out);
    int get_total_search_time(Node* node);
    void pretty_print_node(ostream& out,Node* node);
    int getsize();

private:
  int size;
  Node* root;
//
    void copy_helper(Node* copy_to, const Node* copy_from) const;
    void insert2(int data, Node* root);
    void destroy_tree2(Node* node);
    Node* search2(int obj,Node* root);
    int depthfndr(Node* root);
    void ust2(Node* root);
    void inorder2(Node* root,ostream& out);

    
};

// print a BSTree
ostream& operator<<(ostream& out, BSTree& tree);

// print a node
ostream& operator<<(ostream& out, Node node);

// read in a tree from a file
istream& operator>>(istream& in, BSTree& tree);


#endif
