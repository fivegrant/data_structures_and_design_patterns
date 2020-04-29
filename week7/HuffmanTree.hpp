//
//  HuffmanTree.hpp
//  BinarySearchTreeC++
//
//  Created by Justin Vasselli on 3/17/17.
//  Copyright © 2017 Justin Vasselli. All rights reserved.
//

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <map>

class HuffmanTree;

struct EncodedString
{
    const HuffmanTree* tree;
    std::vector<char> message;
};

class HuffmanTree
{
public:
    int occurrences;
    char character; //will be '-' if non-leaf node
    HuffmanTree* left = nullptr;
    HuffmanTree* right = nullptr;
    
    bool isLeaf();
    
    HuffmanTree( int occurrences, char character = '-' );
    
    static char reveal( char character );
    
    static EncodedString encode( const std::string message );
    
    static std::string decode( const EncodedString& encodedMessage );
    
    static HuffmanTree* buildTestTree();
};

#endif /* HuffmanTree_hpp */
