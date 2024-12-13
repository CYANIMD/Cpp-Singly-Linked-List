#include <iostream>
#include "singlyLinkedList.h"

int main() {
	singlyLinkedList<int> my_list1{};
	singlyLinkedList<int> my_list2{};
	my_list1.push_front(-5);
	auto node1 = my_list1.push_front(-8);
	my_list1.push_back(-2);
	auto node2 = my_list1.push_back(0);
	auto node3 = my_list1.push_back(3);

	my_list1.insert_before(node1, -12);
	my_list1.insert_before(node2, -1);
	my_list1.insert_after(node3, 9);

	auto node4 = my_list2.push_back(2);

}