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


#endif __SINGLYLINKEDLIST_
