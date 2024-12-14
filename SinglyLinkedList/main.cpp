#include <iostream>
#include "singlyLinkedList.h"

int main() {
	singlyLinkedList<int>* my_list1 = new singlyLinkedList<int>();
	singlyLinkedListNode<int>* node1 = my_list1->push_front(0);
	my_list1->push_back(1);
	my_list1->push_back(1);
	my_list1->push_back(2);
	my_list1->push_back(3);
	my_list1->push_back(5);
	my_list1->push_back(8);

	singlyLinkedList<int>* my_list2 = new singlyLinkedList<int>();
	my_list2->push_back(1);
	my_list2->push_back(1);
	std::cout << "nullptr:" << (my_list2->insert_before(*node1, 5) == nullptr) << std::endl;

	std::cout << my_list2->hasNode(*node1) << std::endl;


	std::cout << *my_list1 << std::endl;

	print(*my_list1);

	auto my_list3 = reverse(*my_list1);
	std::cout << *my_list3;

	auto node2 = find(*my_list1, 10);

	delete my_list1;
	delete my_list2;
	delete my_list3;
}