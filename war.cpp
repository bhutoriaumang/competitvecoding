#include </Users/bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector <long long int> x,rank,enemies;
    long long int num;
    DSU(int n){
        x.assign(n,0);
        for(int i=0;i<n;i++){
            x[i] = i;
        }
        rank.assign(n,0);
        enemies.assign(n,-1);
        num = n;
    }
    long long int findSet(int i){
        if(x[i]==i)
            return i;
        else
        {
            x[i] = findSet(x[i]);
            return x[i];
        }
    }
    bool areFriends(int i, int j){
        return (findSet(i)==findSet(j));
    }
    bool areEnemies(int i, int j){
        i = findSet(i);
        j = findSet(j);
        return (i==enemies[j] || j==enemies[i]);
    }
    void Union(int i,int j){
        if(areFriends(i,j))
            return;
        int a = findSet(i);
        int b = findSet(j);
        if(rank[a]>rank[b])
            swap(a,b);
        x[a] = b;
        if(rank[a]==rank[b])
            rank[b]++;
        num--;
    }
};

int main(){
    fstream file;
    string filename = "warinput.txt";
    file.open(filename.c_str());
    int n;
    string s;
    file>>n;
    vector < vector<long long int> > v;
    while(getline(file,s)){
        vector <long long int> tokens;
        stringstream check1(s);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(stoi(intermediate));
        }
        v.push_back(tokens);
    }
    v.pop_back();
    DSU friends(n);
    for(int i=1;i<v.size();i++){
        int a,b,c;
        for(int j=0;j<v[i].size();j+=3){
            a = v[i][j];
            b = v[i][j+1];
            c = v[i][j+2];
        } 
        if(a==1){
            b = friends.findSet(b);
            c = friends.findSet(c);
            if(friends.areEnemies(b,c))
                cout<<"-1\n";
            else if(friends.areFriends(b,c))
                continue;
            else if(friends.enemies[b]==-1 && friends.enemies[c]==-1)
                friends.Union(b,c);
            else if(friends.enemies[b]!=-1 && friends.enemies[c]==-1){
                int z = friends.enemies[b];
                friends.Union(b,c);
                b = friends.findSet(b);
                friends.enemies[z] = b;
                friends.enemies[b] = z;
            }
            else if(friends.enemies[b]==-1 && friends.enemies[c]!=-1){
                int z = friends.enemies[c];
                friends.Union(b,c);
                c = friends.findSet(c);
                friends.enemies[z] = c;
                friends.enemies[c] = z;
            }
            else{
                int x = friends.enemies[b];
                int y = friends.enemies[c];
                friends.Union(b,c);
                friends.Union(x,y);
                x = friends.findSet(x);
                b = friends.findSet(b);
                friends.enemies[b] = x;
                friends.enemies[x] = b;
            }
        }
        else if(a==2){
            b = friends.findSet(b);
            c = friends.findSet(c);
            if(friends.areFriends(b,c))
                cout<<"-1\n";
            else if(friends.enemies[b]==(c) && friends.enemies[c]==b)
                continue;
            else if(friends.enemies[b]==-1 && friends.enemies[c]==-1){
                friends.enemies[b] = c;
                friends.enemies[c] = b;
            }
            else if(friends.enemies[b]!=-1 && friends.enemies[c]==-1){
                int z = friends.enemies[b];
                friends.Union(z,c);
                int x = friends.findSet(c);
                friends.enemies[x] = b;
                friends.enemies[b] = x;
            }
            else if(friends.enemies[b]==-1 && friends.enemies[c]!=-1){
                int z = friends.enemies[c];
                friends.Union(z,b);
                int x = friends.findSet(b);
                friends.enemies[x] = c;
                friends.enemies[c] = x;
            }
            else{
                int x = friends.enemies[b];
                int y = friends.enemies[c];
                friends.Union(x,c);
                friends.Union(y,b);
                b = friends.findSet(b);
                c = friends.findSet(c);
                friends.enemies[b] = c;
                friends.enemies[c] = b;
            }
        }
        else if(a==3){
            cout<<((friends.areFriends(b,c)?"1":"0"))<<endl;
        }
        else
            cout<<((friends.areEnemies(b,c)?"1":"0"))<<endl;
    }
}