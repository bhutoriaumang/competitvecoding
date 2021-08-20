#include <iostream>
using namespace std;

class Complex{
    private:
    int r,i;
    public:
    Complex operator +(Complex b){
        Complex t;
        t.r = r+b.r;
        t.i = i+b.i;
        return t;
    }
    friend ostream& operator <<(ostream &out,const Complex &c);
    friend istream& operator >>(istream &in,Complex &c);
};

ostream& operator <<(ostream &out,const Complex &c){
    out<<c.r<<" + "<<c.i<<"i"<<endl;
    return out;
}

istream& operator >>(istream &in,Complex &c){
    cout<<"Enter the complex number : ";
    in>>c.r>>c.i;
    return in;
}

int main(){
    Complex c1,c2,c;
    cout<<"Enter the first complex number";
    cin>>c1;
    cout<<"Enter the second complex number";
    cin>>c2;
    cout<<"The first complex number is : ";
    cout<<c1;
    cout<<"The second complex number is : ";
    cout<<c2;
    c = c1+c2;
    cout<<"The resultant complex number is : ";
    cout<<c;
}