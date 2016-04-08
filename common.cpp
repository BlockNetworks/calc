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
