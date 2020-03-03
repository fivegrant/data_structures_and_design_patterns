void Link::insertAtHead(T element)
{
  next = new Link(value, next);
  value = element;
}

void Link::insertAtTail(T element)
{
  if(next == nullptr){
    next = new Link(element)
  }
  else{
    next->insertAtTail(element);
  }
}

void Link::insertAt(int index, T element)
{
    insertAt(index, element, 0);
}

void Link::insertAt(int index, T element, int current)
{
  if(index - 1 <= current ){
    insertAtHead(element);
  }
  else{
    next->insertAt(index, element, current + 1);
  }
}

void Link::removeFromHead()
{
  T* old = next;
  value = next->value;
  next = next->next;
  delete old;
}

void Link::removeFromTail()
{
  if(next->next == nullptr){
    delete next->next;
    next = nullptr;
  }
  else{
    next->removeFromTail(element);
  }
}

void Link::removeFrom(int index)
{
  removeFrom(index, 0);
}

void Link::removeFrom(int index, int current)
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
    next->insertAt(index, element, current + 1);
  }
}

int Link::length()
{
  return length(0);
}

int Link::length(int current)
{
  if(next == nullptr){
    return current + 1;
  }
  else{
    return next->length(current + 1);
  }
}

int Link::search(T element) const
{
  search(element, 0);
}

int Link::search(T element, int current) const
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

std::vector<int> Link::searchAll(T element) const
{
  return searchAll(element, 0, std::vector<int> {});
}

std::vector<int> Link::searchAll(T element, int current, std::vector<int> collection) const
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

std::vector<T> Link::toArray() const
{
  return toArray(std::vector<int> {});
}

std::vector<T> Link::toArray(std::vector<T> collection) const
{  
  collection.push_back(current);
  if(next == nullptr){
    return collection;
  }
  else{
    return next->toArray(collection);
  }
}

void Link::append(Link *links)
{
  if(next == nullptr){
    next = links;
  }
  else{
    next->append(links);
  }
}

