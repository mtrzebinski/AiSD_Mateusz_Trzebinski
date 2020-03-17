#include <iostream>
using namespace std;
struct lnode
{
	int key;
	lnode *next;
	lnode(int n, lnode * l = NULL) : key(n), next(l) {};
};

int nty(lnode *l, int n)
{
    // pierwszy element listy ma indeks 0.
	for (int i = 0; i < n; i++)
	{
		if (l->next == NULL)
			return 0;
		else
			l = l->next;
	}
	return l->key;
}
int suma(lnode *l)
{
    int wynik = 0;

    while (l != NULL)
    {
        wynik += l->key;
        l = l->next;
    }
    return wynik;
}

lnode* filter(lnode* l)
{
    lnode* nasza = NULL;
    lnode* elem  = NULL;

    while (l != NULL)
    {
        if (l->key >= 0)
        {
            if (elem == NULL) // �e jest to pierwszy element, kt�ry dodajemy
            {
                elem = nasza = new lnode(l->key);
            }
            else
            {
                elem->next = new lnode(l->key);
                elem = elem->next;
            }
        }

        lnode* tmp = l;
        l = l->next;
        delete tmp;
    }

    return nasza;
}

int main()
{
	lnode *l = new lnode(5);
	l = new lnode(-5, l);
	l = new lnode(2, l);
	l = new lnode(3, l);
	l = new lnode(5, l);
	l = new lnode(7, l);

	cout << "3-ci element listy:" << nty(l, 2) << endl;
	cout << "Suma: " << suma(l) << endl;
	l = filter(l);
	cout << "Suma: " << suma(l) << endl;

	//getchar();
	return 0;
}
