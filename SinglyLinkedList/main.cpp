#include "singlyLinkedList.h"

int main() {
	singlyLinkedList<int> my_list{};
	my_list.push_front(-5);
	auto node1 = my_list.push_front(-8);
	my_list.push_back(-2);
	auto node2 = my_list.push_back(0);
	auto node3 = my_list.push_back(3);

	my_list.insert_before(node1, -12);
	my_list.insert_before(node2, -1);
	my_list.insert_after(node3, 9);
}