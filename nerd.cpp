#include <iostream>
#include <algorithm>
using namespace std;

int calc(int a[], int n, int p, int i)
{
    if (i >= n)
        return p;
    return max(calc(a, n, p + a[i], i + 2), calc(a, n, p, i + 1));
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << calc(a, n, 0, 0) << endl;
}