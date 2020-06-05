#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "rb.hpp"

TEST_CASE("Initialize RB Trees"){
   RedBlackTree<int> first_node = RedBlackTree<int>();
   REQUIRE(first_node.isEmpty());
   first_node.insert(5);
   REQUIRE(first_node.getHeight() == first_node.getSize() );
   REQUIRE(first_node.isBalanced());
   REQUIRE(not first_node.isEmpty());
   REQUIRE(first_node.contains(5));
}

TEST_CASE("Search RB Tree"){
   std::vector<int> content = std::vector<int>{ 3, 10, 8 };
   std::vector<int> correct = std::vector<int> {1, 3, 8, 10};
   std::vector<int> breadth = std::vector<int> {3, 1, 8, 10};
   RedBlackTree<int> tree = RedBlackTree<int>(content);
   REQUIRE(tree.getHeight() == 2);
   REQUIRE(tree.isBalanced());
   REQUIRE(not tree.isEmpty());
   REQUIRE(tree.contains(8));
   REQUIRE(tree.makeBreadthFirstVector() == std::vector<int> {8, 3, 10});
   REQUIRE(tree.right->black);
   tree.insert(1);
   REQUIRE(tree.elementVector() == correct);
   REQUIRE(tree.makeBreadthFirstVector() == breadth);
   REQUIRE(tree.contains(1));
   REQUIRE(tree.contains(10));
   REQUIRE(not tree.isBalanced());
   REQUIRE(not tree.isEmpty());
   REQUIRE(tree.contains(3));
   REQUIRE(tree.getHeight() == 3);
   REQUIRE(tree.getSize() == 4);
}

