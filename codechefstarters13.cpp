// #include </Users/bits/stdc++.h>
// using namespace std;

// vector <int> primeFactors(int n)
// {
//     vector <int> v;
//     while (n%2 == 0)
//     {
//         v.push_back(2);
//         n = n/2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i+2)
//     {
//         int f = 0;
//         while (n%i == 0)
//         {
//             if(!f){
//                 v.push_back(i);
//                 f = 1;
//             }
//             n = n/i;
//         }
//     }
//     if (n > 2)
//         v.push_back(n);
//     return v;
// }

// int main(){
//     int T;
//     cin>>T;
//     while(T-->0){
//         int n;
//         cin>>n;
//         int a[n+1];
//         for(int i=0;i<n;i++)
//             cin>>a[i+1];
//         long long int ans = 0;
//         vector < vector <int> > map(100000+1);
//         for(int i=1;i<=n;i++){
//             vector <int> v = primeFactors(a[i]);
//             for(int j=0;j<v.size();j++)
//                 map[v[j]].push_back(i);
//         }
//         for(int i=1;i<=n;i++){
//             vector <int> v = primeFactors(a[i]);
//             for(int j=0;j<v.size();j++){
                
//             }
//         }
//         cout<<ans<<endl;
//     }
// }

// /*

// 3   9   14  6   10
// 1   0   1   0   0
// 2   0   2   0   0
// 3   1   2   0   0
// 4   


// 3 14    3 10    9 14    9 10    14 6    6 10

// */

#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int>a(n),b(n),s(n);
        vector < vector <int> > aa(100000+1);
        for(int i=0;i<n;i++){
            cin>>a[i];
            aa[a[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
            cin>>b[i];
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            s[i] = sum;
        }
        int swaps = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i]==b[i])
                continue;
            int x = aa[b[i]].back();
            aa[b[i]].pop_back();

        }
    }
}