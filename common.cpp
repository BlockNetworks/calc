#pragma once

#include <iostream>
#include <sstream>
#include "common.h"

using namespace std;

void query(string query, double *result){
	cout << query;
	cout.flush();
	string buffer;
	getline(cin, buffer);
	stringstream(buffer) >> *result;
}

double pol(double dx, double dy, double *x, double *y){
	*y = atan(dy / dx);
	*x = sqrt(dx * dx + dy * dy);
	return *x;
}

template <typename T>
void swapVariables(T *var1, T *var2, T *tmp){
	// transpiration pull?
	*tmp = *var1;
	*var1 = *var2;
	*var2 = *tmp;
}
