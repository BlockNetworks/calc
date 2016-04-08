#pragma once

#include <string>
#include <math.h>

void query(std::string query, double *result);

double pol(double dx, double dy, double *x, double *y);

void swapVariables(double *var1, double *var2, double *tmp);