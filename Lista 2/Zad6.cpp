#include <iostream>

static int licznik = 0;

struct lnode
{
	int m_key;
	lnode* m_next;

	lnode(int key, lnode* next=NULL) :
		m_key(key),
		m_next(next){}

};

void pushNode(lnode*& L, int key)
{
	lnode* temp = new lnode(key);
	temp->m_next = L;
	L = temp;
}

void wypisz(lnode* L)
{
	while(L != NULL)
	{
		std::cout<<L->m_key<<" ";
		L = L->m_next;
	}
}


void odwrocenie(lnode*& L)
{
	lnode* obecny = L;
	lnode* poprzedni = NULL;
	lnode* next = NULL;

	while(obecny != NULL)
	{
		next = obecny->m_next;
		obecny->m_next = poprzedni;
		poprzedni = obecny;
		obecny = next;
	}
	L = poprzedni;
}

lnode* podzial(lnode* L1, lnode* L2)
{
	lnode* newNode = NULL;

	while(L1 || L2)
	{
		if(!L1)
		{
			pushNode(newNode, L2->m_key);
			L2 = L2->m_next;
		}
		else if(!L2)
		{
			pushNode(newNode, L1->m_key);
			L1 = L1->m_next;
		}
		else
		{
			if(L1->m_key < L2->m_key)
			{
				pushNode(newNode, L1->m_key);
				L1 = L1->m_next;
			}
			else
			{
				pushNode(newNode, L2->m_key);
				L2 = L2->m_next;
			}
			licznik++;
		}
	}

	odwrocenie(newNode);
	return newNode;
}

int main()
{
	lnode* myNode1 = NULL;
	pushNode(myNode1, 1);
	pushNode(myNode1, 2);
	pushNode(myNode1, 3);
	pushNode(myNode1, 4);

	lnode* myNode2 = NULL;
	pushNode(myNode2, 5);
	pushNode(myNode2, 6);
	pushNode(myNode2, 7);
	pushNode(myNode2, 8);

	wypisz(myNode1);
	std::cout << std::endl;
	wypisz(myNode2);
	std::cout << std::endl;

	lnode* myNode3 = podzial(myNode1, myNode2);
	wypisz(myNode3);
    std::cout << std::endl;
	std::cout<<licznik<<std::endl;
}
