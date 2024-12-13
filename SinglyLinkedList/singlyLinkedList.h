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
	void push_front(const T& value) {
		_first = new singlyLinkedListNode<T>{ value, _first };
	}
	//Добавление элемента в конец списка.
	void push_back(const T& value) {
		if (_first == nullptr) {
			_first = new singlyLinkedListNode<T>{ value };
		}
		else {
			singlyLinkedListNode<T>* currentNode = _first;
			while (currentNode->_next != nullptr) {
				currentNode = currentNode->_next;
			}
			currentNode->_next = new singlyLinkedListNode<T>{ value };
		}
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
};


#endif __SINGLYLINKEDLIST_
