#include <iostream>
#include <iomanip>
using namespace std;

class House{
    public:
    string name;
    string no;
    void input(){
        getline(cin,name);
        cin>>no;
    }
};

class Electricity : virtual public House{
    public:
    int etcu;
    double ercu;
    void inputElectricity(){
        cin>>etcu;
    }
    void calElectricity(){
        if(etcu<=100)
            ercu = 2.5;
        else if(etcu<=200){
            ercu = 3.5;
        }
        else if(etcu<=500)
            ercu = 4.6;
        else
            ercu = 6.6;
    }
};
class Water : virtual public House{
    public:
    int wtcu;
    double wrcu;
    void inputWater(){
        cin>>wtcu;
    }
    void calWater(){
        if(wtcu<=10)
            wrcu = 4;
        else if(wtcu<=15)
            wrcu = 16;
        else if(wtcu<=25)
            wrcu = 24;
        else
            wrcu = 40;
    }
};
class Gas : virtual public House{
    public:
    int gtcu;
    double grcu;
    void inputGas(){
        cin>>gtcu;
    }
    void calGas(){
        grcu = 85;
    }
};

class Bill : public Electricity,public Water,public Gas{
    public:
    double total;
    void cal(){
        total = etcu*ercu + wtcu*wrcu + gtcu*grcu;
    }
    void display(){
        cout<<fixed<<setprecision(2);
        cout<<"Name: "<<name<<endl;
        cout<<"House No: "<<no<<endl;
        cout<<"Electricity charge: "<<etcu*ercu<<endl;
        cout<<"Water Bill: "<<wtcu*wrcu<<endl;
        cout<<"GAS: "<<gtcu*grcu<<endl;
        cout<<"Total: "<<total<<endl;
    }
};

int main(){
    Bill b;
    b.input();
    b.inputElectricity();
    b.inputWater();
    b.inputGas();
    try{
        if(b.gtcu<8)
            throw -1;
    }
    catch(int e){
        cout<<"Invalid Gas unit"<<endl;
        exit(0);
    }
    b.calElectricity();
    b.calGas();
    b.calWater();
    b.cal();
    b.display();
}