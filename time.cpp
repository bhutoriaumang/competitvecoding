#include <iostream>
using namespace std;

class Time{
    private:
    int h,m;
    public:
    void getValue(){
        cout<<"Enter the time in hours and minutes: ";
        cin>>h>>m;
    }
    int check(){
        if(h>23 || h<0 || m>59 || m<0)
            return 0;
        return 1;
    }
    Time operator +(Time t){
        Time res;
        res.h = (h+t.h)%24;
        res.m = (m+t.m);
        res.h+= (int)res.m/60;
        res.m%=60;
        return res;
    }
    void display(){
        cout.fill('0');
        cout.width(2);
        cout<<h<<" : ";
        cout.width(2);
        cout<<m<<endl;
    }
};

int main(){
    Time t1,t2;
    t1.getValue();
    t2.getValue();
    t1.display();
    t2.display();
    (t1+t2).display();
}