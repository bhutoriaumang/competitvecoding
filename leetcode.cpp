#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	Node *l,*r;
	int v;
	vector <int> dist;
	Node(int v){
		this->v = v;
		l = NULL;
		r = NULL;
		dist = vector <int>();
	}
};

// void preorder(Node *x){
// 	if(x->l!=NULL){
// 		preorder(x->l);
// 	}
// 	cout<<x->v<<" : ";
// 	for(int i=0;i<x->dist.size();i++)
// 		cout<<x->dist[i]<<" ";
// 	cout<<endl;
// 	if(x->r!=NULL){
// 		preorder(x->r);
// 	}
// }

Node* create(vector <int> x,int i){
	if((2*(i+1))>=(int)x.size()){
		Node *n =  new Node(x[i]);
		n->l = NULL;
		n->r = NULL;
		return n;
	}
	else{
		Node *n = new Node(x[i]);
		n->l = create(x,2*(i+1)-1);
		n->r = create(x,2*(i+1));
		return n;
	}
}

void calc(Node *x){
    if(x->l==NULL)
        return;
	if(x->l->l==NULL){
		x->dist.push_back(x->l->v);
		x->dist.push_back(x->r->v);
		sort(x->dist.begin(),x->dist.end());
	}
	else{
		calc(x->l);
		calc(x->r);
		for(int i=0;i<(int)x->l->dist.size();i++)
			x->dist.push_back(x->l->dist[i] + x->l->v);
		for(int i=0;i<(int)x->r->dist.size();i++)
			x->dist.push_back(x->r->dist[i] + x->r->v);
		sort(x->dist.begin(),x->dist.end());
	}
}

int maximum(Node *x){
	if(x->l==NULL)
		return x->v;
	else{
		int a = x->dist[x->dist.size()-1];
		int b = x->dist[x->dist.size()-2];
		return max(a + b + x->v , max(maximum(x->l),maximum(x->r)));
	}
}

int main() {
	int T;
	cin>>T;
	while(T-->0){
		int n;
		cin>>n;
		vector <int> t(n);
		for(int i=0;i<n;i++)
			cin>>t[i];
		Node *root = create(t,0);
		calc(root);
		cout<<maximum(root)<<endl;
	}
}

/*

				2
		4				5
	8		-4		3		-6

8 4 -4 2 3 5 -6

*/