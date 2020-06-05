#ifndef REDBLACK
#define REDBLACK

#include <vector>
#include <algorithm>
#include "queue.hpp"
#include "stack.hpp"
#include <iostream>

template <class U>
class RedBlackTree{
  public:
    U value; 
    RedBlackTree *left = nullptr;
    RedBlackTree *right = nullptr;
    bool empty = true;
    bool black = true;
    RedBlackTree() {};
    RedBlackTree(U element): value(element), empty(false),
      black(false){};
    RedBlackTree(const std::vector<U>& vals){
      for(auto element : vals){
        std::cout << element << "\n";
        insert(element);
      } 
      if(vals.size() > 0){
        this->empty = false;
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

    std::vector<U> elementVector() const{
      if(isEmpty()){
        return {};
      }
      else{
	std::vector<U> collection  = left  == nullptr ? std::vector<U>{} : left->elementVector();
	collection.push_back(value);
	std::vector<U> right_elements = right == nullptr ? std::vector<U>{} : right->elementVector();
	collection.insert(collection.end(), right_elements.begin(), right_elements.end());
	return collection;
      }
    };

    /*
    void insert( const U& element){
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
	    left = new RedBlackTree(element);
	  }
	}
	else if(element > value){
	  if(right != nullptr){
	      right->insert(element);
	    }
	    else{
	      right = new RedBlackTree(element);
	  }
	  }
	};
	*/

    bool contains( const U& find ) const{
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

	U search( const U& find ) const{
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


    std::vector<U> makeBreadthFirstVector() {
	  if(isEmpty()){
	    return {};
	  }
	  std::vector<U> content = {};
	  Queue<RedBlackTree<U>*> queue = Queue<RedBlackTree<U>*>();
	  queue.enqueue(this);
	  while(not queue.isEmpty()){
	    RedBlackTree<U>* current = queue.dequeue();
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

    bool isBlack() const{
      return black;
    }

    void flip(){
      black = not black;
    }

    // Violation 
    bool isRightBlack() const{
      return right == nullptr ? true : right->black;
    }

    // Violation 
    bool isRedMinority() const{
      bool isLeftBlack = left == nullptr ? true : left->black;
      return isLeftBlack or isRightBlack();
    }

    // Violation 
    bool isRedChildless() const{
      if(left != nullptr){
        if(left->left != nullptr){
	  return left->left->black or left->black;
	}
	return true;
      }
      return true;
    }

    void rotateLeft(){
      U temp = value;
      value = right->value;
      right->value = temp;
      RedBlackTree<U>* hold = left;
      left = right;
      left->left = hold;
      hold = left->right;
      right = hold;
      left->right = nullptr;
    }

    void rotateRight(){
      U temp = value;
      value = left->value;
      left->value = temp;
      RedBlackTree<U>* hold = right;
      right = left;
      right->right = hold;
      hold = right->left;
      left = hold;
      right->left = nullptr;
    }

    void include(const U& element, RedBlackTree<U>* parent){
      if(empty){
        value = element;
        empty = false;
      }
      else if(value == element){
        return;
      }
      else if(element < value){
        if(left != nullptr){
  	  left->include(element, this);
        }
        else{
          left = new RedBlackTree(element);
        }
      }
      else if(element > value){
        if(right != nullptr){
	  right->include(element, this);
	}
	else{
	  right = new RedBlackTree(element);
	}
      }
    }

    bool fix(RedBlackTree<U>* parent){
      if(empty){
      	black = true;
	return true;
      }
      else{
	if(not isRightBlack()){
	  std::cout << "rotate left\n";
	  rotateLeft();
	  return false;
	}
        else if(not isRedMinority()){
	  std::cout << "flip\n";
	  flip(); left->flip(); right->flip();
	  return false;
	}
	else if(not isRedChildless()){
	  std::cout << "rotate right\n";
	  rotateRight();
	  right->flip();
	  return false;
	}
	return true;
      }
    }

    void insert(const U& element){
      include(element, nullptr);
      Stack<RedBlackTree<U>*> stack = {};
      RedBlackTree<U>* current = this;
      for(int i = 0; i < getHeight(); i++){
        stack.push(current);
        if(element < value){
  	  current = left;
        }
        else if(element > value){
  	  current = right;
        }
	else{
	  break;
	}
      }
      while(not stack.isEmpty()){
        RedBlackTree<U>* node = stack.pop();
	RedBlackTree<U>* parent = stack.isEmpty() ? nullptr : stack.peek();
	node->fix(parent);
      }
      black = true;
    }
};

#endif
