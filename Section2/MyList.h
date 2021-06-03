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
	T getValue();
	void setValue(T val);
	ListNode* getNext();
	ListNode* getPrev();
	void setNext(ListNode<T>* nt);
	void setPrev(ListNode<T>* previous);
};

template<class T>
class MyList {

private:
	ListNode<T>* head, * tail;
	ListNode<T>* dummy;
	int size;
public:
	MyList();
	MyList(T data, int init_size);
	~MyList();
	int getSize() const;
	MyList<T>& operator = (MyList<T> another_list);

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

	void insert(T value, iterator position);
	iterator begin() const {
		return iterator(head);
	}

	iterator end() const {
		return iterator(dummy);
	}

	iterator erase(iterator position) {
		ListNode<T>* temp = head;
		while (temp != dummy) {
			if (temp == position.node) {
				temp->getNext()->setPrev(temp->getPrev);
				temp->getPrev()->setNext(temp->getNext);
				position = temp->getNext();
				if (temp == head)
					head = temp->getNext();
				else if (temp == tail) {
					tail = temp->getPrev();
				}
				delete temp;
				size--;
				return position;
			}
		}
		throw"Position not found";
	}

};
#endif 