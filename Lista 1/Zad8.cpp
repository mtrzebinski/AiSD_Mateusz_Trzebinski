#include <iostream>
#include <vector>
#include <cmath>


void sito(const int& n)
{
    std::vector<bool> prime(n+1,true);
    prime[0] = false, prime[1] = false;

    for (int i=2; i<=n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i <= n; ++i)
    {
        if(prime[i])
            std::cout << i << std::endl;
    }
}
int main()
{
    sito(75);
}
