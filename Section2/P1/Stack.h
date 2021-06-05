#pragma once

template<class T>
class Stack {
private:
	struct StackNode 
	{
		T Entry;
		StackNode* Prev;
		StackNode(T entry, StackNode* prev): Entry(entry), Prev(prev) { }
	};
private:
	StackNode* _top;
	unsigned int _size;
public:
	Stack();
	Stack(T defaultValue, unsigned int initialSize);
	~Stack();

	T* Top() const;
	bool Push(T const& element);
	T Pop();

	bool IsEmpty() const { return !_top; }
	unsigned int size() { return _size; }
};

template<class T>
Stack<T>::Stack() : _top(0), _size(0) { }

template<class T>
Stack<T>::Stack(T defaultValue, unsigned int initialSize) : _top(0), _size(initialSize)
{
	for (int i = 0; i < initialSize; ++i)
	{
		StackNode* node = new StackNode(defaultValue, _top);
		_top = node;
	}
}

// Return false if memroy allocation fails, otherwise true
template<class T>
bool Stack<T>::Push(T const& element)
{
	StackNode* node = new (std::nothrow) StackNode(element, _top);

	if (!node)
		return false;

	_top = node;
	return true;
}

// Returns null pointer if stack is empty
template<class T>
T* Stack<T>::Top() const
{
	return &(_top->Entry);
}

template<class T>
T Stack<T>::Pop() 
{
	// TODO handle null top
	StackNode* node = _top;
	_top = _top->Prev;
	T element = node->Entry;
	delete node;
	return element;
}

template<class T>
Stack<T>::~Stack() { }