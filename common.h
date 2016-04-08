#pragma once

#include <string>
#include <math.h>

void query(std::string query, double *result);

double pol(double dx, double dy, double *x, double *y){
	*y = atan(dy / dx);
	*x = sqrt(dx * dx + dy * dy);
	return *x;
}