#include "RegStat.cpp"
#include "common.cpp"
#include "PointerGettable.cpp"
#include "StatAverageGettable.cpp"

using namespace std;

double a, b, c, d, x, y, m, ans; // 7 variable slots + 1 Ans slot


Gettable<double> *px = new PointerGettable<double>(&a);
Gettable<double> *py = new PointerGettable<double>(&b);
Gettable<double> *qx = new PointerGettable<double>(&c);
Gettable<double> *qy = new PointerGettable<double>(&d);
Gettable<double> *rx = new PointerGettable<double>(&x);
Gettable<double> *ry = new PointerGettable<double>(&y);

int main(){
	// 3-26
	// order of input for X,Y and C,D is swapped
	cout << "In triangle P(a,b) Q(c, d) R(x, y):" << endl;
	query("a: ", &a);
	query("b: ", &b);
	query("c: ", &c);
	query("d: ", &d);
	query("x: ", &x);
	query("y: ", &y);
	cout << "\n";

	if(a == x){
		if(c == x){
			cerr << "Not a triangle - all angles with same X-coordinate!" << endl;
			return 2;
		}
		swapVariables(&c, &x, &m);
		swapVariables(&d, &y, &m);
	}

	// 27-44
	cout << "Centroid: (" << (**px + **qx + **rx) / 3 << ", " << (**py + **qy + **ry) / 3 << ")" << endl;

	// 47-60
	stat.dt(x, y, pol(b - d, a - c, &x, &y));
	delete rx;
	rx = new StatAverageGettable<double>(true);
	ry = new StatAverageGettable<double>(false);
	// 61-65
	y = tan(y);
	// deobfuscation
//	double *PQ = &x;
	double *slopePQ = &y;

	// 66-69
	ans = **py - stat.bar_y();
	// deobfuscation
	double *dyPR = &ans;

	// 70-94
	x = **qx + *dyPR * (*slopePQ * **rx + **ry - *slopePQ * **qx - **qy) / (**rx + *dyPR * *slopePQ - **px);
	cout << "Orthocenter: (" << x << ", ";
	// no longer valid
	dyPR = nullptr;
//	PQ = nullptr;
	// deobfuscation
	double *undeobfuscated_x_0 = &x;

	// 95-104
	y = **ry + **rx * *slopePQ - x * *slopePQ;
	cout << y << ")" << endl;
	// deobfuscation
	double *undeobfuscated_y_0 = &y;

	// 105-115
	cout << "Circumcenter: (" << (**px + **qx + **rx - *undeobfuscated_x_0) / 2 << ", ";

	// 116-126
	cout << (**py + **qy + **ry - *undeobfuscated_y_0) / 2 << ")" << endl;

	// 131-139
	pol(**rx - **qx, **ry - **qy, &x, &y);
	// deobfuscation
	double *freq = &x;
	// no longer valid
	undeobfuscated_x_0 = nullptr;
	undeobfuscated_y_0 = nullptr;

	// 142-149
	pol(**rx - **px, **ry - **py, &x, &y);
	// 127-139
	stat.dt(**px, **py, *freq);
	// deobfuscation
	double *undeobfuscated_x_1 = &x;
	// no longer valid
	rx = nullptr;
	ry = nullptr;

	// 152-158
	stat.dt(**qx, **qy, *undeobfuscated_x_1);

	// 159-EOF
	cout << "Incenter: (" << stat.bar_x() << ", " << stat.bar_y() << ")" << endl;

	return 0;
}
