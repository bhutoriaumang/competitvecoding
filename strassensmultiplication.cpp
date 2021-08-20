#include </Users/bits/stdc++.h>
using namespace std;

vector <vector <int> > add(vector <vector <int> > a, vector <vector <int> > b){
    vector <vector <int> > v;
    for(int i=0;i<a.size();i++){
        vector <int> t;
        for(int j=0;j<a.size();j++)
            t.push_back(a[i][j]+b[i][j]);
        v.push_back(t);
    }
    return v;
}

vector <vector <int> > substract(vector <vector <int> > a, vector <vector <int> > b){
    vector <vector <int> > v;
    for(int i=0;i<a.size();i++){
        vector <int> t;
        for(int j=0;j<a.size();j++)
            t.push_back(a[i][j]-b[i][j]);
        v.push_back(t);
    }
    return v;
}

vector <vector <int> > strassens_multiplication(vector <vector <int> > a, vector <vector <int> > b,int r,int c,int n){
    if(n==2){
        int p1 = (a[0][0]*b[0][1]) - (a[0][0]*b[1][1]);
        int p2 = (a[0][0]*b[1][1]) + (a[0][1]*b[1][1]);
        int p3 = (a[1][0]*b[0][0]) + (a[1][1]*b[0][0]);
        int p4 = (a[1][1]*b[1][0]) - (a[1][1]*b[0][0]);
        int p5 = (a[0][0]*b[0][0]) + (a[0][0]*b[1][1]) + (a[1][1]*b[0][0]) + (a[1][1]*b[1][1]);
        int p6 = (a[0][1]*b[1][0]) + (a[0][1]*b[1][1]) - (a[1][1]*b[1][0]) - (a[1][1]*b[1][1]);
        int p7 = (a[0][0]*b[0][0]) + (a[0][0]*b[0][1]) - (a[1][0]*b[0][0]) - (a[1][0]*b[0][1]);
        vector <vector <int> > v;
        vector <int> t;
        t.push_back(p6+p5+p4-p2);
        t.push_back(p1+p2);
        v.push_back(t);
        t.clear();
        t.push_back(p3+p4);
        t.push_back(p1+p5-p3-p7);
        v.push_back(t);
        t.clear();
        return v;
    }
    else{
        vector <vector <int> > A,B,C,D,E,F,G,H,P1,P2,P3,P4,P5,P6,P7,X,Y,W,Z,v;
        for(int i=0;i<n/2;i++){
            vector <int> t;
            for(int j=0;j<n/2;j++)
                t.push_back(0);
            A.push_back(t);
            B.push_back(t);
            C.push_back(t);
            D.push_back(t);
            E.push_back(t);
            F.push_back(t);
            G.push_back(t);
            H.push_back(t);
        }
        for(int i=0;i<n;i++){
            vector <int> t;
            for(int j=0;j<n;j++)
                t.push_back(0);
            v.push_back(t);
        }
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                A[i][j] = a[i][j];
                B[i][j] = a[i][j+n/2];
                C[i][j] = a[i+n/2][j];
                D[i][j] = a[i+n/2][j+n/2];
                E[i][j] = b[i][j];
                F[i][j] = b[i][j+n/2];
                G[i][j] = b[i+n/2][j];
                H[i][j] = b[i+n/2][j+n/2];
            }
        }
        P1 = substract(strassens_multiplication(A,F,0,0,n/2),strassens_multiplication(A,H,0,0,n/2));
        P2 = add(strassens_multiplication(A,H,0,0,n/2),strassens_multiplication(B,H,0,0,n/2));
        P3 = add(strassens_multiplication(C,E,0,0,n/2),strassens_multiplication(D,E,0,0,n/2));
        P4 = substract(strassens_multiplication(D,G,0,0,n/2),strassens_multiplication(D,E,0,0,n/2));
        P5 = add(add(strassens_multiplication(A,E,0,0,n/2),strassens_multiplication(A,H,0,0,n/2)),add(strassens_multiplication(D,E,0,0,n/2),strassens_multiplication(D,H,0,0,n/2)));
        P6 = substract(add(strassens_multiplication(B,G,0,0,n/2),strassens_multiplication(B,H,0,0,n/2)),add(strassens_multiplication(D,G,0,0,n/2),strassens_multiplication(D,H,0,0,n/2)));
        P7 = substract(add(strassens_multiplication(A,E,0,0,n/2),strassens_multiplication(A,F,0,0,n/2)),add(strassens_multiplication(C,E,0,0,n/2),strassens_multiplication(C,F,0,0,n/2)));
        W = add(P6,add(P5,substract(P4,P2)));
        X = add(P1,P2);
        Y = add(P3,P4);
        Z = add(P1,substract(P5,add(P3,P7)));
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                v[i][j] = W[i][j];
                v[i][j+n/2] = X[i][j];
                v[i+n/2][j] = Y[i][j];
                v[i+n/2][j+n/2] = Z[i][j];
            }
        }
        return v;
    }
}

int main(){
    int n;
    cin>>n;
    vector <vector <int> > a,b,ans;
    for(int i=0;i<n;i++){
        vector <int> t(n);
        for(auto &j : t)
            cin>>j;
        a.push_back(t);
    }
    for(int i=0;i<n;i++){
        vector <int> t(n);
        for(auto &j : t)
            cin>>j;
        b.push_back(t);
    }
    ans = strassens_multiplication(a,b,0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<ans[i][j]<<"\t";
        cout<<endl;
    }
}