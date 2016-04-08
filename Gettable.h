#pragma once

template<class T>
class Gettable{
public:
	virtual T get() = 0;

	T operator()(){
		return get();
	}

	T operator *(){
		return get();
	}
};
