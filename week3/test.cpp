#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include <string>
#include "doubley_linked_list.hpp"

TEST_CASE("Initialize Linked List"){
   Link<std::string> first_node = Link<std::string>("Hello");
   REQUIRE(first_node.value == "Hello");
   REQUIRE(first_node.next == nullptr);
   REQUIRE(first_node.prev == nullptr);
   REQUIRE(first_node.value == first_node.firstElement());

   Link<std::string> two_node = Link<std::string>("again", &first_node);
   REQUIRE(two_node.value == "again");
   REQUIRE(two_node.next == &first_node);
}

TEST_CASE("Insert into Linked List"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Fourth");
   linked.insertAtIndex(2, "Fifth");
   std::vector<std::string> comp = {"Second","First", "Fifth","Third", "Fourth"};
   int size = linked.getLength();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 5);
   Link<std::string> linked2 = Link<std::string>("Extra");
   linked2.insertAtTail("Stuff");
   linked.appendList(&linked2);
   std::vector<std::string> comp2 = {"Second","First", "Fifth","Third", "Fourth", "Extra", "Stuff"};
   REQUIRE(comp2 == linked.toArray());
   REQUIRE(linked.lastElement() == "Stuff");
}

TEST_CASE("Remove Elements"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Fourth");
   linked.insertAtIndex(2, "Fifth");
   linked.removeFromHead();
   linked.removeFromTail();
   linked.removeFromIndex(1);
   std::vector<std::string> comp = {"First","Third"};
   int size = linked.getLength();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 2);
}

TEST_CASE("Search Stuff"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Third");
   linked.insertAtIndex(2, "Fifth");
   std::vector<std::string> comp = {"Second","First", "Fifth","Third", "Third"};
   int size = linked.getLength();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 5);
   REQUIRE(linked.search("First") == 1);
   REQUIRE(linked.searchAll("Third") == std::vector<int> {3, 4});
}

 

