#include </Users/bits/stdc++.h>
using namespace std;

string binconv(int x){
    string w = "";
    while(x>0){
        w = to_string(x%2) + w;
        x/=2;
    }
    return w;
}

int calc(string x,string y,int c){
    if(c==-1)
        return 0;
    int k = 1,t=1;
    for(int i=x.length()-1;i>=0;i--){
        if(x[i]=='1' && y[i]=='0'){
            t+=k;
            cout<<"HI "<<t<<" "<<k<<endl;
        }
        k*=2;
    }
    cout<<x<<" "<<y<<" "<<c<<"  "<<t<<endl;
    if(x[c]==y[c])
        return calc(x,y,c-1);
    else if(x[c]>y[c]){
        cout<<x[c]<<" "<<y[c]<<" "<<(int)pow(2,x.length()-c-1)<<"    ";
        cout<<t<<" A\n";
        y = y.substr(0,c)+"1"+y.substr(c+1);
        return min(t,(int)pow(2,x.length()-c-1)+calc(x,y,c-1));
    }
    else{
        cout<<x[c]<<" "<<y[c]<<" "<<(int)pow(2,x.length()-c-1)<<"    ";
        cout<<t<<" B\n";
        x = x.substr(0,c)+"1"+x.substr(c+1);
        return min(t,(int)pow(2,x.length()-c-1)+calc(x,y,c-1));
    }
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int a,b;
        cin>>a>>b;
        string x = binconv(a);
        string y = binconv(b);
        while (x.length()<y.length())
        {
            x = "0"+x;
        }
        cout<<calc(x,y,x.length()-1)<<endl;
    }
}