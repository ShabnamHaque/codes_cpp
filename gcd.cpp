#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
   if (b == 0)
   {
      x = 1;
      y = 0;
      return a;
   }
   int x1, y1;
   int d = gcd(b, a % b, x1, y1);
   x = y1;
   y = x1 - (a / b) * y1;
   return d;
}

 int main()

{
   int a = -199, b = 98, x, y;
   cout << "constant ? " << gcd(a, b, x, y);
   cout << endl
        << (-5) * x << endl
        << (-5) * y << endl;

   return 0;
}
