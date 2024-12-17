#ifndef __SINGLYLINKEDLIST_
#define __SINGLYLINKEDLIST_

#include <iostream>
#include <stdexcept>
#include <unordered_set>
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
	singlyLinkedListNode(const T& data, singlyLinkedListNode<T>* next) : _data(data), _next(next) {}
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
private:
	//Указатель на первый элемент списка.
	singlyLinkedListNode<T>* _first;
	//Размер списка.
	size_t _size;
public:
	//Конструктор по умолчанию.
	singlyLinkedList() : _first(nullptr), _size(0) {}
	//Конструктор копии.
	singlyLinkedList(const singlyLinkedList<T>& other) : _size(other.size()) {
		for (size_t i{ 0 }; i < other.size(); i++) {
			push_back(other.get(i));
		}
	}

	//Деструктор.
	~singlyLinkedList() {
		clear();
	}

	//Операторы.

	//Оператор присваивания.
	singlyLinkedList<T>& operator=(const singlyLinkedList<T>& l2) {
		if (this != &l2) {
			clear();
			for (size_t i{ 0 }; i < l2.size(); ++i) {
				push_back(l2.get(i));
			}
			return *this;
		}
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
	//Оператор доступа к значению узла с заданным индексом.
	T& operator[](int index) {
		if (index < 0) throw std::invalid_argument("index < 0");
		if (index >= size())throw std::invalid_argument("index >= size()");
		singlyLinkedListNode<T>* node = _first;
		while (index > 0) {
			node = node->_next;
			index--;
		}
		return node->_data;
	}
	//Оператор доступа к значению узла с заданным индексом.
	const T& operator[](int index) const {
		if (index < 0) throw std::invalid_argument("index < 0");
		if (index >= size())throw std::invalid_argument("index >= size()");
		singlyLinkedListNode<T>* node = _first;
		while (index > 0) {
			node = node->_next;
			index--;
		}
		return node->_data;
	}

	//Методы.

	//Возвращает элемент узла с заданным индексом.
	T get(int index) const {
		if (index < 0) throw std::invalid_argument("index < 0");
		if (index >= size())throw std::invalid_argument("index >= size()");
		singlyLinkedListNode<T>* node = _first;
		while (index > 0) {
			node = node->_next;
			index--;
		}
		return node->_data;
	}
	//Возвращает размер списка.
	size_t size() const {
		return _size;
	}
	//Добавление элемента в начало списка.
	//Возвращает указатель на добавленный элемент.
	const singlyLinkedListNode<T>* push_front(const T& value) {
		_first = new singlyLinkedListNode<T>{ value, _first };
		_size++;
		return _first;
	}
	//Добавление элемента в конец списка.
	//Возвращает указатель на добавленный элемент.
	const singlyLinkedListNode<T>* push_back(const T& value) {
		if (_first == nullptr) {
			return push_front(value); //_size меняется внутри push_front()
		}
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode->_next != nullptr) {
			currentNode = currentNode->_next;
		}
		currentNode->_next = new singlyLinkedListNode<T>{ value };
		_size++;
		return currentNode->_next;
	}
	//Удаление первого элемента списка.
	void pop_front() {
		if (_first == nullptr) return;

		singlyLinkedListNode<T>* node = _first;
		_first = _first->_next;
		_size--;
		delete node;
	}
	//Удаление последнего элемента списка.
	void pop_back() {
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
		_size--;
	}
	//Вставка элемента после указанного узла.
	//Возвращает указатель на добавленный элемент.
	//Если указанного узла нет в списке, то возвращается nullptr.
	const singlyLinkedListNode<T>* insert_after(singlyLinkedListNode<T>* const node, const T& value) {
		if (_first == nullptr || node == nullptr) return nullptr;
		if (!hasNode(node)) throw std::invalid_argument("singlyLinkedList doesn't have node");

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, node->_next };
		node->_next = newNode;
		_size++;
		return newNode;
	}
	//Вставка элемента перед указанным узлом.
	//Возвращает указатель на добавленный элемент.
	//Если указанного узла нет в списке, то возвращается nullptr.
	const singlyLinkedListNode<T>* insert_before(const singlyLinkedListNode<T>* const node, const T& value) {
		if (_first == nullptr || node == nullptr) return nullptr;
		//if (!hasNode(node)) return nullptr;
		//Проверка излишне увеличит время выполнения метода в два раза.

		if (_first == node) return push_front(value); //_size меняется внутри метода push_front()

		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr && currentNode->_next != node) {
			currentNode = currentNode->_next;
		}

		if (currentNode == nullptr) throw std::invalid_argument("singlyLinkedList doesn't have node");

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, currentNode->_next };
		currentNode->_next = newNode;
		_size++;
		return newNode;
	}
	//Проверяет, содержит ли список данный узел.
	bool hasNode(const singlyLinkedListNode<T>* const node) const {
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode == node) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
	//Проверяет, содержит ли список данное значение.
	bool hasValue(const T& value) const {
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode->_data == value) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
	//Проверяет, пустой ли список.
	bool isEmpty() const {
		return _first == nullptr; //Можно написать _size == 0
	}
	//Очистка списка с высвобождением затрачиваемой памяти.
	void clear() {
		while (_first != nullptr) { //Проход по всем узлам и освобождение ресурсов, затрачиваемых на них.
			singlyLinkedListNode<T>* node = _first;
			_first = _first->_next;
			delete node;
		}
		_size = 0;
	}
	//Сдвиг вправо на k позиций.
	void rightShift(int k) {
		if (k < 0) throw std::invalid_argument("k < 0");
		if (k == 0) return;
		if (size() == 0 || size() == 1) return;
		k %= size(); //Определяем число перестановок.

		singlyLinkedListNode<T>* newLastNode = _first;
		for (size_t i{ 0 }; i < size() - k - 1; i++) {
			newLastNode = newLastNode->_next;
		}
		singlyLinkedListNode<T>* newFirstNode = newLastNode->_next;
		newLastNode->_next = nullptr;
		singlyLinkedListNode<T>* oldLastNode = newFirstNode;

		while (oldLastNode->_next != nullptr) {
			oldLastNode = oldLastNode->_next;
		}
		oldLastNode->_next = _first;
		_first = newFirstNode;
	}
	//Сдвиг влево на k позиций.
	void leftShift(int k) {
		if (k < 0) throw std::invalid_argument("k < 0");
		if (k == 0) return;
		if (size() == 0 || size() == 1) return;
		k %= size(); //Определяем число перестановок.

		singlyLinkedListNode<T>* newLastNode = _first;
		for (size_t i{ 0 }; i < k - 1; i++) {
			newLastNode = newLastNode->_next;
		}
		singlyLinkedListNode<T>* newFirstNode = newLastNode->_next;
		newLastNode->_next = nullptr;
		singlyLinkedListNode<T>* oldLastNode = newFirstNode;

		while (oldLastNode->_next != nullptr) {
			oldLastNode = oldLastNode->_next;
		}
		oldLastNode->_next = _first;
		_first = newFirstNode;
	}

	//Возвращает реверсированный исходный линейный односвязный список.
	friend singlyLinkedList<T>* reverse(const singlyLinkedList<T>* const list) {
		if (list->_first == nullptr) return nullptr;

		singlyLinkedList<T>* result = new singlyLinkedList<T>();
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			result->push_front(node->_data);
			node = node->_next;
		}
		return result;
	}
	//Возвращает указатель на первое вхождение в список указанного значения.
	//Если такого вхождения нет, то возвращается nullptr.
	friend singlyLinkedListNode<T>* find(const singlyLinkedList<T>* const list, T value) {
		if (list->_first == nullptr) return nullptr;

		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			if (node->_data == value) return node;
			node = node->_next;
		}
		return nullptr;
	}
	//Обход линейного односвязного списка с выполнением заданного метода.
	friend void for_each(const singlyLinkedList<T>* const list, void(*f)(const T&)) {
		if (list->_first == nullptr) return;

		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			f(node->_data);
			node = node->_next;
		}
	}
	//Вывод в консоль узлов линейного односвязного списка и их связей.
	friend void print(const singlyLinkedList<T>* const list) {
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			std::cout << node->_data << "->";
			node = node->_next;
		}
		std::cout << "||" << std::endl;
	}
	//Возвращает указатель на линейный односвязный список, полученный путём слияние двух исходных линейный односвязных списков.
	friend singlyLinkedList<T>* merge(const singlyLinkedList<T>* const list1, const singlyLinkedList<T>* const list2) {
		singlyLinkedList<T>* result = new singlyLinkedList<T>();
		singlyLinkedListNode<T>* node1 = list1->_first;
		while (node1 != nullptr) {
			result->push_back(node1->_data);
			node1 = node1->_next;
		}
		singlyLinkedListNode<T>* node2 = list2->_first;
		while (node2 != nullptr) {
			result->push_back(node2->_data);
			node2 = node2->_next;
		}
		return result;
	}
	//Возвращает линейный односвязный список без дубликатов.
	friend singlyLinkedList<T>* distinct(const singlyLinkedList<T>* const list) {
		if (list->_first == nullptr) return nullptr;

		std::unordered_set<T> set{ };
		singlyLinkedList<T>* result = new singlyLinkedList<T>();
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			if (set.count(node->_data) == 0) {
				result->push_back(node->_data);
				set.insert(node->_data);
			}
			node = node->_next;
		}
		return result;
	}
	//Возвращает копию линейного односвязного списка.
	friend singlyLinkedList<T>* copy(const singlyLinkedList<T>* const list) {
		if (list->isEmpty()) return new singlyLinkedList<T>{};
		singlyLinkedList<T>* result = new singlyLinkedList<T>{};
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			result->push_back(node->_data);
			node = node->_next;
		}
		return result;
	}
};


#endif __SINGLYLINKEDLIST_
