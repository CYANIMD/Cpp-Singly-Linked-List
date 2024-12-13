#include "singlyLinkedList.h"

int main() {
	singlyLinkedList<int> my_list{};
	my_list.push_front(-5);
	my_list.push_front(-8);
	my_list.push_back(-2);
	my_list.push_back(0);
	my_list.push_back(3);

	my_list.remove_last();
	my_list.remove_last();
}