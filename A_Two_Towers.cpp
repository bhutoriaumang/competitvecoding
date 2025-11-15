/*

Problem Tags: ['brute force', 'implementation', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    string w = "";
    for (int i = 0; i < s.length(); i++)
        w = s[i] + w;
    return w;
}

int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n, m;
        cin >> n >> m;
        string x, y;
        cin >> x >> y;
        x += reverse(y);
        int c = 0;
        for (int i = 0; i < x.length() - 1; i++)
        {
            if (x[i] == x[i + 1])
                c++;
        }
        if (c > 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}