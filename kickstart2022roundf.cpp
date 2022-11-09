#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<long long int>& v1, const vector<long long int>& v2)
{
    return (v1[0] < v2[0]) || (v1[0]==v2[0] && v1[1]>v2[1]);
}

int main(){
    long long int T;
    cin>>T;
    for(long long int cas=1;cas<=T;cas++){
        long long int d,n,x;
        cin>>d>>n>>x;
        vector < vector <long long int> > v(n,vector <long long int>(3));
        vector < vector < vector <long long int> > > t(d+1);
        for(int i=0;i<n;i++){
            cin>>v[i][2]>>v[i][1]>>v[i][0];
            v[i][1] = d-v[i][1]+1;
            t[v[i][1]].push_back(v[i]);
        }
        sort(t.begin(),t.end());
        // for(int i=1;i<=d;i++){
        //     cout<<i<<": ";
        //     sort(t[i].begin(),t[i].end(),greater < vector <long long int> > ());
        //     for(int j=0;j<t[i].size();j++)
        //         cout<<t[i][j][0]<<" "<<t[i][j][1]<<" "<<t[i][j][2]<<endl;
        //     cout<<endl;
        // }
        int k=0,ans=0;
        for(int i=1;i<=d;i++){
            int xx = -1;
            for(int j=i+1;j<=d;j++){
                if(t[j].size()<=1)
                    continue;
                if(xx==-1)
                    xx = j;
                else if(t[j][1][0]>t[xx][0][0])
                    xx = j;
            }
            // cout<<i<<" "<<t[d].size()<<endl;
            if(xx==-1 && t[i].size()>0)
                ans += t[i][0][0];
            else if(t[i].size()>0){
                if(t[i][0][0]>t[xx][1][0])
                    ans += t[i][0][0];
                else if(t[i][0][0]<t[xx][1][0]){
                    ans += t[xx][1][0];
                    t[xx].erase(t[xx].begin()+1);
                }
            }
        }
        // for(int i=1;i<=d;i++){
        //     if(k>=n)
        //         break;
        //     int xx = -1;
        //     for(int i=k;i<n;i++){
        //         if(xx==-1 && v[i][0]<=d && v[i][0]>=i)
        //             xx=i;
        //         else if(xx!=-1 && v[xx][1]<v[i][1] && v[i][0]<=d && v[i][0]>=i)
        //             xx=i;
        //     }
        //     if(xx!=-1)
        //         ans += v[xx][1];
        //     else
        //         break;
        //     cout<<v[xx][1]<<endl;
        //     v.erase(v.begin()+xx);
        //     while(k<v.size() && v[k][0]==i)
        //         k++;
        // }
        cout<<"Case #"<<cas<<": "<<ans<<"\n";
    }
}
// vector < vector <long long int> > v;
// for(long long int i=0;i<n;i++){
//     vector <long long int> temp(3);
//     cin>>temp[2];
//     cin>>temp[0];
//     cin>>temp[1];
//     temp[0] = d-temp[0];
//     v.push_back(temp);
// }
// long long int ans = 0;
// long long int k = 0;
// sort(v.begin(),v.end(),sortcol);
// // for(int i=0;i<n;i++)
// //     cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
// // cout<<"HI\n";
// for(int i=1;i<=d;i++){
//     long long int xx = x;
//     while(k<n && xx>0){
//         // cout<<i<<" : "<<xx<<endl;
//         // cout<<v[k][0]<<" "<<v[k][1]<<" "<<v[k][2]<<endl;
//         ans += min(xx,v[k][2])*v[k][1];
//         // cout<<ans<<endl;
//         int temp = v[k][2];
//         if(xx>=v[k][2])
//             k++;
//         else
//             v[k][2] -= xx;
//         xx = max((long long int)0,xx-temp);
//     }
//     while(k<n && v[k][0]==i)
//         k++;
// }