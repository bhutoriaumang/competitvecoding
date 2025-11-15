/*

Problem Tags: ['brute force', 'geometry', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n, k;
        cin >> n >> k;
        vector< vector<int> > v(n, vector<int>(2, 0));
        vector<int> x(51, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1];
            if (k >= v[i][0] && k <= v[i][1])
            {
                for (int j = v[i][0]; j <= v[i][1]; j++)
                    x[j]++;
            }
        }
        int ind = 1;
        for (int i = 1; i < x.size(); i++)
        {
            if (i == k)
                continue;
            if (x[i] >= x[k])
            {
                ind = -1;
                break;
            }
        }
        if (ind == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}