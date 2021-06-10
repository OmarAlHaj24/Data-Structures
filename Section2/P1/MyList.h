/*
* @author Mirette Amin Danial	20190570 S10
* @author Rana Ihab Ahmed Fahmy 20190207 S10
* Created on 2/6/2021
*/

#pragma once
#ifndef MYLIST_H
#define MYLIST_H

template<class T>
class ListNode {
private:
	T value;
	ListNode<T>* next;
	ListNode<T>* prev;
public:
	ListNode();
	ListNode(T data);
	T& getValue();
	void setValue(T val);
	ListNode* getNext();
	ListNode* getPrev();
	void setNext(ListNode<T>* nt);
	void setPrev(ListNode<T>* previous);
};

template<class T>
class MyList {

private:
	ListNode<T>* head, * tail, * dummyNode;
	int size;
public:
	MyList();
	MyList(T data, int init_size);
	~MyList();
	int getSize() const;
	MyList<T>& operator = (const MyList<T>& another_list);

	class iterator {
	private:
		ListNode<T>* node;
		iterator();
		iterator(ListNode<T>* newNode);  //All node pointers in the list class of the iterator class should be private and inaccessible from outside of the class.
	public:
		friend class MyList;
		T& operator*() const;
		void operator++();
		void operator -- ();
		bool operator == (const iterator& anotherITR);
		bool operator != (const iterator& anotherITR);
	};

	iterator begin() const {
		return iterator(head);
	}

	iterator end() const {
		return iterator(dummyNode);
	}

	iterator insert(T value, iterator position) {
		if (size == 0) {
			head->setValue(value);
			tail = head;
			tail->setNext(dummyNode);
			dummyNode->setPrev(tail);
		}


		else if (position.node == head) {
			//temp->setNext(head);
			if (size != 0) {
				ListNode<T>* temp = new ListNode<T>(value);
				temp->setNext(position.node);
				head->setPrev(temp);
				head = temp;
				--position;
			}
		}
		else {
			ListNode<T>* temp = new ListNode<T>(value);
			position.node->getPrev()->setNext(temp);
			temp->setPrev(position.node->getPrev());
			temp->setNext(position.node);
			position.node->setPrev(temp);
			if (position.node == tail) {
				tail = position.node;
				tail->setNext(dummyNode);
				dummyNode->setPrev(tail);
			}
			else if (position.node == dummyNode) {
				tail->setNext(temp);
				tail = temp;

				dummyNode->setPrev(tail);
				tail->setNext(dummyNode);
			}
			--position;
		}
		size++;
		return position;
	}


	iterator erase(iterator position) {
		try{
			if(position.node == dummyNode)
				throw"Position not found";
			ListNode<T>* temp = position.node;
			temp->getNext()->setPrev(temp->getPrev());
			if (head != temp)
				temp->getPrev()->setNext(temp->getNext());
			position = temp->getNext();
			if (temp == head)
				head = temp->getNext();
			else if (temp == tail) {
				tail = temp->getPrev();
				tail->setNext(dummyNode);
				dummyNode->setPrev(tail);
			}
			delete temp;
			size--;
			return position;

		}
		catch (const char* arr) {
			std::cout << arr << std::endl;

		}
		
	}

};

template<class T>
ListNode<T>::ListNode() : next(nullptr), prev(nullptr) {}

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
	dummyNode = new ListNode<T>();
	tail->setNext(dummyNode);
	dummyNode->setPrev(tail);
}

template<class T>
MyList<T>::MyList(T data, int init_size) : size(init_size) {
	dummyNode = new ListNode<T>();
	if (size > 0) {
		head = tail = new ListNode<T>(data);
		tail->setNext(dummyNode);
		dummyNode->setPrev(tail);
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
				tail->setNext(dummyNode);
				dummyNode->setPrev(tail);
			}
		}
	}
	else {
		head = tail = new ListNode<T>();
		tail->setNext(dummyNode);
		dummyNode->setPrev(tail);
	}

}

template<class T>
MyList<T>::~MyList() {
	for (int i = 0; i < size; i++) {
		ListNode<T>* temp = head->getNext();
		delete head;
		head = temp;
	}
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
	try {
		if (this->node->getNext() == nullptr)
			throw"End of the List";
		node = node->getNext();
	}
	catch (const char* arr) {
		std::cout << arr << std::endl;
		exit(0);
	}
}

template<class T>
void MyList<T>::iterator::operator--() {
	try {
		if (this->node->getPrev() == nullptr)
			throw"We are already at the beginning of the list";
		node = node->getPrev();
	}
	catch (const char* arr) {
		std::cout << arr << std::endl;
		exit(0);
	}
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
MyList<T>& MyList<T>::operator = (const MyList<T>& another_list) {
	while (head->getNext() != dummyNode) {
		ListNode<T>* temp = new ListNode<T>();
		temp = head->getNext();
		head->setNext(temp->getNext());
		delete temp;
	}
	tail = head;
	tail->setNext(dummyNode);
	dummyNode->setPrev(tail);
	size = another_list.size;
	if (another_list.size == 0) {
		return *this;
	}

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
			tail->setNext(this->dummyNode);
			dummyNode->setPrev(this->tail);
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
#endif 