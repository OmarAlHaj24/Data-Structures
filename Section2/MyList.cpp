#include "MyList.h"

template<class T>
ListNode<T>::ListNode() : value(0), next(nullptr), prev(nullptr) {}

template<class T>
ListNode<T>::ListNode(T data) : value(data), next(nullptr), prev(nullptr) {}

template<class T>
MyList<T>::MyList() : size(1) {
	head = tail = new ListNode<T>()
}

template<class T>
MyList<T>::MyList(T data, int init_size) : size(init_size) {
	head = tail = new ListNode<T>(data);
	for (int i = 0; i < size - 1; i++)
	{
		if (head->next == nullptr)
		{
			ListNode* temp = new ListNode();
			head->next = temp;
			temp->prev = head;
			temp->next = tail;
			tail->prev = temp;
		}
		else {
			ListNode* temp = tail->prev;
			temp->next = new ListNode<T>();
			(temp->next)->next = tail;
			tail->prev = temp->next;
		}
	}
}

template<class T>
MyList<T>::~MyList() {

}

template<class T>
int MyList<T>::size()const {
	return size;
}


template<class T>
MyList<T>::iterator::iterator() :node(nullptr) {}

template<class T>
MyList<T>::iterator::iterator(ListNode<T>* newNode) : node(newNode) {}

template<class T>
T& MyList<T>::iterator::operator*() const {
	return node->next->value;
}

template<class T>
void MyList<T>::iterator::operator++() {
	node = node->next;
}

template<class T>
void MyList<T>::iterator::operator--() {
	node = node->prev;
}

template<class T>
bool MyList<T>::iterator::operator == (const iterator& anotherITR) {
	return this->node == anotherITR.node;
}

template<class T>
bool MyList<T>::iterator::operator == (const iterator& anotherITR) {
	return this->node != anotherITR.node;
}


template<class T>
void MyList<T>::insert(T value, iterator position) {

}

template<class T>
MyList<T>& MyList<T>::operator = (MyList<T> another_list) {

}