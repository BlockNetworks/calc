#include "common.cpp"
#include "calc.h"
#include "RegStat.h"

using namespace std;

int main(){
	query("Row 1 Cell 1: ", &m);
	stat.dt(pow(m - 1, 1 / 3));
	query("Row 1 Cell 2: ", &m);
	stat.dt(1, m);
	query("Row 1 Cell 3: ", &m);
	stat.dt(0, m - stat.sum_y());
	query("Row 2 Cell 1: ", &a);
	query("Row 2 Cell 2: ", &b);
	query("Row 2 Cell 3: ", &c);
	query("Row 3 Cell 1: ", &x);
	query("Row 3 Cell 2: ", &y);
	query("Row 3 Cell 3: ", &m);
	d = b * m * stat.sum_x3() - c * y * stat.sum_x3() + c * x * stat.sum_xy() - a * m * stat.sum_xy() + a * y * stat.sum_y() - b * x * stat.sum_y();
	cout << "Det: " << d << endl;
	return 0;
}
