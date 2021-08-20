#include <iostream>
using namespace std;

class operations{
    private:
    int a,b;
    public:
    operations operator +(operations x){
        operations res;
        res.a = a*x.b + x.a*b;
        res.b = b*x.b;
        int t = gcd(res.a,res.b);
        res.a/=t;
        res.b/=t;
        return res;
    }
    operations operator -(operations x){
        operations res;
        res.a = a*x.b - x.a*b;
        res.b = b*x.b;
        int t = gcd(res.a,res.b);
        res.a/=t;
        res.b/=t;
        return res;
    }
    operations operator *(operations x){
        operations res;
        res.a = a*x.a;
        res.b = b*x.b;
        int t = gcd(res.a,res.b);
        res.a/=t;
        res.b/=t;
        return res;
    }
    operations operator /(operations x){
        operations res;
        res.a = a*x.b;
        res.b = b*x.a;
        int t = gcd(res.a,res.b);
        res.a/=t;
        res.b/=t;
        return res;
    }
    int gcd(int x,int y){
        int r;
        while(y!=0){
            r = x%y;
            x = y;
            y = r;
        }
        return x;
    }
    void fix(){
        int t = gcd(a,b);
        a/=t;
        b/=t;
    }
    friend ostream& operator <<(ostream &out,operations &c);
    friend istream& operator >>(istream &in,operations &c);
};

ostream& operator <<(ostream &out,operations &c){
    out<<c.a<<"/"<<c.b<<endl;
    return out;
}

istream& operator >>(istream &in,operations &c){
    in>>c.a>>c.b;
    try{
        if(c.b==0)
            throw "Zero denominator exception";
    }
    catch(const char *exception){
        cerr<<exception<<endl;
    }
    return in;
}


int main(){
    operations x,y,res;
    cin>>x;
    cin>>y;
    x.fix();
    y.fix();
    cout<<x;
    cout<<y;
    res = x+y;
    cout<<res;
    res = x-y;
    cout<<res;
    res = x*y;
    cout<<res;
    res = x/y;
    cout<<res;
}