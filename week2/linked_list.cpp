#include "linked_list.hpp"

void Link<T>::insertAtHead(T element)
{
  next = new Link(value, next);
  value = element;
}

void Link<T>::insertAtTail(T element)
{
  if(next == nullptr){
    next = new Link(element);
  }
  else{
    next->insertAtTail(element);
  }
}

void Link<T>::insertAt(int index, T element)
{
    insertAt(index, element, 0);
}

void Link<T>::insertAt(int index, T element, int current)
{
  if(index - 1 <= current ){
    insertAtHead(element);
  }
  else{
    next->insertAt(index, element, current + 1);
  }
}

void Link<T>::removeFromHead()
{
  T* old = next;
  value = next->value;
  next = next->next;
  delete old;
}

void Link<T>::removeFromTail()
{
  if(next->next == nullptr){
    delete next->next;
    next = nullptr;
  }
  else{
    next->removeFromTail();
  }
}

void Link<T>::removeFrom(int index)
{
  removeFrom(index, 0);
}

void Link<T>::removeFrom(int index, int current)
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
}

int Link<T>::length()
{
  return length(0);
}

template <class T>
int Link<T>::length(int current)
{
  if(next == nullptr){
    return current + 1;
  }
  else{
    return next->length(current + 1);
  }
}

int Link<T>::search(T element) const
{
  return search(element, 0);
}

int Link<T>::search(T element, int current) const
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
}

std::vector<int> Link<T>::searchAll(T element) const
{
  return searchAll(element, 0, std::vector<int> {});
}

std::vector<int> Link<T>::searchAll(T element, int current, std::vector<int> collection) const
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
}

std::vector<T> Link<T>::toArray() const
{
  return toArray(std::vector<int> {});
}

std::vector<T> Link<T>::toArray(std::vector<T> collection) const
{  
  collection.push_back(value);
  if(next == nullptr){
    return collection;
  }
  else{
    return next->toArray(collection);
  }
}

void Link<T>::append(Link *links)
{
  if(next == nullptr){
    next = links;
  }
  else{
    next->append(links);
  }
}

