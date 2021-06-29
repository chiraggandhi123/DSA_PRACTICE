//Problem statement -> given an array of integers. find one distinct pair whose sum is equal to S.
// arr = [10, 5, 3, -6, 11] Sum = 4

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
#include <unordered_set>
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

vector<int> pairSum(std::vector<int> v,int sum){
	unordered_set<int>s;
	std::vector<int> result;
	for(int x: v)
	{
		int diff = sum - x;

		if(s.find(diff)!=s.end())//if diff is int set
			{
				result.push_back(x);
				result.push_back(diff);
				return result;
			}
		s.insert(x);
	}
	return {};
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
std::vector<int> v = {-6,2,3,5,10,13};
int sum = 4;
std::vector<int> out = pairSum(v,sum);
for(int x:out)
{
	cout<<x<<" ";
}
return 0;
}