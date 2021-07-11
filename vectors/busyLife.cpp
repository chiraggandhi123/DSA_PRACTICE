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
int busyLife(vector<pair<int,int>>mp)
{
sort(mp.begin(), mp.end(),[&](pair<int,int>a,pair<int,int> b){
return a.second<b.second;
});
int cnt = 1;
int first_ending_time = mp[0].second;
for(int i=1;i<mp.size();i++)
{
	if(first_ending_time<=mp[i].first)
	{
		cnt++;
		first_ending_time = mp[i].second;
	}
}
return cnt;
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
vector<pair<int,int>>mp;		
int n;
cin>>n;
while(n--)
{
	int x;
	int y;
	cin>>x>>y;
	mp.push_back({x,y});
}
int count = busyLife(mp);
cout<<count;

return 0;
}
// 4 5
// 5 7
// 7 9
// 8 9
// 0 10
// 4 10
