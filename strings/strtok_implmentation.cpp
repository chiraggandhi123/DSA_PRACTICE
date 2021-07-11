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
char *myStrtok(char* str, char delim)
{
	static char* input = NULL;//this static variable will store the state of pointer currently pointing to str
	if(str!=NULL)
	{
		input = str;
	}
	if(input==NULL) return NULL;
	char* token = new char[strlen(str)+1];
	int i = 0;
	for(;input[i]!='\0';i++)
	{
		if(input[i]!=delim)
		{
			token[i] = input[i];
		}
		else
		{
			token[i] = '\0';
			input = input+i+1;//moving pointer to a new position
			return token;
		}
	} 
	token[i] = '\0';
	input = NULL;
	return token;
}

int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
char str[1000];
cin.getline(str,1000);
std::vector<string> result;
char *token = myStrtok(str,' ');
while(token!=NULL)
{
cout<<token<<" ";
	token = myStrtok(NULL,' ');

}

return 0;
}