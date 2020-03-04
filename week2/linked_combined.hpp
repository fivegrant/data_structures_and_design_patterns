#include <string>
#include <vector>

// Linked List Class
template <class T>
class Link{
  public: 
    T value; 
    Link *next = nullptr; 
    Link() {};
    Link(T element): value(element){};
    Link(T element, Link *address): value(element),next(address){};
    void insertAtHead(T element){
      next = new Link(value, next);
      value = element;
      };
    void insertAtTail(T element){
      if(next == nullptr){
      next = new Link(element);
      }
      else{
      next->insertAtTail(element);
      }
    };   
    void insertAt(int index, T element){
      insertAt(index, element, 0);
    };
    void insertAt(int index, T element, int current){
      if(index - 1 <= current ){
      insertAtHead(element);
    }
    else{
      next->insertAt(index, element, current + 1);
    }
    };

void removeFromHead(){
  T* old = next;
  value = next->value;
  next = next->next;
  delete old;
};

void removeFromTail()
{
  if(next->next == nullptr){
    delete next->next;
    next = nullptr;
  }
  else{
    next->removeFromTail();
  }
};

void removeFrom(int index)
{
  removeFrom(index, 0);
};

void removeFrom(int index, int current)
{
  if(index == 0){
    removeFromHead();
  }
  else if(index - 1 <= current ){
    T* old = next;
    next = next->next;
    delete old;
  }
  else{
    next->insertAt(index, current + 1);
  }
};

int length(){
  return length(0);
};

int length(int current)
{
  if(next == nullptr){
    return current + 1;
  }
  else{
    return next->length(current + 1);
  }
};

int search(T element) const
{
  return search(element, 0);
};

int search(T element, int current) const
{
  if(element == value){
    return current;
  }
  if(next == nullptr){
    return -1;
  }
  else{
    return next->search(element, 0);
  }
};

std::vector<int> searchAll(T element) const
{
  return searchAll(element, 0, std::vector<int> {});
};

std::vector<int> searchAll(T element, int current, std::vector<int> collection) const
{
  if(element == value){
    collection.push_back(current);
  }
  if(next == nullptr){
    return collection;
  }
  else{
    return next->searchAll(collection);
  }
};

std::vector<T> toArray() const
{
  return toArray(std::vector<T> {});
};

std::vector<T> toArray(std::vector<T> collection) const
{  
  collection.push_back(value);
  if(next == nullptr){
    return collection;
  }
  else{
    return next->toArray(collection);
  }
};

void append(Link *links)
{
  if(next == nullptr){
    next = links;
  }
  else{
    next->append(links);
  }
};
};


