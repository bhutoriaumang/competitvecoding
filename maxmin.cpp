#include </Users/bits/stdc++.h>
using namespace std;

int c1,c2;

void bruteforce(long long int a[],long long int n){
    long long int ma=0,mi=0;
    for(long long int i=0;i<n;i++){
        c1++;
        if(a[i]<a[mi])
            mi = i;
        if(a[i]>a[ma])
            ma = i;
    }
    cout<<"By brute force method\t|\tMin element is : "<<a[mi]<<"\tMax element is : "<<a[ma]<<endl;
}

pair<long long int,long long int> divconq(long long int a[],long long int i,long long int j){
    if(i==j)
        return make_pair(a[i],a[i]);
    c2++;
    long long int m = (i+j)/2;
    pair <long long int,long long int> x = divconq(a,i,m);
    pair <long long int,long long int> y = divconq(a,m+1,j);
    pair <long long int,long long int> ans = make_pair(((x.first<y.first)?x.first:y.first),((x.second>y.second)?x.second:y.second));
    return ans;
}

int main(){
    int v[] = {100,200,400,1000,10000};
    srand(time(0));
    for(int i=0;i<5;i++){
        long long int n = v[i];
        long long int a[n];
        c1 = 0;
        c2 = 0;
        for(long long int i=0;i<n;i++){
            a[i] = rand();
        }
        bruteforce(a,n);
        pair <long long int,long long int> ans = divconq(a,0,n-1);
        cout<<"By divide and conquer \t|\tMin elemnt is : "<<ans.first<<"\tMax element is : "<<ans.second<<endl;
        cout<<"For "<<v[i]<<" comparisons :\n";
        cout<<"Number of comparisons made in brute force method is :\t"<<c1<<endl;
        cout<<"Number of comparisons made in divide and counquer method is :\t"<<c2<<endl<<endl<<endl;
    }
}