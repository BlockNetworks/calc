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

	double bar_x();

	double bar_y();

	vector<RegStatEntry *> getStack();
} stat;
