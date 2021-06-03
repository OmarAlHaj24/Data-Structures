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
		return iterator(tail);
	}

	iterator insert(T value, iterator position) {
		ListNode<T>* temp = new ListNode<T>(value);
		temp->setNext(position.node);
		if (position.node == head) {
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}
		else {
			position.node->getPrev()->setNext(temp);
			temp->setPrev(position.node->getPrev());
			position.node->setPrev(temp);
			if (position.node == tail) {
				tail = position.node;
				tail->setNext(dummyNode);
				dummyNode->setPrev(tail);
			}
			if (position.node == dummyNode) {
				tail = temp;
				dummyNode->setPrev(tail);
				tail->setNext(dummyNode);
			}
		}
		size++;
		--position;
		return position;
	}

	iterator erase(iterator position) {
		ListNode<T>* temp = head;
		while (temp != dummyNode) {
			if (temp == position.node) {
				temp->getNext()->setPrev(temp->getPrev());
				if (head != temp)
					temp->getPrev()->setNext(temp->getNext());
				position = temp->getNext();
				if (temp == head)
					head = temp->getNext();
				else if (temp == tail) {
					tail = temp->getPrev();
					dummyNode->setPrev(tail);
					tail->setNext(dummyNode);
				}
				delete temp;
				size--;
				return position;
			}
			temp = temp->getNext();
			size--;
		}
		throw"Position not found";
	}

};
#endif 