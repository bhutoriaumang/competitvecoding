#include <iostream>
using namespace std;

class length{
    private:
    int feet,inch;
    public:
    length(){
        feet=0;
        inch=0;
    }

    length* operator -(int t){//ob t=5
        feet-=t;
        inch-=t;
        return this;
    }

    friend ostream& operator <<(ostream &out, length &l);
    friend istream& operator >>(istream &in, length &l);
};

ostream& operator <<(ostream &out,length &l){
    out<<l.feet<<" feet and "<<l.inch<<" inches"<<endl;
    return out;
}

istream& operator >>(istream &in,length &l){
    cout<<"Enter the length in feets and inches : ";
    in>>l.feet>>l.inch;
    return in;
}

int main(){
    length ob;
    cin>>ob;
    cout<<ob;
    ob = *(ob-5);
    cout<<ob;
}