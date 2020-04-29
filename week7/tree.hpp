#ifndef TREE
#define TREE

#include <vector>
#include <string>
#include <algorithm>

class HuffmanTree{
  private: 
    char value; 
    Huffman *left = nullptr;
    HuffmanTree *right = nullptr;
    bool empty = true;

  public: 
	HuffmanTree(){} // makes an empty one
	HuffmanTree(std::string element): value(element), empty(false){} 
	//builds tree from sorted array of ints
	HuffmanTree( const std::vector<char>& vals) {
	  for(auto element : vals){
	    insert(element);
	  }
	  if(vals.size() > 0){
	    empty = false;
	  }
	}

	int getHeight() const{
	  if(isEmpty()){
	    return 0;
	  }
	  else{
	    int left_height  = left  == nullptr ? 0 : left->getHeight(); 
	    int right_height = right == nullptr ? 0 : right->getHeight(); 
	    return std::max(left_height, right_height) + 1;
	  }
	}

	bool isEmpty() const{
	  return empty;
	}

	int getSize() const{
	  if(isEmpty()){
	    return 0;
	  }
	  else{
	    int left_height  = left  == nullptr ? 0 : left->getSize(); 
	    int right_height = right == nullptr ? 0 : right->getSize(); 
	    return left_height + right_height + 1;
  
	  }
	}

	bool isBalanced() const{
	  if(isEmpty()){
	    return true;
	  }
	  else{
	    bool left_balance  = left  == nullptr ? false : left->isBalanced(); 
	    bool right_balance = right == nullptr ? false : right->isBalanced();
	    return left_balance == right_balance;
	  }
	}


	void insert( const char& element){
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
	      left = new HuffmanTree(element);
	    }
	  }
	  else if(element > value){
	    if(right != nullptr){
	      right->insert(element);
	    }
	    else{
	      right = new HuffmanTree(element);
	  }
	  }
	}

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

	}

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
	}


	std::vector<T> makeBreadthFirstVector() const{
	  if(isEmpty()){
	    return {};
	  }
	  else{
	    std::vector<T> collection = {value};
	    if(left != nullptr){
	      collection.push_back(left->value);
	    }
	    if(right != nullptr){
	      collection.push_back(right->value);
	    }
	    std::vector<T> left_elements  = left  == nullptr ? std::vector<T>{} : left->getBreadthFirstVector();
	    std::vector<T> right_elements = right == nullptr ? std::vector<T>{} : right->getBreadthFirstVector();
	    left_elements.insert(left_elements.end(), right_elements.begin(), right_elements.end());
	    collection.insert(collection.end(), left_elements.begin(), left_elements.end());
	    return collection;
	  }

	}

	std::vector<T> getBreadthFirstVector() const{
    	  std::vector<T> collection = {};
    	  if(left != nullptr){
      	    collection.push_back(left->value);
    	  }
    	  if(right != nullptr){
	    collection.push_back(right->value);
    	  }
    	  std::vector<T> left_elements  = left  == nullptr ? std::vector<T>{} : left->getBreadthFirstVector();
    	  std::vector<T> right_elements = right == nullptr ? std::vector<T>{} : right->getBreadthFirstVector();
    	  left_elements.insert(left_elements.end(), right_elements.begin(), right_elements.end());
    	  collection.insert(collection.end(), left_elements.begin(), left_elements.end());
    	  return collection;

	}

};

#endif
