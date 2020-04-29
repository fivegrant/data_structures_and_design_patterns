//
//  main.cpp
//  BinarySearchTreeC++
//
//  Created by Justin Vasselli on 3/17/17.
//  Copyright © 2017 Justin Vasselli. All rights reserved.
//

#include <iostream>
#include "HuffmanTree.hpp"

int main(int argc, const char * argv[]) {
    HuffmanTree* testTree = HuffmanTree::buildTestTree();
    
    //Level 3C
    EncodedString encodedString;
    encodedString.message = { static_cast<char>(0b11101101), static_cast<char>(0b10100100), static_cast<char>(0b10000111), static_cast<char>(0b11101100) };
    encodedString.tree = testTree;
    std::cout << HuffmanTree::decode(encodedString) << std::endl;
    
    return 0;
}
