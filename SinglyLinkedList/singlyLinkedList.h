#ifndef __SINGLYLINKEDLIST_
#define __SINGLYLINKEDLIST_

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
		while (_first != nullptr) { //Проход по всем узлам и освобождение ресурсов, затрачиваемых на них.
			singlyLinkedListNode<T>* node = _first;
			_first = _first->_next;
			delete node;
		}
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
		if (_first != nullptr) {
			singlyLinkedListNode<T>* node = _first;
			_first = _first->_next;
			delete node;
		}
	}
	//Удаление последнего элемента списка.
	void remove_last() {
		if (_first != nullptr) {
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
	singlyLinkedListNode<T>* insert_after(singlyLinkedListNode<T>* node, const T& value) {
		if (node == nullptr || _first == nullptr) return nullptr;
		if (!hasNode(node)) return nullptr;

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, node->_next };
		node->_next = newNode;
		return newNode;
	}
	//Вставка элемента перед указанным узлом.
	//Возвращает указатель на добавленный элемент.
	//Если указанного узла нет в списке, то возвращается nullptr.
	singlyLinkedListNode<T>* insert_before(singlyLinkedListNode<T>* node, T value) {
		if (node == nullptr || _first == nullptr) return nullptr;
		if (!hasNode(node)) return nullptr;

		if (_first == node) return push_front(value);

		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr && currentNode->_next != node) {
			currentNode = currentNode->_next;
		}

		if (currentNode == nullptr) return nullptr;

		singlyLinkedListNode<T>* newNode = new singlyLinkedListNode<T>{ value, node };
		currentNode->_next = newNode;
		return newNode;
	}
	//Проверяет, содержит ли список данный узел.
	bool hasNode(singlyLinkedListNode<T>* node) {
		singlyLinkedListNode<T>* currentNode = _first;
		while (currentNode != nullptr) {
			if (currentNode == node) return true;
			currentNode = currentNode->_next;
		}
		return false;
	}
};


#endif __SINGLYLINKEDLIST_
