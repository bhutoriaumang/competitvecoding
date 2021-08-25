#include </Users/bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t-->0){
	    int n;
	    cin>>n;
	    vector <string> v;
	    string w = "";
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        v.push_back(s);
	    }
	    if(n==1){
	        if(v[0][0]=='0')
	            cout<<"1\n";
	        else
	            cout<<"0\n";
	        continue;
	    }
	    sort(v.begin(),v.end());
        int l=0,u=n-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<v.size();j++){
                if(v[j][i]=='0')
                    c++;
            }
            if(c==0){
                while(w.length()!=n)
                    w+='0';
                break;
            }
            if(c==(v.size())){
                while(w.length()!=n)
                    w+='1';
                break;
            }
            if(c > (v.size()/2)){
                w+='1';
                v.erase(v.begin(),v.begin()+c);
            }
            else{
                w+='0';
                v.erase(v.begin()+c,v.end());
            }
            // for(int j=0;j<v.size();j++)
            //     cout<<v[j]<<"\t";
            // cout<<endl<<w<<endl;
        }
        cout<<w<<endl;
	}
	return 0;
}