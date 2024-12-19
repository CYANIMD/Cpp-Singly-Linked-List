# О проекте.
Cpp-Singly-Linked-List - это проект, представляющий собой реализацию линейного односвязного спискана C++ с широким функционалом.

# Временная и пространственная асимптотическая сложность алгоритмов.
Обозначим как 
n\m - размер линейного односвязного списка;

|Метод|Временная асимптотическая сложность|Пространственная асимптотическая сложность|
:----------|----------|-----------:
|singlyLinkedList()|O(1)|O(1)|
|singlyLinkedList(const singlyLinkedList<T>&)|O(n^2)|O(n)|
|~singlyLinkedList()|O(n)|O(1)|
|operator=(singlyLinkedList<T>&, const singlyLinkedList<T>&)|O(n^2)|O(n)|
|operator<<(std::ostream&, const singlyLinkedList<T>&)|O(n)|O(1)|
|operator[](size_t)|O(n)|O(1)|
|size()|O(1)|O(1)|
|hasValue(const T&)|O(n)|O(1)|
|isEmpty()|O(1)|O(1)|
|clear()|O(n)|O(1)|
|push_front(const T&)|O(1)|O(1)|
|push_back(const T&)|O(n)|O(1)|
|pop_front()|O(1)|O(1)|
|pop_back()|O(n)|O(1)|
|rightLeft(size_t)|O(n)|O(1)|
|rightShift(size_t)|O(n)|O(1)|
|divideInHalf(const singlyLinkedListNode<T>*)|O(n)|O(n)|
|reverse(const singlyLinkedListNode<T>* const)|O(n)|O(n)|
|for_each(const singlyLinkedListNode<T>* const, void(\*f)(const T&))|O(n)|O(1)|
|print(const singlyLinkedListNode<T>* const)|O(n)|O(1)|
|merge(const singlyLinkedListNode<T>* const, const singlyLinkedListNode<T>* const)|O(n^2+m^2)|O(n^2+m^2)|
|distinct(const singlyLinkedListNode<T>* const)|O(n^2)|O(n)|
|copy(const singlyLinkedListNode<T>* const)|O(n^2)|O(n)|


