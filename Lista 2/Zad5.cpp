#include <iostream>

struct lnode
{
	int m_key;
	lnode* m_next;

	lnode(int key, lnode* next=NULL) :
		m_key(key),
		m_next(next)
	{}
};

void pushNode(lnode*& L, int key)
{
	lnode* tmp = new lnode(key);
	tmp->m_next = L;
	L = tmp;
}

void wypisz(lnode* L)
{
	while(L != NULL)
	{
		std::cout << L->m_key << " ";
		L = L->m_next;
	}
}

void odwroc(lnode*& L)
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

int main()
{
	lnode* myNode = NULL;
	pushNode(myNode, 4);
	pushNode(myNode, 3);
	pushNode(myNode, 2);
	pushNode(myNode, 1);

	wypisz(myNode);
	odwroc(myNode);
	std::cout<<std::endl;
	wypisz(myNode);
}
