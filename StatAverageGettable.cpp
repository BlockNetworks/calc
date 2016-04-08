#pragma once

#include "RegStat.cpp"
#include "Gettable.h"

template <class T>
class StatAverageGettable : public Gettable<T>{
	bool name;
public:
	StatAverageGettable(bool name){
		this->name = name;
	}
	virtual T get(){
		return this->name ? stat.bar_x() : stat.bar_y();
	}
};
