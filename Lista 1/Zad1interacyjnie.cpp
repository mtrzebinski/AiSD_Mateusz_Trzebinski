#include <iostream>
#include <cmath>

using namespace std;

double power(int x, int n)
{
   double s = 1;
   if (n<0) return 1/power(x,-n);
   while (n > 0)
   {
       if (n%2 == 0)
       {
           x = x*x;
           n = n/2;
       }
       else
       {
           s = s*x;
           n--;
       }
   }
   return s;
}

int main()
{
    while(true)
    {
        int a, n;
        cin >> a >> n;
        cout << power(a, n) << endl;
    }
}
