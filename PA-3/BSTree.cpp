
#include "BSTree.h"


// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
ostream& operator<<(ostream& out, Node node)
{
  return out << "( " << node.value << ", "
	     << node.search_time << " )";
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
istream& operator>>(istream& in, BSTree& tree)
{
  int next;
  while(in >> next) 
    tree.insert(next);
  return in;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree& other)
{
    this->root = new Node;
    this->root->value = other.root->value;
    if(other.root == this->root)
    {
        cout<<"cannot make tree from same tree"<<endl;
        exit(0);
    }
    copy_helper(this->root, other.root);
    this->size = other.size;
}
//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  
    this->root = new Node;
    this->root->value = other.root->value;
    if(other.root == this->root)
    {
        cout<<"cannot make tree from same tree"<<endl;
        exit(0);
    }
    copy_helper(this->root, other.root);
    this->size=other.size;
    return *this;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    
// move constructor
BSTree::BSTree(BSTree&& other)
{
    if(other.root==this->root)
    {
        cout<<"cannot make tree from same tree"<<endl;
        exit(0);
    }
      this->root = other.root;
    this->size = other.size;
       other.root = nullptr;
}

// move assignment
BSTree BSTree::operator=(BSTree&& other)
{
    this->root = other.root;
    this->size= other.size;
    other.root = nullptr;
    return *this;

}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// destructor
BSTree::~BSTree()
{
    destroy_tree2( this->root);
    this->size=0;
}
void BSTree::destroy_tree2(Node* node)
{
 if(node != nullptr)
 {
     
   destroy_tree2(node->left);
   destroy_tree2(node->right);
     delete node;
   
 }
    
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// recursive
void BSTree::copy_helper(Node* copy_to,const Node* copy_from) const
{
  if(copy_from == nullptr)
    return;

  if(copy_from->left != nullptr)
    {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  }
  else
    {
    copy_to->left = nullptr;
  }

  if(copy_from->right != nullptr)
    {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  }
  else
    {
    copy_to->right = nullptr;
  }
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
//
//insert recursive function
void BSTree::insert2(int val,  Node* root)
{
    if(root == nullptr)
        {
            Node* root = new Node;
            this->root = root;
            root->value = val;
            root->left = nullptr;
            root->right = nullptr;
        }
        else if(val<root->value)
        {
            if(root->left!=nullptr)
            {
                insert2(val, root->left);
            }
            else
            {
                Node* n = new Node;
                root->left = n;
                n->value = val;
                n->left= nullptr;
                n->right = nullptr;
                
            }
        }
            else if(val>root->value)
        {
            if(root->right!=nullptr)
            {
                insert2(val, root->right);
            }
            else
            {
                Node* n = new Node;
                root->right = n;
                n->value = val;
                n->left= nullptr;
                n->right = nullptr;
                
            }
        }
}
void BSTree::insert(int obj)
{
    insert2(obj, root);
    this->update_search_times();
    this->size++;
}
//
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    
Node* BSTree::search(int obj)
{
    return search2(obj,this->root);
    
}
//
Node* BSTree::search2(int obj,Node* root)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(root->value==obj)
       {
           return root;
       }
    if(obj>root->value)
    {
        return search2(obj,root->right);
        
    }
    else
    {
        return search2(obj,root->left);
    }
    
    
}
//
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
void BSTree::update_search_times()
    {
        ust2(this->root);
    }
void BSTree::ust2(Node* root)
    {
        if(root!=nullptr)
        {
            root->search_time = 1 + (depthfndr(this->root) - depthfndr(root));
            ust2(root->left);
            ust2(root->right);
        }
        return;
    }
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

ostream& BSTree::inorder(ostream& out)
{
    inorder2(this->root,out);
    return out;
}
void BSTree::inorder2(Node* root,ostream& out)
    {
        if (root != NULL)
        {
            inorder2(root->left,out);
            out <<root->value<<"["<<root->search_time<<"]"<<" ";
            inorder2(root->right,out);
        }
    }
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// implemented
void BSTree::pretty_print_node(ostream& out,Node* node)
{
  out << node->value << "["<<node->search_time<<"] ";
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// implemented
ostream& BSTree::print_level_by_level(ostream& out)
{
  if(root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node*> current_level;
  vector<Node*> next_level;
  current_level.push_back(root);
  while(hasNodes) {
    hasNodes = false;
    for(auto node : current_level) {
      if(node != nullptr) {
	pretty_print_node(out, node);
	if(node->left != nullptr)
	  hasNodes = true;
	if(node->right != nullptr)
	  hasNodes = true;
	
	next_level.push_back(node->left);
	next_level.push_back(node->right);
      } else {
	out << "X ";
	next_level.push_back(nullptr);
	next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// implemented
int BSTree::get_total_search_time(Node* node)
{
  if(node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
    get_total_search_time(node->right) + node->search_time;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}
// // // // // // // // // // // // // // // //// // // // // // // // // // // // // // // //

//depth
int BSTree::depthfndr(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int left = depthfndr(root->left);
    int right = depthfndr(root->right);
           
    return max(left,right)+1;
    
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

//size
int BSTree::getsize()
{
    return this->size;
}
