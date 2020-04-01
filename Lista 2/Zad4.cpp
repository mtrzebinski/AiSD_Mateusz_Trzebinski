#include <iostream>

void odwrotnosc(int *tab, int poczatek, int koniec)
{
    int tmp;

    while(poczatek < koniec)
    {
        tmp = tab[poczatek];
        tab[poczatek] = tab[koniec];
        tab[koniec] = tmp;
        ++poczatek;
        --koniec;
    }
}


void zmiana(int *tab, int n, int k)
{
	k %= n;
	if(k != 0)
	{
		odwrotnosc(tab, 0, n-1);
		odwrotnosc(tab, 0, k-1);
		odwrotnosc(tab, k, n-1);
	}
}

int main()
{
	int n = 6;
	int k = 10;
	int t[n] = {2, 4, 6, 8, 10, 12};
	zmiana(t, n, k);

	for(int i = 0; i < n; ++i)
	{
		std::cout<<t[i]<<" ";
	}
}
