// given an array 
// 5 6 1 2 3 4 5 4 3 2 0 1 2 3 4 -2 4
// find peak which has maximum 
// example => peaks possible => 
// 6 => 1, 5 => 6 , 4 => 14
//   2       8         6
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
int findMountain(vector<int>v)
{
	std::vector<int> peaks,widths;
	// find peaks -> indices
	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i]>v[i-1] && v[i]>v[i+1])
		{
			peaks.push_back(i);
		}
	}

	// iterate left
	for(auto tempx:peaks)
	{
		//iterate left
		int j = tempx;
		while(j>=1 && v[j]>v[j-1])
		{
			j--;
		}
		int k = tempx;
		while(k<v.size()-1 && v[k]>v[k+1])
		{
			k++;
		}
		widths.push_back(k-j+1);


	}
	return *max_element(widths.begin(),widths.end());
	// return 0;
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
vector<int>input;
while(n--)
{
	int x;
	cin>>x;
	input.push_back(x);
}
int res = findMountain(input);
cout<<res;


return 0;
}