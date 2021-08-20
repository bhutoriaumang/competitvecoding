#include <iostream>
using namespace std;

int sum;

void permute(string a, int l, int r)
{
	if (l == r){
        cout<<"{";
        for(int i=0;i<a.length()-1;i++)
            cout<<a[i]<<",";
        cout<<a[a.length()-1]<<"}"<<endl;
    }
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permute(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}
int main()
{
	string str,s;
    cin>>str;
    sum = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            s+=str[i];
            sum+=(int)str[i] - 48;
        }
    }
	int n = s.size();
	permute(s, 0, n-1);
    int fact = 1;
    while(n>0){
        fact*=n;
        n--;
    }
    cout<<sum*fact<<endl;
	return 0;
}