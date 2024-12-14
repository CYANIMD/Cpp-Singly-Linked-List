#ifndef __SINGLYLINKEDLIST_
#define __SINGLYLINKEDLIST_

#include <iostream>
#include <functional>

//Класс, реализующий "узел линейного односвязного списка".
template<typename T>
class singlyLinkedListNode {
public:
	//Значение, хранимое в узле.
	T _data;
	//Указатель на следующий узел.
	singlyLinkedListNode<T>* _next;
	//Конструктор по умолчанию.
	singlyLinkedListNode() : _data(T()), _next(nullptr) {}
	//Конструктор с входными параметрами.
	singlyLinkedListNode(const T& data) : _data(data), _next(nullptr) {}
	//Конструктор с входными параметрами.
	singlyLinkedListNode(T data, singlyLinkedListNode<T>* next) : _data(data), _next(next) {}
	//Оператор вывода в поток.
	friend std::ostream& operator<<(std::ostream& os, const singlyLinkedListNode<T>& node) {
		os << node._data;
		return os;
	}


	//Деструктор не нужен.
};

//Класс, реализующий "линейный односвязный список".
template<typename T>
class singlyLinkedList {
public:
	//Указатель на первый элемент списка.
	singlyLinkedListNode<T>* _first;
	//Конструктор по умолчанию.
	singlyLinkedList() : _first(nullptr) {}
	//Деструктор.
	~singlyLinkedList() {
		clear();
	}
	//Оператор вывода в поток.
	friend std::ostream& operator<<(std::ostream& os, const singlyLinkedList<T>& list) {
		singlyLinkedListNode<T>* node = list._first;
		while (node != nullptr) {
			os << node->_data << ' ';
			node = node->_next;
		}
		return os;
	}
	//Добавление элемента в начало списка.
	//Возвращает указатель на добавленный элемент.
	singlyLinkedListNode<T>* push_front(const T& value) {
		_first = new singlyLinkedListNode<T>{ value, _first };
		return _first;
	}
	//Добавление элемента в конец списка.
	//Возвращает указатель на добавленный элемент.
	singlyLinkedListNode<T>* push_back(const T& value) {
		if (_first == nullptr) {
			return push_front(value);
		}
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode->_next != nullptr) {
			currentNode = currentNode->_next;
		}
		currentNode->_next = new singlyLinkedListNode<T>{ value };
		return currentNode->_next;
	}
	//Удаление первого элемента списка.
	void remove_first() {
		if (_first == nullptr) return;

		singlyLinkedListNode<T>* node = _first;
		_first = _first->_next;
		delete node;
	}
	//Удаление последнего элемента списка.
	void remove_last() {
		if (_first == nullptr) return;

		if (_first->_next == nullptr) {
			delete _first;
			_first = nullptr;
		}
		else {
			singlyLinkedListNode<T>* node = _first;
			while (node->_next->_next != nullptr) { //Поиск предпоследнего элемента.
				node = node->_next;
			}
			delete node->_next;
			node->_next = nullptr;
		}
	}
	//Возвращает количество узлов списка.
	size_t count() const {
		size_t result{ 0 };
		singlyLinkedListNode<T>* node = _first;
		while (node != nullptr) {
			result++;
			node = node->_next;
		}
		return result;
	}
	//Вставка элемента после указанного узла.
	//Возвращает указатель на добавленный элемент.
	//Если указанного узла нет в списке, то возвращается nullptr.
	singlyLinkedListNode<T>* insert_after(singlyLinkedListNode<T>& node, const T& value) {
		if (_first == nullptr) return nullptr;
		if (!hasNode(node)) return nullptr;

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, node._next };
		node._next = newNode;
		return newNode;
	}
	//Вставка элемента перед указанным узлом.
	//Возвращает указатель на добавленный элемент.
	//Если указанного узла нет в списке, то возвращается nullptr.
	singlyLinkedListNode<T>* insert_before(const singlyLinkedListNode<T>& node, const T& value) {
		if (_first == nullptr) return nullptr;
		//if (!hasNode(node)) return nullptr;
		//Проверка излишне увеличит время выполнения метода в два раза.

		if (_first == &node) return push_front(value);

		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr && currentNode->_next != &node) {
			currentNode = currentNode->_next;
		}

		if (currentNode == nullptr) return nullptr;

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, currentNode->_next };
		currentNode->_next = newNode;
		return newNode;
	}
	//Проверяет, содержит ли список данный узел.
	bool hasNode(const singlyLinkedListNode<T>& node) const {
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode == &node) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
	//Очистка списка с высвобождением затрачиваемой памяти.
	void clear() {
		while (_first != nullptr) { //Проход по всем узлам и освобождение ресурсов, затрачиваемых на них.
			singlyLinkedListNode<T>* node = _first;
			_first = _first->_next;
			delete node;
		}
	}
	//Проверяет, пустой ли список.
	bool isEmpty() const {
		return _first == nullptr;
	}
};
//Возвращает реверсированный исходный линейный односвязный список.
template<typename T>
singlyLinkedList<T>* reverse(const singlyLinkedList<T>& list) {
	singlyLinkedList<T>* result = new singlyLinkedList<T>();
	singlyLinkedListNode<T>* node = list._first;
	while (node != nullptr) {
		result->push_front(node->_data);
		node = node->_next;
	}
	return result;
}
//Возвращает указатель на первое вхождение в список указанного значения.
//Если такого вхождения нет, то возвращается nullptr.
template<typename T>
singlyLinkedListNode<T>* find(const singlyLinkedList<T>& list, T value) {
	singlyLinkedListNode<T>* node = list._first;
	while (node != nullptr) {
		if (node->_data == value) return node;
		node = node->_next;
	}
	return nullptr;
}
//Обход линейного односвязного списка с выполнением заданного метода.
template<typename T>
void for_each(const singlyLinkedList<T>& list, void(*f)(T)) {
	singlyLinkedListNode<T>* node = list._first;
	while (node != nullptr) {
		f(node->_data);
		node = node->_next;
	}
}
//Вывод в консоль узлов линейного односвязного списка и их связей.
template<typename T>
void print(const singlyLinkedList<T>& list) {
	singlyLinkedListNode<T>* node = list._first;
	while (node != nullptr) {
		std::cout << node->_data << "->";
		node = node->_next;
	}
	std::cout << "||" << std::endl;
}




#endif __SINGLYLINKEDLIST_
