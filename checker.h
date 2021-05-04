#ifndef TEMPLATE_CHECKER_H
#define TEMPLATE_CHECKER_H
#include <iostream>
using namespace std;


template <typename T>
bool checkInput(T input1){
	T result;
	if(input1){
	result = input1;
	}
	return result;
}

#endif

