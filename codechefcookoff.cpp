#include </Users/bits/stdc++.h>
using namespace std;

// int main(){
//     vector <int> v(6);
//     string s;
//     getline(cin,s);
//     for(int i=0;i<6;i++)
//         cin>>v[i];
//     int x=0,m=-1,ind=-1,mind=-1;
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='A' || s[i]=='B' || s[i]=='C' || s[i]=='D' || s[i]=='E' || s[i]=='F'){
//             if(x==0)
//                 ind = i;
//             x+= v[(int)s[i] - 65];
//         }
//         else{
//             if(x>m){
//                 mind = ind;
//                 m = x;
//             }
//             x = 0;
//             ind = -1;
//         }
//     }
//     cout<<mind<<"\t"<<m<<endl;
// }

// vector <int> prime(1000000+1,0);
// void SieveOfEratosthenes()
// {
//     int n = 1000000;
//     for (int p = 2; p * p <= n; p++)
//     {
//         if (prime[p] == 0)
//         {
//             for (int i = p + p; i <= n; i += p)
//                 prime[i]++;
//         }
//     }
// }

// bool DFS(vector <vector <int> > v,int x,int k,int n){
//     if(x==n)
//         return true;
//     bool f = false;
//     for(int i=1;i<v[x].size();i++){
//         if(v[x][i]>0 && prime[v[x][i]]==k)
//             f = f || DFS(v,i,k,n);
//         if(f)
//             return f;
//     }
//     return f;
// }

// int main(){
//     SieveOfEratosthenes();
//     int n,k,p;
//     cin>>n>>k>>p;
//     vector < vector <int> > v(n+1,vector<int>(n+1,0));
//     for(int i=0;i<p;i++){
//         int x,y,d;
//         cin>>x>>y>>d;
//         v[x][y] = d;
//     }
//     cout << ((DFS(v,1,k,n))?"YES":"NO") << endl;
// }