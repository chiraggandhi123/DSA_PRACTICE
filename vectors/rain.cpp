// https://leetcode.com/problems/trapping-rain-water/
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
int findRainWater(std::vector<int> v)
{
	int n = v.size();
	std::vector<int> right(n);
	std::vector<int> left(n);
	left[0] = v[0];
	// iterate from left 
	for(int i=1;i<v.size();i++)
	{
		left[i] = max(left[i-1],v[i]);
	}
	// //iterate from right
	right[v.size()-1] = v[v.size()-1];

	for(int i=v.size()-2;i>=0;i--)
	{
		right[i] = max(right[i+1],v[i]);
	}
	
	int totalWater = 0;
	for(int i=0;i<left.size();i++)
	{
		totalWater += min(left[i],right[i])-v[i];
	}
	return totalWater;
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
int n;
cin>>n;
std::vector<int> input;
while(n--)
{
	int x;
	cin>>x;
	input.push_back(x);
}

cout<<findRainWater(input);
return 0;
}