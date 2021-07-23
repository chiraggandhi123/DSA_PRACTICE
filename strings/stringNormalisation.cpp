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
#include <bits/stdc++.h>
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
void formatter(string &token)
{
	int i = 0;
	while(i<token.size())
	{
		if(i==0)
		{
				if(int(token[i])>=97 && int(token[i])<=122)
				token[i] = char(int(token[i])-32);
		
		}
		else
		{
			if(int(token[i])>=65 && int(token[i])<=90)
			token[i] = char(int(token[i])+32);
		
		}
		i++;
	}
}
string normalise(string s)
{
	//tokenise
	stringstream ss(s);
	string token;
	std::vector<string>tokens;
	while(getline(ss,token,' '))
	{
		formatter(token);

		tokens.push_back(token);
	}
	// cout<<'A'<<int('a')<<"Z"<<int('z');
	string out = "";
	for(auto x:tokens) out.append(x+" ") ;
	return out;
}
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
string s;
getline(cin,s);
string out = normalise(s);
cout<<out<<endl;
return 0;
}