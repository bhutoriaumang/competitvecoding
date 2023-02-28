#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        long long int n, a, b, k;
        cin >> n >> a >> b >> k;
        if (b < a)
            swap(a, b);
        long long int x, y, z;
        x = n / a;
        y = n / b;
        if (b % a != 0)
            z = n / (a * b);
        else
            z = n / b;
        x -= z;
        y -= z;
        if ((x + y) >= k)
            cout << "Win ";
        else
            cout << "Lose ";
        // long long int ans = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (i % a == 0 && i % b != 0)
        //         ans++;
        //     else if (i % a != 0 && i % b == 0)
        //         ans++;
        // }
        // if (ans >= k)
        //     cout << "Win\n";
        // else
        //     cout << "Lose\n";
    }
}