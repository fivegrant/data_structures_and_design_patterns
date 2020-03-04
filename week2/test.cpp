#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include <string>
#include "linked_list.cpp"

TEST_CASE("Initialize Linked List"){
   Link<std::string> first_node = Link<std::string>("Hello");
   REQUIRE(first_node.value == "Hello");
   REQUIRE(first_node.next == nullptr);

   Link<std::string> two_node = Link<std::string>("again", &first_node);
   REQUIRE(two_node.value == "again");
   REQUIRE(two_node.next == &first_node);
}
 

