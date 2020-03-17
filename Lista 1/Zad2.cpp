#include <cmath>
#include <iostream>

using namespace std;
double epsilon = 0.0001;

double x(double x)
{
	return  x*x*x - x + 2;
}

double y(double x)
{
	return  x*x*x - x + 9;
}

double roots(double f(double), double a, double b)
{
	double fa = f(a);
	double fb = f(b);
	double x0 = 0;

	if (fa*fb > 0) //(fa > 0 || 0 > fb)
	{
		cout << "Brak spelnionych zalozen bisekcji" << endl;
		return 0;
	}
	while (abs(a-b) > epsilon)
	{
		fa = f(a);
		x0 = (a + b) / 2;
		double f0 = f(x0);

		if (abs(f0) < epsilon) break;

		if (fa*f0 < 0)
			b = x0;
		else
		{
			a = x0;
		}
	}
	return x0;
}

int main()
{
	cout << roots (x,-2, 2) << endl;
	cout << roots(y, -2, 2) << endl;
	getchar();
	return 0;
}
