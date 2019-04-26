// Copyright 2019 Karasev Anton

#ifndef MODULES_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_
#define MODULES_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_

#include <iostream>
#include <vector>
#include <string>

template <typename T> 
class modif_stack
{
private:
	std::vector<std::pair<T, T>> stack;

public:
	modif_stack();
	modif_stack(const modif_stack<T> &src);
	modif_stack(std::vector<T> src = { 1, 2, 3, 4, 5 });
	~modif_stack();

	bool empty();
	int size();

	std::pair<T, T> top();
	void push(T number);
	void pop();
	std::string show_stack();
};

#endif //MODULES_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_