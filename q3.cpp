#include <iostream>
using namespace std;

class Candidate{
    private:
    int age;
    double height,chest;
    public:
    Candidate(){
        cout<<"Enter candidate's age:"<<endl;
        cin>>age;
        cout<<"Enter candidate's height:"<<endl;
        cin>>height;
        cout<<"Enter candidate's chest:"<<endl;
        cin>>chest;
    }
    inline bool fit(){
       return (height>=5.2 && height<=5.6)?(age>=18 && age<=25)?(chest>=45)?true:false:false:false;
    }
};

int main(){
    Candidate c;
    if(c.fit())
        printf("The candidate is fit for selection");
    else
        printf("Candidate is rejected");
}