﻿#include <iostream>
#include "singlyLinkedList.h"

int main() {
	setlocale(LC_ALL, "Russian");

	singlyLinkedList<double>* my_list1 = new singlyLinkedList<double>();

	std::cout << "Линейный односвязный список: " << *my_list1 << std::endl;

	reverse(my_list1);
	distinct(my_list1);

	my_list1->pop_front();
	my_list1->pop_back();

	std::cout << "Линейный односвязный список через оператор <<: " << *my_list1 << std::endl;

	my_list1->push_back(1.65);
	my_list1->push_back(2.72);
	my_list1->push_back(3.14);
	my_list1->push_front(0);
	my_list1->push_front(-1);
	my_list1->push_back(6.022);

	std::cout << "Линейный односвязный список через оператор <<: " << *my_list1 << std::endl;

	std::cout << "Линейный односвязный список через метод print(): " << std::endl; print(my_list1);
	std::cout << "Линейный односвязный список через метод for_each(): " << std::endl; for_each(my_list1, [](const double& value) {std::cout << value << "=>"; }); std::cout << std::endl;
	my_list1->push_back(-1);
	my_list1->push_back(3.14);
	my_list1->push_back(0);
	std::cout << "Линейный односвязный список с повторными значениями через оператор <<: " << *my_list1 << std::endl;
	std::cout << "Линейный односвязный список без повторных значений через оператор <<: " << *distinct(my_list1) << std::endl;
	std::cout << "Реверсированный инейный односвязный список через оператор <<: " << *reverse(my_list1) << std::endl;
	std::cout << "Значение узла с индексом 0: " << (*my_list1)[0] << std::endl;
	std::cout << "Значение узла с индексом 1: " << (*my_list1)[1] << std::endl;
	std::cout << "Значение узла с индексом 2: " << (*my_list1)[2] << std::endl;
	std::cout << "Значение узла с индексом 3: " << (*my_list1)[3] << std::endl;

	std::cout << "Пустой ли линейный односвязный список: " << my_list1->isEmpty() << std::endl;
	std::cout << "Размер линейного односвязного списка: " << my_list1->size() << std::endl;

	singlyLinkedList<double>* my_list2 = new singlyLinkedList<double>();
	my_list2->push_back(2);
	my_list2->push_back(0.5);
	my_list2->push_back(-0.97);

	std::cout << "Линейный односвязный список через оператор <<: " << *my_list2 << std::endl;
	std::cout << "Слияние двух линейных односвязных списков через оператор <<: " << *merge(my_list2, my_list1) << std::endl;
	std::cout << "Линейный односвязный список через оператор <<: " << *my_list1 << std::endl;
	std::cout << "Линейный односвязный список через оператор <<: " << *my_list2 << std::endl;

	my_list1->rightShift(1);
	std::cout << "Линейный односвязный список смещённый на 1 позицию вправо через оператор <<: " << *my_list1 << std::endl;
	my_list1->rightShift(2);
	std::cout << "Линейный односвязный список смещённый на 2 позиции вправо через оператор <<: " << *my_list1 << std::endl;
	my_list1->leftShift(2);
	std::cout << "Линейный односвязный список смещённый на 2 позиции влево через оператор <<: " << *my_list1 << std::endl;
	my_list1->leftShift(1);
	std::cout << "Линейный односвязный список смещённый на 1 позиции влево через оператор <<: " << *my_list1 << std::endl;


	singlyLinkedList<int> l1{};
	l1.push_back(-1);
	l1.push_back(0);
	l1.push_back(1);
	singlyLinkedList<int> l2{};
	l2 = *copy(&l1);;
	std::cout << "Линейный односвязный через оператор <<: " << l1 << std::endl;
	std::cout << "Линейный односвязный через оператор <<: " << l2 << std::endl;

	l1 = l2;
}