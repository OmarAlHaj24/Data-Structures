#pragma once
#ifndef MYLIST_H
#define MYLIST_H

template<class T>
struct ListNode {
	T value;
	ListNode<T>* next;
	ListNode<T>* prev;
	ListNode();
	ListNode(T data);
};

template<class T>
class MyList {

private:
	ListNode* head, * tail;
	int size;
public:
	MyList();
	MyList(T data, int init_size);
	~MyList();
	int size() const;
	MyList<T>& operator = (MyList<T> another_list);

	class iterator {
	private:
		ListNode* node;
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
	iterator begin() const;
	iterator end() const;
	iterator erase(iterator position);
};

#endif