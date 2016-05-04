#pragma once

#include <vector>

using namespace std;

class RegStatEntry{
public:
	double x;
	double y;
	double frequency;

	RegStatEntry(double x, double y, double frequency);
};

class RegStat{
	vector<RegStatEntry *> stack;

public:
	void dt(RegStatEntry *v);

	void dt(double x, double y, double frequency);

	void dt(double x, double y);

	void dt(double x);

	double bar_x();

	double bar_y();

	double sum_x();

	double sum_y();

	double sum_xy();

	double sum_x3();

	vector<RegStatEntry *> getStack();
} stat;
