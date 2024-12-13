#ifndef __SINGLYLINKEDLIST_
#define __SINGLYLINKEDLIST_

//�����, ����������� "���� ��������� ������������ ������".
template<typename T>
class singlyLinkedListNode {
public:
	//��������, �������� � ����.
	T _data;
	//��������� �� ��������� ����.
	singlyLinkedListNode<T>* _next;
	//����������� �� ���������.
	singlyLinkedListNode() : _data(T()), _next(nullptr) {}
	//����������� � �������� �����������.
	singlyLinkedListNode(const T& data) : _data(data), _next(nullptr) {}
	//����������� � �������� �����������.
	singlyLinkedListNode(T data, singlyLinkedListNode<T>* next) : _data(data), _next(next) {}

	//���������� �� �����.
};


#endif __SINGLYLINKEDLIST_
