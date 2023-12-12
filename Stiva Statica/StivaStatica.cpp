#include "stivastatica.h"
#include<iostream>
using namespace std;
Array_Stack::Array_Stack(int max) {
	this->max = max;
	this->top = 0;
	this->vector = new int[max];
}
Array_Stack::~Array_Stack() {
	this->top = 0;
	this->max = 0;
	delete[] this->vector;
}
void Array_Stack::push(int value) {
    if (isfull()) {
        throw Stack_Overflow();
    }
    vector[top++] = value;
}

int Array_Stack::pop() {
    if (isempty()) {
        throw Stack_Underflow();
    }
    return vector[--top];
}

int Array_Stack::peek() {
    if (isempty()) {
        throw Stack_Underflow();
    }
    return vector[top - 1];
}

bool Array_Stack::isempty() {
    return top == 0;
}

bool Array_Stack::isfull() {
    return top == max;
}

void Array_Stack::print() {
    if (isempty()) {
        cout << "Stiva este vida\n";
    }
    else {
        cout << "Elementele stivei sunt: ";
        for (int i = 0; i < top; ++i) {
            cout << vector[i] << " ";
        }
        cout << endl;
    }
}