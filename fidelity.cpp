int count(int x,int d){
    int c=0;
    while(x>0){
        int digit = x%10;
        if(d==digit)
            c++;
    }
    return c;
}

int printResult(int N,int d){
    int x = pow(10,N-1),y=0;
    vector <int> arr;
    while(x<(pow(10,N))){
        if(!prime[x]){
            x++;
            continue;
        }
        int count - count(x,d);
        if(count>y){
            arr.clear();
            arr.push_back(x);
            y=count;
        }
        else if(count==y)
            arr.push_back(x);
        x++;
    }
    int ans = 0;
    for(int i=0;i<arr.size();i++)
        ans+=arr[i];
    return ans;
}