#include </Users/bits/stdc++.h>
using namespace std;

void display(deque <int> x){
    while(x.size()>0){
        cout<<x.front()<<" ";
        x.pop_front();
    }
    cout<<endl;
}

void displayvec(vector <int> x){
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n),a(n+1,0),ans;
        deque <int> f;
        for(int i=0;i<n;i++){
            cin>>v[i];
            a[v[i]]++;
        }
        for(int i=0;i<=n;i++){
            if(a[i]==0)
                f.push_back(i);
        }
        int prevmin = f.front();
        while(v.size()!=0){
            int count = f.front(),t=f.front();
            ans.push_back(count);
            vector <int> temp(count+1,0);
            int k = 0;
            for(int i=0;i<v.size();i++){
                k++;
                a[v[i]]--;
                if(v[i]<t && temp[v[i]]==0){
                    temp[v[i]]=1;
                    if(a[v[i]]==0 && v[i]<prevmin){
                        f.push_front(v[i]);
                        prevmin = v[i];
                    }
                    if(v[i]<t)
                        count--;
                }
                if(count==0)
                    break;
            }
            v.erase(v.begin(),v.begin()+k);
            temp.clear();
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}