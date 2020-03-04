#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include <string>
#include "linked_list_fixed.hpp"

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
   std::vector<std::string> comp = {"Second","Fifth","First","Third", "Fourth"};
   int size = linked.length();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 5);
   Link<std::string> linked2 = Link<std::string>("Extra");
   linked2.insertAtTail("Stuff");
   linked.append(&linked2);
   std::vector<std::string> comp2 = {"Second","Fifth","First","Third", "Fourth", "Extra", "Stuff"};
   REQUIRE(comp2 == linked.toArray());
}

TEST_CASE("Remove Elements"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Fourth");
   linked.insertAt(2, "Fifth");
   linked.removeFromHead();
   linked.removeFromTail();
   linked.removeFrom(1);
   std::vector<std::string> comp = {"Fifth","Third"};
   int size = linked.length();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 2);
}

TEST_CASE("Search Stuff"){
   Link<std::string> linked = Link<std::string>("First");
   linked.insertAtHead("Second");
   linked.insertAtTail("Third");
   linked.insertAtTail("Third");
   linked.insertAt(2, "Fifth");
   std::vector<std::string> comp = {"Second","Fifth","First","Third", "Third"};
   int size = linked.length();
   REQUIRE(comp == linked.toArray());
   REQUIRE(size == 5);
   REQUIRE(linked.search("First") == 2);
   REQUIRE(linked.searchAll("Third") == std::vector<int> {3, 4});
}

 

