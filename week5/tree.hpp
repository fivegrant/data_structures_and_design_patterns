#ifndef TREE
#define TREE

#include <vector>
#include <algorithm>
#include "queue.hpp"

template <class T>
class BinarySearchTree{
  public: 
        T value; 
        BinarySearchTree *left = nullptr;
        BinarySearchTree *right = nullptr;
        bool empty = true;


	BinarySearchTree(){}; // makes an empty one
	BinarySearchTree(T element): value(element), empty(false){} 
	//builds tree from sorted array of ints
	BinarySearchTree(const std::vector<T>& vals) {
	  for(auto element : vals){
	    insert(element);
	  }
	  if(vals.size() > 0){
	    empty = false;
	  }
	};

	int getHeight() const{
	  if(isEmpty()){
	    return 0;
	  }
	  else{
	    int left_height  = left  == nullptr ? 0 : left->getHeight(); 
	    int right_height = right == nullptr ? 0 : right->getHeight(); 
	    return std::max(left_height, right_height) + 1;
	  }
	};

	bool isEmpty() const{
	  return empty;
	};

	int getSize() const{
	  if(isEmpty()){
	    return 0;
	  }
	  else{
	    int left_height  = left  == nullptr ? 0 : left->getSize(); 
	    int right_height = right == nullptr ? 0 : right->getSize(); 
	    return left_height + right_height + 1;
  
	  }
	};

	bool isBalanced() const{
	  if(isEmpty()){
	    return true;
	  }
	  else{
	    bool left_balance  = left  == nullptr ? false : left->isBalanced(); 
	    bool right_balance = right == nullptr ? false : right->isBalanced(); 
	    return left_balance == right_balance;
	  }
	};

	std::vector<T> elementVector() const{
	  if(isEmpty()){
	    return {};
	  }
	  else{
	    std::vector<T> collection  = left  == nullptr ? std::vector<T>{} : left->elementVector();
	    collection.push_back(value);
	    std::vector<T> right_elements = right == nullptr ? std::vector<T>{} : right->elementVector();
	    collection.insert(collection.end(), right_elements.begin(), right_elements.end());
	    return collection;
	  }

	};

	void insert( const T& element){
	  if(isEmpty()){
	    value = element;
	    empty = false;
	  }
	  else if(value == element){
	    return;
	  }
	  else if(element < value){
	    if(left != nullptr){
	      left->insert(element);
	    }
	    else{
	      left = new BinarySearchTree(element);
	    }
	  }
	  else if(element > value){
	    if(right != nullptr){
	      right->insert(element);
	    }
	    else{
	      right = new BinarySearchTree(element);
	  }
	  }
	};

	bool contains( const T& find ) const{
	  if (find == value){
	    return true;
	  }
	  else if(find < value and left != nullptr){
	    return left->contains(find);
	  }
	  else if(find > value and left != nullptr){
	    return right->contains(find);
	  }
	  else{
	    return false;
	  }

	};

	T search( const T& find ) const{
	  if (find == value){
	    return value;
	  }
	  else if(find < value){
	    return left->search(find);
	  }
	  else if(find > value){
	    return right->search(find);
	  }
	    //potential for no return
	};


	std::vector<T> makeBreadthFirstVector() {
	  if(isEmpty()){
	    return {};
	  }
	  std::vector<T> content = {};
	  Queue<BinarySearchTree<T>*> queue = Queue<BinarySearchTree<T>*>();
	  queue.enqueue(this);
	  while(not queue.isEmpty()){
	    BinarySearchTree<T>* current = queue.dequeue();
	    if(current->left != nullptr){
	      queue.enqueue(current->left);
	    }
	    if(current->right != nullptr){
	      queue.enqueue(current->right);
	    }
	    content.push_back(current->value);
	  }
	  return content;
	};

};

#endif
