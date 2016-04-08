#pragma once

#include "Gettable.h"

template<class T>
class PointerGettable : public Gettable<T>{
	T *value;
public:
	PointerGettable(T *value){
		this->value = value;
	}

	virtual T get(){
		return *value;
	}
};