#pragma once

#include "RegStat.h"

RegStatEntry::RegStatEntry(double x, double y, double frequency){
	this->x = x;
	this->y = y;
	this->frequency = frequency;
}

void RegStat::dt(RegStatEntry *v){
	stack.push_back(v);
}

double RegStat::bar_x(){
	double sum = 0;
	for(RegStatEntry *v : stack){
		sum += v->x;
	}
	return sum / stack.size();
}

double RegStat::bar_y(){
	double sum = 0;
	for(RegStatEntry *v:stack){
		sum += v->y;
	}
	return sum / stack.size();
}

vector<RegStatEntry *> RegStat::getStack(){
	return stack;
}

void RegStat::dt(double x, double y, double frequency){
	RegStatEntry *entry = new RegStatEntry(x, y, frequency); // memory allocation: DT
	dt(entry);
}
