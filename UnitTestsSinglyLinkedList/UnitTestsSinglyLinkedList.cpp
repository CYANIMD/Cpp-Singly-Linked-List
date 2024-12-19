#include "pch.h"
#include "CppUnitTest.h"
#include <initializer_list>
#include "../SinglyLinkedList/singlyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsSinglyLinkedList
{
	TEST_CLASS(UnitTestsSinglyLinkedList)
	{
	public:
		TEST_METHOD(TEST_CONSTRUCTOR_AND_CONSTRUCTOR_LIST)
		{
			singlyLinkedList<int> emptyIntList{ };
			singlyLinkedList<int> intList1 {-2};
			singlyLinkedList<int> intList2{ -2, -1 };
			singlyLinkedList<int> intList3{ -2, -1, 0 };
			singlyLinkedList<int> intList4{ -2, -1, 0, 1 };
			singlyLinkedList<int> intList5{ -2, -1, 0, 1, 2 };

			Assert::IsTrue(emptyIntList == std::initializer_list<int>{});
			Assert::IsTrue(intList1 == std::initializer_list<int>{-2});
			Assert::IsTrue(intList2 == std::initializer_list<int>{-2, -1});
			Assert::IsTrue(intList3 == std::initializer_list<int>{-2, -1, 0});
			Assert::IsTrue(intList4 == std::initializer_list<int>{-2, -1, 0, 1 });
			Assert::IsTrue(intList5 == std::initializer_list<int>{-2, -1, 0, 1, 2});

			singlyLinkedList<double> emptyDoubleList{ };
			singlyLinkedList<double> doubleList1{ -6.22 };
			singlyLinkedList<double> doubleList2{ -6.22, -1.65 };
			singlyLinkedList<double> doubleList3{ -6.22, -1.65, 0 };
			singlyLinkedList<double> doubleList4{ -6.22, -1.65, 0, 2.72 };
			singlyLinkedList<double> doubleList5{ -6.22, -1.65, 0, 2.72, 3.14 };

			Assert::IsTrue(emptyDoubleList == std::initializer_list<double>{});
			Assert::IsTrue(doubleList1 == std::initializer_list<double>{-6.22});
			Assert::IsTrue(doubleList2 == std::initializer_list<double>{-6.22, -1.65});
			Assert::IsTrue(doubleList3 == std::initializer_list<double>{-6.22, -1.65, 0});
			Assert::IsTrue(doubleList4 == std::initializer_list<double>{-6.22, -1.65, 0, 2.72 });
			Assert::IsTrue(doubleList5 == std::initializer_list<double>{-6.22, -1.65, 0, 2.72, 3.14});
		}
		TEST_METHOD(TEST_SIZE) {
			singlyLinkedList<int> emptyIntList{ };
			singlyLinkedList<int> intList1{ -2 };
			singlyLinkedList<int> intList2{ -2, -1 };
			singlyLinkedList<int> intList3{ -2, -1, 0 };
			singlyLinkedList<int> intList4{ -2, -1, 0, 1 };
			singlyLinkedList<int> intList5{ -2, -1, 0, 1, 2 };

			Assert::IsTrue(emptyIntList.size() == 0);
			Assert::IsTrue(intList1.size() == 1);
			Assert::IsTrue(intList2.size() == 2);
			Assert::IsTrue(intList3.size() == 3);
			Assert::IsTrue(intList4.size() == 4);
			Assert::IsTrue(intList5.size() == 5);

			singlyLinkedList<double> emptyDoubleList{ };
			singlyLinkedList<double> doubleList1{ -6.22 };
			singlyLinkedList<double> doubleList2{ -6.22, -1.65 };
			singlyLinkedList<double> doubleList3{ -6.22, -1.65, 0 };
			singlyLinkedList<double> doubleList4{ -6.22, -1.65, 0, 2.72 };
			singlyLinkedList<double> doubleList5{ -6.22, -1.65, 0, 2.72, 3.14 };

			Assert::IsTrue(emptyDoubleList.size() == 0);
			Assert::IsTrue(doubleList1.size() == 1);
			Assert::IsTrue(doubleList2.size() == 2);
			Assert::IsTrue(doubleList3.size() == 3);
			Assert::IsTrue(doubleList4.size() == 4);
			Assert::IsTrue(doubleList5.size() == 5);
		}
		TEST_METHOD(TEST_IS_EMPTY) {
			singlyLinkedList<int> emptyIntList{ };
			singlyLinkedList<int> intList1{ -2 };
			singlyLinkedList<int> intList2{ -2, -1 };
			singlyLinkedList<int> intList3{ -2, -1, 0 };
			singlyLinkedList<int> intList4{ -2, -1, 0, 1 };
			singlyLinkedList<int> intList5{ -2, -1, 0, 1, 2 };

			Assert::IsTrue(emptyIntList.isEmpty());
			Assert::IsFalse(intList1.isEmpty());
			Assert::IsFalse(intList2.isEmpty());
			Assert::IsFalse(intList3.isEmpty());
			Assert::IsFalse(intList4.isEmpty());
			Assert::IsFalse(intList5.isEmpty());

			singlyLinkedList<double> emptyDoubleList{ };
			singlyLinkedList<double> doubleList1{ -6.22 };
			singlyLinkedList<double> doubleList2{ -6.22, -1.65 };
			singlyLinkedList<double> doubleList3{ -6.22, -1.65, 0 };
			singlyLinkedList<double> doubleList4{ -6.22, -1.65, 0, 2.72 };
			singlyLinkedList<double> doubleList5{ -6.22, -1.65, 0, 2.72, 3.14 };

			Assert::IsTrue(emptyDoubleList.isEmpty());
			Assert::IsFalse(doubleList1.isEmpty());
			Assert::IsFalse(doubleList2.isEmpty());
			Assert::IsFalse(doubleList3.isEmpty());
			Assert::IsFalse(doubleList4.isEmpty());
			Assert::IsFalse(doubleList5.isEmpty());
		}
		TEST_METHOD(TEST_CONTAINS) {
			singlyLinkedList<int> emptyIntList{ };
			singlyLinkedList<int> intList1{ -2 };
			singlyLinkedList<int> intList2{ -2, -1 };
			singlyLinkedList<int> intList3{ -2, -1, 0 };
			singlyLinkedList<int> intList4{ -2, -1, 0, 1 };
			singlyLinkedList<int> intList5{ -2, -1, 0, 1, 2 };

			Assert::IsFalse(emptyIntList.contains(0));
			Assert::IsFalse(emptyIntList.contains(-5));
			Assert::IsFalse(emptyIntList.contains(5));

			Assert::IsFalse(intList1.contains(0));
			Assert::IsFalse(intList1.contains(-1));
			Assert::IsFalse(intList1.contains(3));
			Assert::IsTrue(intList1.contains(-2));

			Assert::IsFalse(intList2.contains(0));
			Assert::IsFalse(intList2.contains(-3));
			Assert::IsFalse(intList2.contains(3));
			Assert::IsTrue(intList2.contains(-2));
			Assert::IsTrue(intList2.contains(-1));

			Assert::IsFalse(intList3.contains(4));
			Assert::IsFalse(intList3.contains(-6));
			Assert::IsFalse(intList3.contains(3));
			Assert::IsTrue(intList3.contains(-2));
			Assert::IsTrue(intList3.contains(-1));
			Assert::IsTrue(intList3.contains(0));

			Assert::IsFalse(intList4.contains(-8));
			Assert::IsFalse(intList4.contains(8));
			Assert::IsFalse(intList4.contains(4));
			Assert::IsTrue(intList4.contains(-2));
			Assert::IsTrue(intList4.contains(-1));
			Assert::IsTrue(intList4.contains(0));
			Assert::IsTrue(intList4.contains(1));

			Assert::IsFalse(intList5.contains(-6));
			Assert::IsFalse(intList5.contains(9));
			Assert::IsFalse(intList5.contains(3));
			Assert::IsTrue(intList5.contains(-2));
			Assert::IsTrue(intList5.contains(-1));
			Assert::IsTrue(intList5.contains(0));
			Assert::IsTrue(intList5.contains(1));
			Assert::IsTrue(intList5.contains(2));

			singlyLinkedList<double> emptyDoubleList{ };
			singlyLinkedList<double> doubleList1{ -6.22 };
			singlyLinkedList<double> doubleList2{ -6.22, -1.65 };
			singlyLinkedList<double> doubleList3{ -6.22, -1.65, 0 };
			singlyLinkedList<double> doubleList4{ -6.22, -1.65, 0, 2.72 };
			singlyLinkedList<double> doubleList5{ -6.22, -1.65, 0, 2.72, 3.14 };

			Assert::IsFalse(emptyDoubleList.contains(0.0));
			Assert::IsFalse(emptyDoubleList.contains(3.05));
			Assert::IsFalse(emptyDoubleList.contains(-1.98));

			Assert::IsFalse(doubleList1.contains(2));
			Assert::IsFalse(doubleList1.contains(-5.6));
			Assert::IsFalse(doubleList1.contains(1.65));
			Assert::IsTrue(doubleList1.contains(-6.22));

			Assert::IsFalse(doubleList2.contains(1.87));
			Assert::IsFalse(doubleList2.contains(-9.12));
			Assert::IsFalse(doubleList2.contains(9));
			Assert::IsTrue(doubleList2.contains(-6.22));
			Assert::IsTrue(doubleList2.contains(-1.65));

			Assert::IsFalse(doubleList3.contains(4));
			Assert::IsFalse(doubleList3.contains(2.15));
			Assert::IsFalse(doubleList3.contains(6.09));
			Assert::IsTrue(doubleList3.contains(-6.22));
			Assert::IsTrue(doubleList3.contains(-1.65));
			Assert::IsTrue(doubleList3.contains(0.0));

			Assert::IsFalse(doubleList4.contains(6.22));
			Assert::IsFalse(doubleList4.contains(-9.1));
			Assert::IsFalse(doubleList4.contains(5));
			Assert::IsTrue(doubleList4.contains(-6.22));
			Assert::IsTrue(doubleList4.contains(-1.65));
			Assert::IsTrue(doubleList4.contains(0.0));
			Assert::IsTrue(doubleList4.contains(2.72));

			Assert::IsFalse(doubleList5.contains(-2));
			Assert::IsFalse(doubleList5.contains(9.82));
			Assert::IsFalse(doubleList5.contains(-3.14));
			Assert::IsTrue(doubleList5.contains(-6.22));
			Assert::IsTrue(doubleList5.contains(-1.65));
			Assert::IsTrue(doubleList5.contains(0.0));
			Assert::IsTrue(doubleList5.contains(2.72));
			Assert::IsTrue(doubleList5.contains(3.14));
		}
		TEST_METHOD(TEST_TOP) {
			singlyLinkedList<int> IntList{ };
			Assert::ExpectException<std::invalid_argument>([&IntList]() {IntList.front(); });

			IntList = { 2 };
			Assert::AreEqual(IntList.front(), 2);
			IntList = { 0 };
			Assert::AreEqual(IntList.front(), 0);
			IntList = { -2 };
			Assert::AreEqual(IntList.front(), -2);

			IntList = { 1, 3 };
			Assert::AreEqual(IntList.front(), 1);
			IntList = { -2, 0 };
			Assert::AreEqual(IntList.front(), -2);
			IntList = { 0, -1 };
			Assert::AreEqual(IntList.front(), 0);

			IntList = { -2, 1, 3 };
			Assert::AreEqual(IntList.front(), -2);
			IntList = { 5, -1, 0 };
			Assert::AreEqual(IntList.front(), 5);
			IntList = { 0, -4, 1 };
			Assert::AreEqual(IntList.front(), 0);

			IntList = { -8, -2, 0, 1 };
			Assert::AreEqual(IntList.front(), -8);
			IntList = { 0, -6, 1, 2 };
			Assert::AreEqual(IntList.front(), 0);
			IntList = { 3, -3, 0, 9 };
			Assert::AreEqual(IntList.front(), 3);

			IntList = { 4, -8, 9, 0, -3 };
			Assert::AreEqual(IntList.front(), 4);
			IntList = { -1, 1, 2, 1, 3 };
			Assert::AreEqual(IntList.front(), -1);
			IntList = { 6, 0, -1, 9, 7 };
			Assert::AreEqual(IntList.front(), 6);

			singlyLinkedList<double> doubleList{ };
			Assert::ExpectException<std::invalid_argument>([&doubleList]() {doubleList.front(); });

			doubleList = { 3.14 };
			Assert::AreEqual(doubleList.front(), 3.14);
			doubleList = { 1.65 };
			Assert::AreEqual(doubleList.front(), 1.65);
			doubleList = { -0.5 };
			Assert::AreEqual(doubleList.front(), -0.5);

			doubleList = { -1.76, 2.72 };
			Assert::AreEqual(doubleList.front(), -1.76);
			doubleList = { 0, 6.22 };
			Assert::AreEqual(doubleList.front(), 0.0);
			doubleList = { 8.31, 3.14 };
			Assert::AreEqual(doubleList.front(), 8.31);

			doubleList = { -3.21, 0, -6.54321 };
			Assert::AreEqual(doubleList.front(), -3.21);
			doubleList = { 5.401, -3.12, 9.87 };
			Assert::AreEqual(doubleList.front(), 5.401);
			doubleList = { 22.4, 67.89, -1.5 };
			Assert::AreEqual(doubleList.front(), 22.4);

			doubleList = { -5.05, -3.2, 0, 1.987 };
			Assert::AreEqual(doubleList.front(), -5.05);
			doubleList = { 1.2345, -5.4321, 0.123, 3.210 };
			Assert::AreEqual(doubleList.front(), 1.2345);
			doubleList = { 0.05, 2.5, -2.5 };
			Assert::AreEqual(doubleList.front(), 0.05);

			doubleList = { 6.789, -3.45, 5.22, 0, -1.2 };
			Assert::AreEqual(doubleList.front(), 6.789);
			doubleList = { -1.12, -5.67, 0.5, -0.5, 1 };
			Assert::AreEqual(doubleList.front(), -1.12);
			doubleList = { 0.0005 , -3.333, 9.56, 5.43, -9.43 };
			Assert::AreEqual(doubleList.front(), 0.0005);
		}
		TEST_METHOD(TEST_FRONT) {
			singlyLinkedList<int> IntList{ };
			Assert::ExpectException<std::invalid_argument>([&IntList]() {IntList.top(); });

			IntList = { 2 };
			Assert::AreEqual(IntList.top(), 2);
			IntList = { 0 };
			Assert::AreEqual(IntList.top(), 0);
			IntList = { -2 };
			Assert::AreEqual(IntList.top(), -2);

			IntList = { 1, 3 };
			Assert::AreEqual(IntList.top(), 3);
			IntList = { -2, 0 };
			Assert::AreEqual(IntList.top(), 0);
			IntList = { 0, -1 };
			Assert::AreEqual(IntList.top(), -1);

			IntList = { -2, 1, 3 };
			Assert::AreEqual(IntList.top(), 3);
			IntList = { 5, -1, 0 };
			Assert::AreEqual(IntList.top(), 0);
			IntList = { 0, -4, 1 };
			Assert::AreEqual(IntList.top(), 1);

			IntList = { -8, -2, 0, 1 };
			Assert::AreEqual(IntList.top(), 1);
			IntList = { 0, -6, 1, 2 };
			Assert::AreEqual(IntList.top(), 2);
			IntList = { 3, -3, 0, 9 };
			Assert::AreEqual(IntList.top(), 9);

			IntList = { 4, -8, 9, 0, -3 };
			Assert::AreEqual(IntList.top(), -3);
			IntList = { -1, 1, 2, 1, 3 };
			Assert::AreEqual(IntList.top(), 3);
			IntList = { 6, 0, -1, 9, 7 };
			Assert::AreEqual(IntList.top(), 7);

			singlyLinkedList<double> doubleList{ };
			Assert::ExpectException<std::invalid_argument>([&doubleList]() {doubleList.top(); });

			doubleList = { 3.14 };
			Assert::AreEqual(doubleList.top(), 3.14);
			doubleList = { 1.65 };
			Assert::AreEqual(doubleList.top(), 1.65);
			doubleList = { -0.5 };
			Assert::AreEqual(doubleList.top(), -0.5);

			doubleList = { -1.76, 2.72 };
			Assert::AreEqual(doubleList.top(), 2.72);
			doubleList = { 0, 6.22 };
			Assert::AreEqual(doubleList.top(), 6.22);
			doubleList = { 8.31, 3.14 };
			Assert::AreEqual(doubleList.top(), 3.14);

			doubleList = { -3.21, 0, -6.54321 };
			Assert::AreEqual(doubleList.top(), -6.54321);
			doubleList = { 5.401, -3.12, 9.87 };
			Assert::AreEqual(doubleList.top(), 9.87);
			doubleList = { 22.4, 67.89, -1.5 };
			Assert::AreEqual(doubleList.top(), -1.5);

			doubleList = { -5.05, -3.2, 0, 1.987 };
			Assert::AreEqual(doubleList.top(), 1.987);
			doubleList = { 1.2345, -5.4321, 0.123, 3.210 };
			Assert::AreEqual(doubleList.top(), 3.210);
			doubleList = { 0.05, 2.5, -2.5 };
			Assert::AreEqual(doubleList.top(), -2.5);

			doubleList = { 6.789, -3.45, 5.22, 0, -1.2 };
			Assert::AreEqual(doubleList.top(), -1.2);
			doubleList = { -1.12, -5.67, 0.5, -0.5, 1 };
			Assert::AreEqual(doubleList.top(), 1.0);
			doubleList = { 0.0005 , -3.333, 9.56, 5.43, -9.43 };
			Assert::AreEqual(doubleList.top(), -9.43);
		}
		TEST_METHOD(TEST_CLEAR) {
			singlyLinkedList<int> intList{};
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = {-1};
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 0 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 1 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 1, 1 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -1, -2 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 0, 2 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -1, 0, 1 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -2, -1, 1 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 1, 1, 2 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -3, -2, -1, 0 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -1, 0, 1, 2 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 1, 1, 2, 3 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -4, -3, -2, -1, 0 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { -2, -1, 0, 1, 2 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());
			intList = { 1, 1, 2, 3, 5 };
			intList.clear();
			Assert::IsTrue(intList == std::initializer_list<int>());

			singlyLinkedList<double> doubleList{};
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = {3.14};
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -2.05 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 0 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 1.65, 1.76 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -2.5, -0.5 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = {-0.3, 0.93 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 0, 1.23, 4.56 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -5.43, -2.10, 1.05 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -5.55, -3.33, -7.77 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -6.65, -8.54, -4.43, -6.5 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 2.9, -1.5, 3.9, -2.5 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 9.1, 3.56, 7.09, 5 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { 1.65, 1.78, 2.72, 3.14, 6.28 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -2.3, -2.09, -1.89, -1.56, -0.49 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
			doubleList = { -0.32, -0.56, 0, 1.89, 9.32 };
			doubleList.clear();
			Assert::IsTrue(doubleList == std::initializer_list<double>());
		}
	};
}