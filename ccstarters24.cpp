#include </Users/bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n, m;
        cin >> n;
        string s;
        cin >> s;
        cin >> m;
        vector<vector<int> > v(26, vector<int>());
        for (int i = 0; i < n; i++)
        {
            v[(int)s[i] - 97].push_back(i);
        }
        int ans = n, count = 0;
        while (true)
        {
            count++;
            // if (count == 3)
            //     break;
            string x = "";
            vector<int> k(26, 0);
            int i = 0, d = -1, c = 0, cc = 0;
            while (v[i].size() > k[i] && x.length() < m)
            {
                // if (cc == 10)
                //     break;
                int f = v[i][k[i]];
                if (f < d)
                {
                    if(i>0 && 1<v[i-1].size() && v[i-1][1]>f){
                        v[i].erase(v[i].begin(),v[i].begin()+1);
                    }
                    else
                        k[i]++;
                }
                else
                {
                    if(i!=0)
                        c += (v[i][k[i]] - d) - 1;
                    d = v[i][k[i]];
                    x += (char)(97 + i);
                    i++;
                    i = i % 26;
                }
            }
            if (x.length() == m)
                ans = min(ans, c);
            int flag = 0;
            if(v[0].size()>0)
                v[0].erase(v[0].begin(),v[0].begin()+1);
            for (int ll = 0; ll < v.size(); ll++)
            {
                if(ll<m && v[ll].size()==0)
                    flag = 1;
                if(v[ll].size()==0)
                    break;
                // cout<<(char)(97+ll)<<" : ";
                // for(int j=0;j<v[ll].size();j++)
                //     cout<<v[ll][j]<<" ";
                // cout<<endl;
            }
            if(flag)
                break;
        }
        if(ans==n)
            ans = -1;
        cout << ans << endl;
    }
}

/*

0 2
1 3 4
6
5 8
7

*/