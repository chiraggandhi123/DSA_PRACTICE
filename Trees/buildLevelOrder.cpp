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
		node(int d)
		{
			this->data = d;
			this-> left = NULL;
			this->right = NULL;
		}
};
void levelOrderPrint(node * root){

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
node* levelOrderBuild(){
	int d;
	cin>>d;
	node* root = new node(d);//1
	queue<node*>q;//2 3
	q.push(root);
	while(!q.empty())
	{
		int c1,c2;
		cin>>c1>>c2;//4 5 6
		
		node* temp = q.front();//1
		q.pop();
		if(c1!=-1)
		{
			node* ln = new node(c1);
			temp->left = ln;
			q.push(ln); 
		}
		else
		{
			temp->left = NULL;
		}
		if(c2!=-1)
		{
			node* rn = new node(c2);
			temp->right = rn; 
			q.push(rn);
		}
		else
		{
			temp->right = NULL;
 		}
 		// cout<<temp->data<<endl;
 		// cout<<temp->left->data<<" "<<temp->right->data<<endl;
	}
	return root;
	//                1
	//              2   3
	//            4  5    6
	//                 7
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
node* root = levelOrderBuild();
// cout<<root->right->data;
levelOrderPrint(root);
return 0;
}