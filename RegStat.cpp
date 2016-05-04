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

void RegStat::dt(double x, double y, double frequency){
	RegStatEntry *entry = new RegStatEntry(x, y, frequency); // memory allocation: DT
	dt(entry);
}

void RegStat::dt(double x, double y){
	this->dt(x, y, 1);
}

void RegStat::dt(double x){
	this->dt(x, 0, 1);
}

double RegStat::bar_x(){
	double sum = 0;
	double freq = 0;
	for(RegStatEntry *v : stack){
		sum += v->x * v->frequency;
		freq += v->frequency;
	}
	return sum / freq;
}

double RegStat::bar_y(){
	double sum = 0;
	double freq = 0;
	for(RegStatEntry *v:stack){
		sum += v->y * v->frequency;
		freq += v->frequency;
	}
	return sum / freq;
}

double RegStat::sum_x(){
	double sum = 0;
	for(RegStatEntry *v : stack){
		sum += v->x * v->frequency;
	}
	return sum;
}

double RegStat::sum_y(){
	double sum = 0;
	for(RegStatEntry *v : stack){
		sum += v->y * v->frequency;
	}
	return sum;
}

double RegStat::sum_xy(){
	double sum = 0;
	for(RegStatEntry *v : stack){
		sum += v->x * v->y * v->frequency;
	}
	return sum;
}

double RegStat::sum_x3(){
	double sum = 0;
	for(RegStatEntry *v : stack){
		sum += v->x * v->x * v->x * v->frequency;
	}
	return sum;
}

vector<RegStatEntry *> RegStat::getStack(){
	return stack;
}
