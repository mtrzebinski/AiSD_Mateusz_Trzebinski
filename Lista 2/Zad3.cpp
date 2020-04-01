#include <iostream>

static int licznik = 0;

// Podpunkt A
int skalar(int a[], int b[], int n)
{
    licznik = 0;
	int wynik = 0;

	for(int i = 0; i < n; ++i)
	{
		wynik += a[i] * b[i];
		licznik++;
	}
	return wynik;
}

// Podpunkt B
int wielomian(int a[], int n, int x)
{
    licznik = 0;
	int wynik = 0;
	int czesc = 0;

	for(int i = 0; i < n; ++i)
	{
		czesc = 1;

		for(int j = n-i; j > 0; --j)
		{
			czesc *= x;
			licznik++;
		}
		czesc *= a[i];
		licznik++;
		wynik += czesc;
	}
	wynik += a[n];
	return wynik;
}

// Podpunkt C
int iloczynWielomianow(int a[], int b[], int n1, int n2, int x)
{
    licznik = 0;
	licznik++;
	return wielomian(a, n1, x) * wielomian(b, n2, x);
}

// Podpunkt D
void iloczynMacierzy(int a[][3], int b[][3], int n)
{
    licznik = 0;
	int m3[n][n];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
        {
            m3[i][j] = 0;
        }
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				m3[i][j] += a[i][k] * b[k][j];
				licznik++;
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <  n; ++j)
		{
			std::cout<<" "<<m3[i][j];
		}
	}
}

int main()
{
	int n1 = 3;
	int n2 = 4;
	int n3 = 3;
	int x = 10;
	int s1[n1] = {1,2,3};
	int s2[n1] = {4,5,6};
	int w1[n1+1] = {1,2,3,4};
	int w2[n2+1] = {5,6,7,8,9};
	int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int m2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int m3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	std::cout<<skalar(s1, s2, n1)<<" Ilosc porownan: "<<licznik<<std::endl;
	std::cout<<wielomian(w1, n1, x)<<" Ilosc porownan: "<<licznik<<std::endl;
	std::cout<<iloczynWielomianow(w1, w2, n1, n2, x)<<" Ilosc porownan: "<<licznik<<std::endl;
	iloczynMacierzy(m1, m2, n3);
	std::cout<<" Number of multiplications: "<<licznik<<std::endl;

}
