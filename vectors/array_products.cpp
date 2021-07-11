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
std::vector<int> findProduct(std::vector<int> arr)
{//1 2 3 4 5 
//1 2 6 24 120
//120  120  60  20  5
int n = arr.size();
std::vector<int> left(n,1);
std::vector<int> right(n,1);
for(int i=1;i<n;i++)
{
	left[i] = arr[i]*left[i-1];
}

right[n-1] = arr[n-1];
for(int i=n-2;i>=0;i--)
{
	right[i] = right[i+1]*arr[i];
}

vector<int>ans;
for(int i=0;i<n;i++)
{
	if(i==0) ans.push_back(right[1]);
	else if(i==n-1) ans.push_back(left[n-2]);
	else
	ans.push_back(left[i-1]*right[i+1]);
}
return ans;
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

std::vector<int> arr;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	int x;
	cin>>x;
	arr.push_back(x);
}
std::vector<int> left(n,1);
std::vector<int> right(n,1);
std::vector<int> ans = findProduct(arr);
for(auto x:ans)
{
	cout<<x<<" ";
}
return 0;
}