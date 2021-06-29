// You are given an array and need to find the triplet that sums up to k.
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
vector<vector<int>> pairRes(vector<int> v, int sum,int a)
{
	vector<vector<int>>temp;
	int i=0;
	int j=v.size()-1;
	while(i<j)
	{
		if(v[i]+v[j]<sum)
		{
			i++;
		}
		else if(v[i]+v[j]>sum)
		{
			j--;
		}
		else
		{
			temp.push_back({a,v[i],v[j]});
			i++;
			j--;
		}
	}
	return temp;
}


vector<vector<int>> tripletSum(vector<int>v, int sum)
{
	vector<vector<int>>res;
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++)
	{
		vector<vector<int>>temp = pairRes(v,sum-v[i],v[i]);
		for(auto x:temp)
		{
			res.push_back(x);
		}
	}
	return res;
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
std::vector<int> input;
int n;
cin>>n;
while(n--)
{
	int x = 0;
	cin>>x;
	input.push_back(x);
}
int sum = 0;
cin>>sum;
vector<vector<int>>output = tripletSum(input, sum);
cout<<"=============="<<endl;
//[
// [
// [1,2,3],[2,3,1]
// ],
// [[1,2,3],[2,3,1]]
// ]
for(vector<int>row: output)
{
	for(int col:row)
	{
		cout<<col<<" ";
	}
	cout<<endl;
}

return 0;
}