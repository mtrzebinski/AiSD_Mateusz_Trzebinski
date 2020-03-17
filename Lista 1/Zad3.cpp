#include <iostream>
#include <vector>
using namespace std;

// stosuj�c schemat hornera wykonujemy n mno�e� dla n-wymiarowego wielomianu

double oblicz(vector<int> a, double x)
{
	double w = 0;
	int n = a.size() - 1;
	cout << "Ilosc mnozen = " << n+1 << endl;
	for (int i = n; i >= 0; i--)
	{
		w *= x;
		w += a[i];
	}

	return w;
}

int main()
{
	vector<int> a = { 3, 4, 7, 8 ,9 };
	cout << "Wynik wielomianu = " << oblicz(a,2) << endl;

	getchar();
	return 0;
}
