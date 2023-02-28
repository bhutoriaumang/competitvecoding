#include <bits/stdc++.h>
using namespace std;

int fact(int x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}

int calc(int x, int y, int t)
{
    if (t > 60)
        return -1;
    int s = 0;
    while (x > 0)
    {
        s += fact(x % 10);
        x /= 10;
    }
    if (s == y)
        return t;
    return calc(s, y, t + 1);
}

int main()
{
    string s;
    getline(cin, s);
    s += " ";
    vector<int> x;
    string t = "";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == ' ')
        {
            x.push_back(stoi(t));
            t = "";
        }
        else
            t += ch;
    }
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        int ans = calc(x[i], x[i], 1);
        if (ans == -1)
            cout << "F";
        else
            cout << ans;
        cout << " ";
    }
}