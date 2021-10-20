#include </Users/bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int n,Q;
        cin>>n>>Q;
	    vector <long long int> l(n);
	    vector < pair<long long int,int> > q(Q);
	    for(int i=0;i<n;i++)
	        cin>>l[i];
	    for(int i=0;i<Q;i++){
	        cin>>q[i].first;
	        q[i].second = i;
	    }
	    sort(l.begin(),l.end(),greater<long long int>());
	    sort(q.begin(),q.end(),greater< pair<long long int,int> >());
	    vector < pair<int,long long int> > ans;
	    int ii = 0;
        long long int x = 0;
	    for(int i=0;i<Q;i++){
	        while(ii<n && q[i].first<=l[ii])
	            ii++;
	        if(ii<n){
    	        long long int ll = n-ii-1;
    	        while(ii<n-x && (l[ii]+ll)>=q[i].first){
    	            x += (q[i].first-l[ii]);
                    ll-=x;
    	            ii++; 
                    cout<<x<<" "<<ll<<" "<<ii<<endl;
    	        }
	        }
	        ans.push_back(make_pair(q[i].second,ii));
	    }
	    sort(ans.begin(),ans.end());
	    for(int i=0;i<Q;i++)
	        cout<<ans[i].second<<endl;
	}
	return 0;
}