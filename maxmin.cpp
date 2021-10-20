#include </Users/bits/stdc++.h>
using namespace std;
#define pll pair <long long int,long long int> 
#define lli long long int

int c1,c2;

void bruteforce(lli a[],int n){//Brute force method to find the min and max of an array
    lli ma=0,mi=0;
    for(lli i=0;i<n;i++){
        c1+=2;
        if(a[i]<a[mi])
            mi = i;
        if(a[i]>a[ma])
            ma = i;
    }
    cout<<"By brute force method\t|\tMin element is : "<<a[mi]<<"\tMax element is : "<<a[ma]<<endl;
}

pll divconq(lli a[],lli i,lli j){//Divide and conquer method to find the min and max of an array
    if(i==j)
        return make_pair(a[i],a[i]);
    c2+=2;
    long long int m = (i+j)/2;
    pll x = divconq(a,i,m);
    pll y = divconq(a,m+1,j);
    pll ans = make_pair(((x.first<y.first)?x.first:y.first),((x.second>y.second)?x.second:y.second));
    return ans;
}

int main(){
    int v[] = {100,200,400,1000,10000};
    srand(time(0));
    for(int i=0;i<5;i++){
        int n = v[i];
        lli a[n];
        cout << "For "<<n<<" elements :\n";
        c1 = 0;
        c2 = 0;
        for(lli i=0;i<n;i++){
            a[i] = rand();//Building my randomized array
        }
        bruteforce(a,n);
        pll ans = divconq(a,0,n-1);
        cout<<"By divide and conquer \t|\tMin elemnt is : "<<ans.first<<"\tMax element is : "<<ans.second<<endl;
        cout<<"Number of comparisons made in brute force method is :\t"<<c1<<endl;
        cout<<"Number of comparisons made in divide and counquer method is :\t"<<c2<<endl<<endl;
    }
}