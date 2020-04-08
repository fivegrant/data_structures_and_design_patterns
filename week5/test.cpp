#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "tree.hpp"

TEST_CASE("Initialize Binary Trees"){
   BinarySearchTree<int> first_node = BinarSearchTree<int>();
   BinarySearchTree<int> first_node.insert(5)
   REQUIRE(first_node.contains(5));
}

