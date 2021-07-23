// we want the output to be 
// 1
// 2 3
// we will be using queue data structure
// 1. It stores the visited node
// 2. It helps maintain the FIFO ordering

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
node* buildTree(){
	int d;
	cin>>d;

	if(d==-1) return NULL;

	node* n = new node(d);
	n->left =  buildTree();
	n->right = buildTree();
	return n;
}
void printLevelTree(node* root)
{
queue<node*>q;
q.push(root);
q.push(NULL);
	while(!q.empty())
	{
		node* data = q.front();
		q.pop();
		if(data==NULL && !q.empty())
		{
			cout<<"\n";
			q.push(NULL);
		}
		else if(data==NULL && q.empty()) cout<<"\n";
		else
		{
			cout<<data->data;
			if(data->left!=NULL)q.push(data->left);
			if(data->right!=NULL)q.push(data->right);
		}
	}

}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


node* root = buildTree();
printLevelTree(root);
return 0;
}