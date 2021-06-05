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
	T PopElement();
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
	_size++;
	return true;
}

// Returns null pointer if stack is empty
template<class T>
T* Stack<T>::Top() const
{
	return &(_top->Entry);
}

// Pre-conditions: It doesn't check boundaries, make sure to check for boundry conditions before calling
template<class T>
T Stack<T>::PopElement()
{
	StackNode* node = _top;
	T elementToReturn = node->Entry;
	_top = _top->Prev;
	delete node;
	_size--;
	return elementToReturn;
}

// Pre-conditions: Stack must not be empty. Throws an exception if stack is Empty
// Use TryPop for no exceptions on stack empty
template<class T>
T Stack<T>::Pop()
{
	if (!_top)
		throw "Stack is Empty";

	return PopElement();
}

// outElement: Reference to pop element into.
// Pops items from stack, if stack is Empty returns false.
template<class T>
bool Stack<T>::TryPop(T& outElement)
{
	if (!_top)
		return false;

	outElement = PopElement();
	return true;
}

template<class T>
Stack<T>::~Stack() {}
