#pragma once

#include <string>
#include <math.h>

void query(std::string query, double *result);

double pol(double dx, double dy, double *x, double *y);

template <typename T>
void swapVariables(T *var1, T *var2, T *tmp);

