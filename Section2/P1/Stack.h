#pragma once

template<class T>
class Stack
{
private:
	struct StackNode
	{
		T Entry;
		StackNode* Prev;
		StackNode(T entry, StackNode* prev) : Entry(entry), Prev(prev) { }
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
	bool TryPop(T& outElement);

	bool IsEmpty() const { return !_top; }
	unsigned int size() const { return _size; }
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

// Pre-conditions: Stack must not be empty. Throws an exception if stack is Empty
// Use TryPop for no exceptions on stack empty
template<class T>
T Stack<T>::Pop()
{
	if (!_top)
		throw "Stack is Empty";

	StackNode* node = _top;
	_top = _top->Prev;
	T element = node->Entry;
	delete node;
	return element;
}

// outElement: Reference to pop element into.
// Pops items from stack, if stack is Empty returns false.
template<class T>
bool Stack<T>::TryPop(T& outElement)
{
	if (!_top)
		return false;

	StackNode* node = _top;
	outElement = node->Entry;
	_top = _top->Prev;
	delete node;
	return true;
}

template<class T>
Stack<T>::~Stack() {}