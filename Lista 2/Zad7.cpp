#include <iostream>

int licznik = 0;

struct node
{
	int m_x;
	node* m_left;
	node* m_right;

	node(int x, node* left = NULL, node* right = NULL):
	    m_x(x), m_left(left), m_right(right){}
};

void wstaw(node *& t, int x)
{
	node **t1 = &t;
	while(*t1)
	{
		if(x<(*t1)->m_x)
		{
			t1 = &((*t1)->m_left);
		}

		else
		{
			t1 = &((*t1)->m_right);
		}
		licznik++;
	}

	*t1 = new node(x);
}

int glebokosc(node* t)
{
	if(!t)
	{
		return -1;
	}
	else
    {
        return 1 + std::max(glebokosc(t->m_left), glebokosc(t->m_right));
    }

}

void wyswietl(node *t, char z1 = ' ', char z2 = ' ')
{
	if(t)
	{
		std::cout<<z1;
		wyswietl(t->m_left,'(',')');
		std::cout<<t->m_x;
		wyswietl(t->m_right,'[',']');
		std::cout<<z2;
	}
}



int main(){

	node *N = nullptr;
	int n = 15;
	for (int i=1; i<=n; i++)
	{
        wstaw(N, i);
    }

    wyswietl(N);
    std::cout << std::endl;
    std::cout<<"Glebokosc drzewa: "<<glebokosc(N)<<std::endl;
	std::cout<<"Ilosc porownan: "<<licznik<<std::endl;
	return 0;
}
