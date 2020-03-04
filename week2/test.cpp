#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include <string>
#include "linked_combined.hpp"

TEST_CASE("Initialize Linked List"){
   Link<std::string> first_node = Link<std::string>("Hello");
   REQUIRE(first_node.value == "Hello");
   REQUIRE(first_node.next == nullptr);

   Link<std::string> two_node = Link<std::string>("again", &first_node);
   REQUIRE(two_node.value == "again");
   REQUIRE(two_node.next == &first_node);
}

TEST_CASE("Insert into Linked List"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Fourth");
   linked.insertAt(2, "Fifth");
   std::vector<std::string> comp = {"First","Second","Fifth","Third", "Fourth"};
   int size = linked.length();
   REQUIRE(size == 4);
   REQUIRE(comp == linked.toArray());
}

 

