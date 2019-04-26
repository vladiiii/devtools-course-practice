// Copyright 2019 Karasev Anton

#include "include/modif_stack.h"

#include <iostream>
#include <vector>
#include <string>

template <typename T>
modif_stack<T>::modif_stack() {};

template <typename T>
modif_stack<T>::modif_stack(const modif_stack<T> &src)
{
	for (auto i = src.stack.begin(); i != src.stack.size(); i++)
	{
		this->stack.push_back(src.stack[i]);
	}
}

template <typename T>
modif_stack<T>::modif_stack(std::vector<T> src)
{
	for (auto i = src.stack.begin(); i != src.size(); i++)
	{
		this->stack.push_back(src[i]);
	}
}

template <typename T>
modif_stack<T>::~modif_stack() {};

template <typename T>
bool modif_stack<T>::empty()
{
	return stack.empty();
}

template <typename T>
int modif_stack<T>::size()
{
	return this->stack.size();
}

template <typename T>
std::pair<T, T> modif_stack<T>::top()
{
	std::pair<T, T> res = std::make_pair(-1, 0);
	if (this->size() != 0)
	{
		res = this->stack[this->stack.size() - 1];
	}
	return res;
}

template <typename T>
void modif_stack<T>::push(T number)
{
	std::pair<T, T> res = std::make_pair(number, number);
	res.second = std::min(number, this->top().second);
	this->stack.push_back(res);
}

template <typename T>
void modif_stack<T>::pop()
{
	if (this->size() != 0)
	{
		res = this->stack.pop_back();
	}
}

template <typename T>
std::string modif_stack<T>::show_stack()
{
	std::string res = "";
	for (auto i = 0; i < this->size(); i++)
	{
		res += "(";
		res = res + this->stack[i].first + "," + this->stack[i].second + ") ";
	}

	return res;
}