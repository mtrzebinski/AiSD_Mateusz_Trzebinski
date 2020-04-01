#include <iostream>

static int porownanie1 = 0;
static int porownanie2 = 0;
static int porownanie3 = 0;

// Podpunkt A
int maks1(int t[], int n)
{
    int x = t[--n];
    while(n--)
    {
		porownanie1++;
        if(t[n] > x)
        {
            x = t[n];
        }
    }
    return x;
}

// Podpunkt B
int maks2(int t[], int n)
{
	porownanie2++;
	if(n == 1)
	{
		return t[0];
	}

	int maks = maks2(t, (n - 1));
	if(maks > t[n - 1])
    {
        return maks;
    }
    else
    {
        return t[n-1];
    }

}

// Podpunkt C
int maks3(int t[], int poczatek, int koniec)
{

	if(poczatek == koniec)
	{
		return t[koniec];
	}

	int srodek = (poczatek + koniec) / 2; // 4
	int maksimum1 = maks3(t, poczatek, srodek); // 4
	int maksimum2 = maks3(t, srodek+1, koniec); // 4

	porownanie3++;
	if(maksimum1 > maksimum2)
    {
        return maksimum1;
    }
    else
    {
        return maksimum2;
    }
}

int main()
{
    int tab[7] = {1, 2, 3, 4, 5, 6, 7};

    std::cout<<"Podpunkt A Maksimum: "<<maks1(tab, sizeof(tab)/sizeof(*tab))<<" Ilosc porownan: "<<porownanie1<<std::endl;
    std::cout<<"Podpunkt B Maksimum: "<<maks2(tab, sizeof(tab)/sizeof(*tab))<<" Ilosc porownan: "<<porownanie2<<std::endl;
    std::cout<<"Podpunkt C Maksimum: " <<maks3(tab, 0, (sizeof(tab)/sizeof(*tab))-1)<<" Ilosc porownan: "<<porownanie3<<std::endl;
}
