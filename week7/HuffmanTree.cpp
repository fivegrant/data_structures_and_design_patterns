//
//  HuffmanTree.cpp
//  BinarySearchTreeC++
//
//  Created by Justin Vasselli on 3/17/17.
//  Copyright © 2017 Justin Vasselli. All rights reserved.
//

#include "HuffmanTree.hpp"
#include <iostream>

std::map<int, std::deque<char>> getCounts(std::string data)
{
  std::map<char, int> counts = {};
  std::vector<char> keys = {} ;
  for(char character: data){
    if(counts.find(character) == counts.end()){
      counts[character] = 1;
      keys.push_back(character);
    }
    else{
      counts[character] += 1;
    }
  }
  std::map<int, std::deque<char>> occurrences = {};
  for(char key: keys){
    int index = counts[key];
    if(occurrences.find(index) == occurrences.end()){
      occurrences[index] = std::deque<char> {key};
    }
    else{
      occurrences[index].push_back(key);
    }

  }
  return occurrences;
}

bool HuffmanTree::isLeaf()
{
    return left == nullptr && right == nullptr;
}

HuffmanTree::HuffmanTree( int occurrences, char character )
{
    this->occurrences = occurrences;
    this->character = character;
}

EncodedString HuffmanTree::encode( const std::string message )
{
    // What level of occurrences are currently being observed
    std::map<int, std::deque<char>> letter_counts = getCounts(message);
    std::map<int, std::deque<HuffmanTree*>> node_counts = {};
    std::vector<char> construct = {};
    int occ_level = letter_counts.begin()->first;
    int last_level = occ_level + 1;
    while(occ_level <= last_level){
      if(letter_counts[occ_level].empty() and node_counts[occ_level].empty()){
        occ_level += 1;
        int last_level = letter_counts.rbegin()->first;
      }
      else{
        HuffmanTree* node = new HuffmanTree(0, '-');
	while(node->left == nullptr or node->right == nullptr){
	  if(not node_counts[occ_level].empty()){
	    node->occurrences += occ_level;
	    if(node->left == nullptr){
	      node->left = node_counts[occ_level].front();
	      node_counts[occ_level].pop_front();
	    }
	    else{
	      node->right = node_counts[occ_level].front();
	      node_counts[occ_level].pop_front();
	    }
	  }
	  else if(not letter_counts[occ_level].empty()){
	    node->occurrences += occ_level;
	    if(node->left == nullptr){
	      node->left = new HuffmanTree(occ_level,letter_counts[occ_level].front());
	      letter_counts[occ_level].pop_front();
	    }
	    else{
	      node->right = new HuffmanTree(occ_level,letter_counts[occ_level].front());
	      letter_counts[occ_level].pop_front();	    }
	  }
	  else{
	    occ_level += 1;
	  }
	  
	}
        int last_level = letter_counts.rbegin()->first;
      }
    }
    EncodedString returnString;
    returnString.message = construct;
    returnString.tree = node_counts[last_level].front();
    return returnString;
}

std::string HuffmanTree::decode( const EncodedString& encodedMessage )
{
    std::string construct = "";
    HuffmanTree* top = new HuffmanTree(encodedMessage.tree->occurrences, '-');
    top->left = encodedMessage.tree->left;
    top->right = encodedMessage.tree->right;
    HuffmanTree* node = top;
    for(auto character: encodedMessage.message){
      node = character == '0' ? node->left : node->right;
      std::cout << "yay\n";
      std::cout << character << "\n";
      if(node->character != '-'){
        construct += character;
        HuffmanTree* node = top;
      }

    }
    delete top;
    return construct;
}

//Provided
HuffmanTree* HuffmanTree::buildTestTree()
{
    HuffmanTree* d = new HuffmanTree( 1, 'd' );
    HuffmanTree* e = new HuffmanTree( 1, 'e' );
    HuffmanTree* h = new HuffmanTree( 1, 'h' );
    HuffmanTree* r = new HuffmanTree( 1, 'r' );
    HuffmanTree* w = new HuffmanTree( 1, 'w' );
    HuffmanTree* space = new HuffmanTree( 1, ' ' );
    HuffmanTree* o = new HuffmanTree( 2, 'o' );
    HuffmanTree* l = new HuffmanTree( 3, 'l' );
    
    HuffmanTree* de = new HuffmanTree( 2 );
    de->left = d;
    de->right = e;
    
    HuffmanTree* hr = new HuffmanTree( 2 );
    hr->left = h;
    hr->right = r;
    
    HuffmanTree* wspace = new HuffmanTree( 2 );
    wspace->left = w;
    wspace->right = space;
    
    HuffmanTree* dehr = new HuffmanTree( 4 );
    dehr->left = de;
    dehr->right = hr;
    
    HuffmanTree* wSpaceO = new HuffmanTree( 4 );
    wSpaceO->left = wspace;
    wSpaceO->right = o;
    
    HuffmanTree* ldehr = new HuffmanTree(7);
    ldehr->left = l;
    ldehr->right = dehr;
    
    HuffmanTree* testTree = new HuffmanTree(11);
    testTree->left = wSpaceO;
    testTree->right = ldehr;
    
    return testTree;
}

// last element source: https://stackoverflow.com/questions/289715/last-key-in-a-stdmap
