#include <iostream>
using namespace std;

class Base{
	public:
	string name,reg;
	int age;
	void input(){
		cin>>name>>reg>>age;
	}
	void display(){
		cout<<"Name : "<<name<<endl;
		cout<<"Reg : "<<reg<<endl;
		cout<<"Age : "<<age<<endl;
	}
};

class Derived : public Base{
	public:
	int m[5];
	void percentage(){
		int sum = 0;
		input();
		for(int i=0;i<5;i++){
			cin>>m[i];
			sum+=m[i];
		}
		display();
		cout<<"Percentage : "<<(sum*100)/500<<"%"<<endl;
	}
};

int main(){
	Derived ob;
	ob.percentage();
}