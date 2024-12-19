#ifndef __SINGLYLINKEDLIST_
#define __SINGLYLINKEDLIST_

#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <functional>



//Класс, реализующий "линейный односвязный список".
template<typename T>
class singlyLinkedList {
/*
Изначально предполагалось, что пользователь сможет вручную взаимодействовать с узлом линейного односвязного списка.
Но из-за высокого риска возникновения утечки памяти было решено сделать данный класс приватным.
*/
private:
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
		//Деструктор.
		~singlyLinkedListNode() = default;
		//Оператор вывода в поток.
		friend std::ostream& operator<<(std::ostream& os, const singlyLinkedListNode<T>& node) {
			os << node._data;
			return os;
		}
	};
private:
	//Указатель на первый элемент списка.
	singlyLinkedListNode<T>* _first;
	//Размер списка.
	size_t _size;
public:
	//Конструктор по умолчанию.
	singlyLinkedList() : _first(nullptr), _size(0) {}
	//Конструктор копии.
	singlyLinkedList(const singlyLinkedList<T>& other) : _size(other.size()), _first(nullptr) {
		size_t count = other.size();
		if (count == 0) return;
		while (count != 0) {
			push_front(other[count - 1]);
			count--;
		}
	}
	//Деструктор.
	~singlyLinkedList() {
		clear();
	}

	//Оператор присваивания.
	singlyLinkedList<T>& operator=(const singlyLinkedList<T>& other) {
		if (this != &other) {
			clear();
			size_t count = other.size();
			if (count != 0) {
				while (count != 0) {
					push_front(other[count - 1]);
					count--;
				}
			}
			return *this;
		}
	}
	//Оператор вывода в поток.
	friend std::ostream& operator<<(std::ostream& os, const singlyLinkedList<T>& list) {
		singlyLinkedListNode<T>* node = list._first;
		while (node != nullptr) {
			os << *node << ' ';
			node = node->_next;
		}
		return os;
	}
	//Оператор доступа к значению узла с заданным индексом.
	T& operator[](size_t index) {
		if (isEmpty()) throw std::invalid_argument("singlyLinkedList is empty");
		if (index >= size()) throw std::invalid_argument("index >= size()");

		singlyLinkedListNode<T>* node = _first;
		while (index != 0) { //Важно избежать проблем с памятью из-за типа index!
			node = node->_next;
			index--;
		}
		return node->_data;
	}
	//Оператор доступа к константному значению узла с заданным индексом.
	const T& operator[](size_t index) const {
		if (isEmpty()) throw std::invalid_argument("singlyLinkedList is empty");
		if (index >= size())throw std::invalid_argument("index >= size()");

		singlyLinkedListNode<T>* node = _first;
		while (index != 0) { //Важно избежать проблем с памятью из-за типа index!
			node = node->_next;
			index--;
		}
		return node->_data;
	}

	//Возвращает реверсированный исходный линейный односвязный список.
	//Если исходный список пустой, то возвращается nullptr.
	friend singlyLinkedList<T>* reverse(const singlyLinkedList<T>* const list) {
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		if (list->isEmpty()) return nullptr;

		singlyLinkedList<T>* result = new singlyLinkedList<T>();
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			result->push_front(node->_data);
			node = node->_next;
		}
		return result;
	}
	//Обход линейного односвязного списка с выполнением заданного метода.
	friend void for_each(const singlyLinkedList<T>* const list, void(*f)(const T&)) {
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		if (f == nullptr) throw std::invalid_argument("f is nullptr");
		if (list->isEmpty()) return;

		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			f(node->_data);
			node = node->_next;
		}
	}
	//Вывод в консоль узлов линейного односвязного списка и их связей.
	friend void print(const singlyLinkedList<T>* const list) {
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			std::cout << node->_data << "->";
			node = node->_next;
		}
		std::cout << "||" << std::endl;
	}
	//Возвращает указатель на линейный односвязный список, полученный путём слияние двух исходных линейный односвязных списков.
	friend singlyLinkedList<T>* merge(const singlyLinkedList<T>* const list1, const singlyLinkedList<T>* const list2) {
		if (list1 == nullptr) throw std::invalid_argument("list1 is nullptr");
		if (list2 == nullptr) throw std::invalid_argument("list2 is nullptr");

		if (list1->isEmpty()) {
			return new singlyLinkedList<T>(*list2);
		}
		if (list2->isEmpty()) {
			return new singlyLinkedList<T>(*list1);
		}
		singlyLinkedList<T>* result = new singlyLinkedList<T>();
		size_t size2 = list2->size();
		do {
			size2--;
			result->push_front((*list2)[size2]);

		} while (size2 != 0);
		size_t size1 = list1->size();
		do {
			size1--;
			result->push_front((*list1)[size1]);

		} while (size1 != 0);
		return result;
	}
	//Возвращает линейный односвязный список без дубликатов.
	//Если исходный список пустой, то возвращается nullptr.
	friend singlyLinkedList<T>* distinct(const singlyLinkedList<T>* const list) {
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		if (list->isEmpty()) return new singlyLinkedList<T>();

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
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		if (list->isEmpty()) return new singlyLinkedList<T>{};

		singlyLinkedList<T>* result = new singlyLinkedList<T>{};
		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			result->push_back(node->_data);
			node = node->_next;
		}
		return result;
	}

	//Возвращает размер списка.
	size_t size() const {
		return _size;
	}
	//Проверяет, содержит ли список данное значение.
	bool contains(const T& value) const {
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode->_data == value) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
	//Проверяет, пустой ли список.
	bool isEmpty() const {
		return _first == nullptr && _size == 0;
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
	//Добавление элемента в начало списка.
	//Возвращает указатель на добавленный элемент.
	void push_front(const T& value) {
		_first = new singlyLinkedListNode<T>{ value, _first };
		_size++;
	}
	//Добавление элемента в конец списка.
	//Возвращает указатель на добавленный элемент.
	void push_back(const T& value) {
		if (_first == nullptr) {
			push_front(value); //_size меняется внутри push_front()
			return;
		}
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode->_next != nullptr) {
			currentNode = currentNode->_next;
		}
		currentNode->_next = new singlyLinkedListNode<T>{ value };
		_size++;
	}
	//Добавление элемента в указанный индекс списка.
	void insert(size_t index, const T& value) {
		if (index == 0) push_front(value);
		if (index == size()) push_back(value);
		else {
			insert_before(getNode(index), value);
		}
	}
	//Удаление элемента списка с указанным индексом.
	void remove(size_t index) {
		if (index >= size()) throw std::invalid_argument("index >= size()");
		if (index == 0) pop_front();
		else if (index == size() - 1) pop_back();
		else {
			size_t currentIndex{};
			singlyLinkedListNode<T>* node = _first;
			while (currentIndex != index - 1) {
				currentIndex++;
				node = node->_next;
			}
			singlyLinkedListNode<T>* temp = node->_next;
			node->_next = node->_next->_next;
			delete temp;
		}
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
	//Сдвиг вправо на k позиций.
	void rightShift(size_t k) {
		if (k == 0) return;
		if (isEmpty() || size() == 1) return;
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
	void leftShift(size_t k) {
		if (k == 0) return;
		if (isEmpty() || size() == 1) return;
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
	//Разбивает список пополам.
	//Первая половина записывается в исходный список, а вторая половина возвращается в виде указателя.
	singlyLinkedList<T>* divideInHalf() {
		return split(_first);
	}
private:
	//Возвращает узел с указанным индексом.
	const singlyLinkedListNode<T>* getNode(size_t index) const {
		if (index >= size()) throw std::invalid_argument("index >= size()");
		singlyLinkedListNode<T>* node = _first;
		while (node != nullptr) {
			if (index == 0) return node;
			node = node->_next;
			index--;
		}
	}
	//Проверяет, содержит ли список указанный узел.
	bool contains(const singlyLinkedListNode<T>* const node) const {
		if (node == nullptr) throw std::invalid_argument("node is nullptr");

		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode == node) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
	//Разбивает часть списка, начинающуюся с указанного узла, на две половины.
	//Первая половина записывается в исходный список, а вторая половина возвращается в виде указателя.
	singlyLinkedList<T>* split(const singlyLinkedListNode<T>* const node) {
		if (node == nullptr) throw std::invalid_argument("node is nullptr");

		//Объявляем два указателя: один быстрее другого в два раза.
		singlyLinkedListNode<T>* slow = const_cast<singlyLinkedListNode<T>*>(node); //В дальнейшем slow станет последним узлом первой половины списка.
		singlyLinkedListNode<T>* fast = const_cast<singlyLinkedListNode<T>*>(node); //В дальнейшем fast станет последним узлом второй половины списка.
		while (fast->_next != nullptr && fast->_next->_next != nullptr) { //Пока не дошли конца списка, в том числе его второй половины.
			slow = slow->_next;
			fast = fast->_next->_next;
		}
		singlyLinkedListNode<T>* secondHalfPart = slow->_next; //Указатель на вторую половину списка.
		slow->_next = nullptr;
		singlyLinkedList<T>* result = new singlyLinkedList<T>{};
		result->_first = secondHalfPart;
		//Вычисление количества узлов в первой и во второй половинах после разбиения.
		int count{ 0 }; //Число узлов во второй половине списка.
		while (secondHalfPart != nullptr) {
			count++;
			secondHalfPart = secondHalfPart->_next;
		}
		result->_size = count;
		this->_size -= count;
		return result;
	}
	//Возвращает указатель на первое вхождение в список указанного значения.
	//Если такого вхождения нет, то возвращается nullptr.
	friend singlyLinkedListNode<T>* find(const singlyLinkedList<T>* const list, const T& value) {
		if (list == nullptr) throw std::invalid_argument("list is nullptr");
		if (list->_first == nullptr) return nullptr;

		singlyLinkedListNode<T>* node = list->_first;
		while (node != nullptr) {
			if (node->_data == value) return node;
			node = node->_next;
		}
		return nullptr;
	}
	//Вставка элемента после указанного узла списка.
	//Возвращает указатель на добавленный элемент.
	//Нет проверки на наличие узла в списке!
	const singlyLinkedListNode<T>* insert_after(singlyLinkedListNode<T>* const node, const T& value) {
		if (node == nullptr) throw std::invalid_argument("node is nullptr");
		if (_first == nullptr) return nullptr;

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, node->_next };
		node->_next = newNode;
		_size++;
		return newNode;
	}
	//Вставка элемента перед указанным узлом списка.
	//Возвращает указатель на добавленный элемент.
	//Нет проверки на наличие узла в списке!
	const singlyLinkedListNode<T>* insert_before(const singlyLinkedListNode<T>* const node, const T& value) {
		if (node == nullptr) throw std::invalid_argument("node is nullptr");
		if (_first == nullptr) return nullptr;

		if (_first == node) {
			push_front(value); //_size меняется внутри метода push_front()
			return _first;
		}

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
};

#endif __SINGLYLINKEDLIST_
