#include "StivaStatica.h"
#include<iostream>

int main() {
	Array_Stack stiva(5);
	try {
		stiva.push(10);
		stiva.push(20);
		stiva.push(30);
		stiva.push(40);
		stiva.push(50);
		stiva.print();
		std::cout << "Elementul din varf:" << stiva.peek() << std::endl;
		stiva.pop();
		stiva.print();
		stiva.pop();
		stiva.pop();
	}
	catch (const StackAbstract::Stack_Underflow& e) {
		std::cout << "Exceptie: Stiva este vida!\n";
	}
	catch (const StackAbstract::Stack_Overflow& e) {
		std::cout << "Exceptie: Stiva este plina!\n";
	}
	return 0;
}