#include <iostream>

static int porownania = 0;

int find(int t[], int poczatek, int koniec, int x)
{
	int srodek = (poczatek + koniec) / 2;

	porownania++;
	if(t[srodek] == x)
	{
		std::cout<<"Element znaleziony. Potrzebowal porownan: "<<porownania<<std::endl;
		return srodek;
	}
	else if(poczatek == koniec)
	{
		std::cout<<"Element nieznaleziony. Ilosc porownan: "<<porownania<<std::endl;
		return 0;
	}
	else
	{
		if (t[srodek] > x)
        {
            koniec = srodek;
		}
		else
        {
            poczatek = srodek+1;
		}
        find(t, poczatek, koniec, x);
	}

	porownania = 0;
	return 0;
}


int main()
{

	int t1[8] = {1, 4, 5, 7, 10, 22};
	int t2[15] = {1, 4, 5, 7, 10, 11};
	int t3[16] = {1, 4, 5, 7, 50, 56, 87};

	find(t1, 0, 6, 22);
	find(t2, 0, 2, 1);
	find(t3, 0, 7, 50);
	find(t1, 0, 6, 100);
	find(t2, 0, 6, 100);
	find(t3, 0, 7, 7);
}
