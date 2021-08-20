#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int cas = 1;cas<=t;cas++){
        int n;
        cin>>n;
        vector <long long int> v,x,y,ans;
        for(int i=0;i<n;i++){
            long long int temp;
            cin>>temp;
            v.push_back(temp);
            if(i%2==0)
                x.push_back(temp);
            else
                y.push_back(temp);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int l=0,k=0,f=-1;
        // for(int i=0;i<n;i++){
            
        //     if(i%2==0 && (l>=x.size() || x[l]>y[k])){
        //         f = i;
        //         break;
        //     }
        //     else if(i%2==1 && (k>=y.size() || x[l]<y[k])){
        //         f = i;
        //         break;
        //     }
        //     if(i%2==0)
        //         l++;
        //     else
        //         k++;
        // }
        for(int i=0;i<n;i++){
            if(i%2==0)
                ans.push_back(x[l++]);
            else
                ans.push_back(y[k++]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i]!=ans[i]){
                f = i;
                break;
            }
        }
        cout<<"Case #"<<cas<<": "<<((f==-1)?"OK":to_string(f))<<"\n";
    }
}

