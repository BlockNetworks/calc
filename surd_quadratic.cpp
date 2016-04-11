#include <cmath>
#include "common.cpp"
#include "calc.h"

using namespace std;

int main(){
	cout << "For Ax^2 + Bx + C = 0:\n";
	query("A: ", &a);
	query("B: ", &b);
	query("C: ", &c);
	cout << "\nSolving: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

	double *delta = &d;
	d = b * b - 4 * a * c;

	double *front = &x;
	if(d > 0){
		cout << "Two real roots: ";
		*front = -b / (2 * a);
		cout << *front + sqrt(*delta) / (2 * a) << " OR ";
		cout << *front - sqrt(*delta) / (2 * a) << endl;
	}else if(d == 0){
		cout << "One real root: ";
		cout << -b / (2 * a) << endl;
		return 0;
	}else{
		cout << "Two imaginary roots: ";
		*front = -b / (2 * a);
		cout << *front << " +- sqrt( " << abs(*delta) << " ) i" << endl;
	}

	cout << "Surd form: " << *front << " +- ";

	double *cont = &x;
	*cont = abs(*delta);

	double *factor = &y;
	double *multiplier = &c;
	*multiplier = 1;

	double *div = &m;
	for(*factor = 2; *factor <= sqrt(*cont); (*factor)++){
		*div = *cont / (*factor * *factor);
		if(floor(*div) == *div){
			*multiplier *= *factor;
			*cont = *div;
		}
	}

	cout << *multiplier / (2 * a);
	if(*delta < 0){
		cout << "i";
	}
	cout << " sqrt( " << abs(*cont) << " )" << endl;
}
