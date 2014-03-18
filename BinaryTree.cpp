#include <iostream>
#include <queue>

//A simple node structure for the tree
struct Node {
  int value;
  Node* left;
  Node* right;
  bool visited;
};

//A simple binary tree
class BinaryTree {
public:
  //Constructs a root node filled with NULL values
  BinaryTree();
  //Eliminates the whole tree using the erase_tree function
  ~BinaryTree();
  //Inserts a node traversing in dfs mode.
  void insert(int value);
  //Performs Depth First Search. Checks if given value is in tree
  bool dfs(int value);
  //Performs Breadth First Search. Checks if given value is in tree
  bool bfs(int value);
  //Prints tree node values while traversing it in BFS mode
  void show();
private:
  //Deletes nodes of the tree from the bottom up traversing in DFS mode
  void erase_tree(Node* tree);
  void insert(int value, Node*& tree);
  void dfs(int value, Node* tree);
  bool bfs(int value, Node* tree);
  bool value_found;
  Node* root;
};

BinaryTree::BinaryTree(){
  root = new Node;
  root->value = NULL;
  root->left = NULL;
  root->left = NULL;
  root->visited = false;
  
}

BinaryTree::~BinaryTree(){
  erase_tree(root);
}


void BinaryTree::insert(int value, Node*& tree){


  if (tree == NULL){ 
    tree = new Node;          
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    tree->visited = false;

    return;

  }

  if(value < tree->value){ 
    insert(value,tree->left);
  }else if (value > tree->value){
    insert(value,tree->right);
  }
  

}

void BinaryTree::insert(int value){

  if(root->value == NULL){ 
    root->value = value;
  }else{ 
    insert(value,root);
  }
  return;
}

//DFS starting from the left
void BinaryTree::dfs(int value, Node* tree){
  static bool found;

  if (value_found == true) {
    return;
  }

  if(tree == NULL){
    return;
  }

  if(tree->visited == true){
    return;
  }

  if(value == tree->value){
    value_found = true;
    return;
  }else{
    dfs(value,tree->left);
    dfs(value,tree->right);
  }

  return;
}

bool BinaryTree::dfs(int value){
  value_found = false;

  if(root->value == value){
    value_found = true;
    return value_found;
  }
  dfs(value, root);
  return value_found;
}

bool BinaryTree::bfs(int value, Node* tree){
  Node* leaf;
  std::queue<Node *> queue;
  queue.push(tree);           
  
  while(!queue.empty()){         

    leaf = queue.front();         //visit node
    queue.pop();
    if(value == leaf->value){    //found => true
      return true;
    }
                                //push same level nodes
    if(leaf->left != NULL){      
      queue.push(leaf->left);
    }

    if(leaf->right != NULL){
      queue.push(leaf->right);
    }
    
    
  }
  return false;
}

void BinaryTree::show(){
  Node* leaf;
  std::queue<Node*> queue;
  queue.push(root);

  while(!queue.empty()){

    leaf = queue.front();
    std::cout << leaf->value << " ";  //print node
    queue.pop();

    
    if(leaf->left != NULL){     //traverse in bfs style
      queue.push(leaf->left);
    }

    if(leaf->right != NULL){
      queue.push(leaf->right);
    }

  }
  std::cout << std::endl;
  return;
}

bool BinaryTree::bfs(int value){
  if(root->value == value){         //base case
    return true;
  }
  
  bfs(value, root);
}

void BinaryTree::erase_tree(Node* tree){
  if(tree->value == NULL){
    return;
  }
  if(tree->left != NULL){
    erase_tree(tree->left);
  }
  if(tree->right != NULL){
    erase_tree(tree->right);
  }

  delete tree;   //erase from the bottom up
  return;
}


int main(){  //Testing the Class
  BinaryTree A;
  A.insert(5);
  A.insert(3);
  A.insert(4);
  A.insert(8);
  A.insert(9);
  A.show();
  std::cout << std::endl;
  if(A.dfs(10) == true){
    std::cout << "Found" << std::endl;
  }else{
    std::cout << "Not Found" << std::endl;
  }

  return 0;
}
