#include <iostream>
using namespace std;
// Using  for loop TC = O(N)
int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

// using Recursion having same time complexity TC = O(N)
int fact1(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return fact1(n - 1) * n;
}
int main()
{
    cout << fact1(5);
    cout<<endl;
}