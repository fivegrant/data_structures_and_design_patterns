#ifndef REDBLACK
#define REDBLACK

#include "tree.hpp"

template <class U>
class RedBlackTree: public BinarySearchTree<U>{
  private:
    RedBlackTree *poly_left = nullptr;
    RedBlackTree *poly_right = nullptr;
    bool black = true;
  
  public:
    RedBlackTree(): BinarySearchTree<U>(){};
    RedBlackTree(U element): BinarySearchTree<U>(element),
      black(false){};
    RedBlackTree(const std::vector<U>& vals): BinarySearchTree<U>(){
      for(auto element : vals){
        insert(element);
      } 
      if(vals.size() > 0){
        this->fill();
      }
    }

    bool isBlack() const{
      return black;
    }

    void flip(){
      black = not black;
    }

    void invert(){
      flip();poly_left->flip();poly_right->flip();
    }

    // Violation 
    bool isRightBlack() const{
      return poly_right == nullptr ? true : poly_right->isBlack();
    }

    // Violation 
    bool isRedMinority() const{
      return poly_left->isBlack() or isRightBlack();
    }

    // Violation 
    bool isLeftValid() const{
      return not(isBlack() or (poly_left == nullptr ? true : poly_left->isBlack()));
    }

    void rotateLeft(RedBlackTree<U>* parent){
      if(parent != nullptr){
        parent->poly_right = poly_right; 
      }
      poly_right->poly_left = this;
      poly_right->flip();
      poly_right = nullptr;
      flip();
    }

    void rotateRight(RedBlackTree<U>* parent){
      if(parent != nullptr){
        parent->poly_left = poly_left; 
      }
      poly_left->poly_right = this;
      poly_left->flip();
      poly_left = nullptr;
      flip();
    }

    void include(const U& element, RedBlackTree<U>* parent){
      if(this->empty){
        this->value = element;
        this->empty = false;
      }
      else if(this->value == element){
        return;
      }
      else if(element < this->value){
        if(poly_left != nullptr){
  	  poly_left->include(element, parent);
      }
        else{
          poly_left = new RedBlackTree(element);
        }
      }
      else if(element > this->value){
        if(poly_right != nullptr){
	  poly_right->include(element, parent);
	}
	else{
	  poly_right = new RedBlackTree(element);
	}
      }
    }

    bool fix(const U& element, RedBlackTree<U>* parent){
      if(this->empty){
      	black = true;
	return true;
      }
      else{
        if(isRedMinority()){
	  this->invert();
	  return false;
	}
	else if(isRightBlack()){
	  this->rotateLeft(parent);
	  return false;
	}
	else if(isLeftValid()){
	  this->rotateRight(parent);
	  return false;
	}
	else if(element < this->value){
	  return poly_left == nullptr ? true : poly_left->fix(element, this);
	}
	else if(element > this->value){
	  return poly_right == nullptr ? true : poly_right->fix(element, this);
	}
	return true;
      }
    }

    void insert(const U& element){
      include(element, nullptr);
      bool clean = false;
      while(not clean){
        clean = fix(element, nullptr);
      }
    }

};

#endif
