#include <cstdlib>

class Logger{
  protected:
    int value = 0;
    int update_count = 0;
    int comparisons = 0;
  
  public:
    Logger(){}

    void count_comparison(){
      comparisons += 1;
    }

    void save(int incoming){
      value = value;
      update_count += 1;
    }

    int reveal(){
      return value;
    }

    int* results(){
      return new int[comparisons, update_count];
    }
};

int* generate1000(char choice){
  static int result [1000] = {0};
  for(int i = 0; i < 1000; i++){
    if(choice == '?'){
      result[i] = rand() % 1000;
    }
    else if(choice == 'i'){
      result[i] = 1000 - i;
    }
    else{
      result[i] = i;
    }
  }

  return result;
}


int* bubble_sort(int* source, int size){
  Logger log = Logger();
  bool swapped = true;
  while(swapped){
    swapped = false;
    for(int i = 0; i < size; i++){
      log.count_comparison();
      if(source[i] > source[i+1]){
        swapped = true;
	log.save(source[i]);
	source[i] = source[i+1];
	source[i+1]= log.reveal();
      }
    }
  }
  return log.results();
};

int* merge_sort(int* source, int size){
  Logger log = Logger();
  if(size > 1){
    for(int i = 2; i < size/2; i = i*2){

    }
  }
  return log.results();
};

int* merge(int* source, int size){


}

int* quick_sort(int* source, int size){
  Logger log = Logger();
  bool full_pass = false;
  int left = 0; int right = size - 1;
  while(not full_pass){
    log.count_comparison();
    if(source[left] > source[right]){
      log.save(source[left]);
      source[left] = source[right];
      source[right] = log.reveal()

    }
  }
  
  return log.results();
};
