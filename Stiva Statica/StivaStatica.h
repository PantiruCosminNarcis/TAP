#pragma once
#ifndef STIVASTATICA_H
#define STIVASTATICA_H

using namespace std;
class StackAbstract {
public: 
	virtual void push(int) = 0;
	virtual int pop() = 0;
	virtual int peek() = 0;
	virtual bool isempty() = 0;
	virtual bool isfull() = 0;
	virtual void print() = 0;
	class Stack_Overflow{};
	class Stack_Underflow{};
};

class Array_Stack :public StackAbstract {
private: 
	int* vector;
	int top;
	int max;
public:
	Array_Stack(int max = 100);
	Array_Stack(const Array_Stack&);
	~Array_Stack();
	virtual void push(int);
	virtual int pop();
	virtual int peek();
	virtual bool isempty();
	virtual bool isfull();
	virtual void print();
};
#endif // !STIVASTATICA_H
 