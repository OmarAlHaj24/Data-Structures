#include "MyList.h"
#include<iostream>
using namespace std;

template<class T>
ListNode<T>::ListNode() : value(0), next(nullptr), prev(nullptr) {}

template<class T>
ListNode<T>::ListNode(T data) : value(data), next(nullptr), prev(nullptr) {}

template<class T>
ListNode<T>* ListNode<T>::getNext() {
	return next;
}

template<class T>
ListNode<T>* ListNode<T>::getPrev() {
	return prev;
}

template<class T>
void ListNode<T>::setNext(ListNode<T>* nt) {
	next = nt;
}

template<class T>
void ListNode<T>::setPrev(ListNode<T>* previous) {
	prev = previous;
}

template<class T>
T& ListNode<T>::getValue() {
	return value;
}

template<class T>
void ListNode<T>::setValue(T val) {
	value = val;
}


template<class T>
MyList<T>::MyList() : size(0) {
	head = tail = new ListNode<T>();
	dummy = new ListNode<T>();
	tail->setNext(dummy);
	dummy->setPrev(tail);
}

template<class T>
MyList<T>::MyList(T data, int init_size) : size(init_size) {
	dummy = new ListNode<T>();
	if (size > 0) {
		head = tail = new ListNode<T>(data);
		tail->setNext(dummy);
		dummy->setPrev(tail);
		for (int i = 0; i < size - 1; i++)
		{
			if (head->getNext() == nullptr)
			{
				ListNode<T>* temp = new ListNode<T>(data);
				head->setNext(temp);
				temp->setPrev(head);
				temp->setNext(tail);
				tail->setPrev(temp);
			}
			else {
				ListNode<T>* temp = new ListNode<T>(data);
				temp->setPrev(tail);
				tail->setNext(temp);
				tail = temp;
				tail->setNext(dummy);
				dummy->setPrev(tail);
			}
		}
	}
	else {
		head = tail = new ListNode<T>();
		tail->setNext(dummy);
		dummy->setPrev(tail);
	}

}

template<class T>
MyList<T>::~MyList() {
	for (int i = 0; i < size; i++) {
		ListNode<T>* temp = head->getNext();
		delete head;
		head = temp;
	}
	delete dummy, tail;
	size = 0;
}

template<class T>
int MyList<T>::getSize() const {
	return size;
}


template<class T>
MyList<T>::iterator::iterator() :node(nullptr) {}

template<class T>
MyList<T>::iterator::iterator(ListNode<T>* newNode) : node(newNode) {}

template<class T>
T& MyList<T>::iterator::operator*() const {
	return node->getValue();
}

template<class T>
void MyList<T>::iterator::operator++() {
	if (this->node->getNext() == nullptr)
		throw"End of the List";
	node = node->getNext();
}

template<class T>
void MyList<T>::iterator::operator--() {
	if (this->node->getPrev() == nullptr)
		throw"We are already at the beginning of the list";
	node = node->getPrev();
}

template<class T>
bool MyList<T>::iterator::operator == (const iterator& anotherITR) {
	return this->node == anotherITR.node;
}

template<class T>
bool MyList<T>::iterator::operator != (const iterator& anotherITR) {
	return this->node != anotherITR.node;
}


template<class T>
void MyList<T>::insert(T value, iterator position) {
	ListNode<T>* temp = head;

	while (temp != nullptr) {
		if (temp == position.node) {
			ListNode<T>* t = new ListNode<T>(value);
			t->setPrev(temp->getPrev());
			t->setNext(temp);
			if (temp != head)
				temp->getPrev()->setNext(t);
			temp->setPrev(t);


			if (temp == head) {
				head = t;
			}
			if (temp == tail) {
				tail = t;
				dummy->setPrev(tail);
			}
			if (temp == dummy) {
				tail = t;
				dummy->setPrev(tail);
				tail->setNext(dummy);
			}
			break;
		}
		temp = temp->getNext();
	}
}

template<class T>
MyList<T>& MyList<T>::operator = (const MyList<T>& another_list) {
	head = tail = new ListNode<T>;
	dummy = new ListNode<T>;
	dummy->setPrev(tail);
	tail->setNext(dummy);
	if (another_list.head == nullptr) {
		return *this;
	}
	size = another_list.size;
	ListNode<T>* another = another_list.head;
	ListNode<T>* list = head;
	while (true) {
		if (another == another_list.head) {
			list->setValue(another->getValue());
			another = another->getNext();
		}
		else if (another == another_list.tail) {
			ListNode<T>* t = new ListNode<T>(another->getValue());
			list->setNext(t);
			tail = t;
			tail->setPrev(list);
			tail->setNext(this->dummy);
			dummy->setPrev(this->tail);
			another = another->getNext();
			return *this;
		}
		else
		{
			ListNode<T>* t = new ListNode<T>(another->getValue());
			list->setNext(t);
			list->getNext()->setPrev(list);
			list = list->getNext();
			another = another->getNext();
		}
	}

}