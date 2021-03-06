// lru cache implementation

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
#include <unordered_map>
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
class LRUCache{
public:
	list<pair<int,int>>key_value;
	unordered_map<int,list<pair<int,int>>::iterator>key_iterator;
	int maxCap;
	int size;
	LRUCache(int capacity){
		maxCap = capacity;
		size = 0;
	}

	void put(int key, int value)
	{
		if(maxCap<=0) return;
		if(maxCap==size)
		{
			int key_to_be_removed = key_value.front().first;
			key_value.pop_front();
			key_iterator.erase(key_to_be_removed);
		}
		key_value.push_back({key,value});
		key_iterator[key] = --key_value.end();
		if(size<maxCap) size++;
	}
	int get(int key)
	{
		if(!key_iterator.count(key)) return -1;
		else
		{
			auto it = key_iterator[key];
			key_value.erase(it);
			key_value.push_back(*it);
			key_iterator[key] = --key_value.end();
			return key_value.back().second;
		}
	}	

};
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
LRUCache c(2);
c.put(1,1);//1
c.put(2,2);//1<-2
cout<<c.get(1)<<endl;//2<-1
c.put(3,3);//1<-3
cout<<c.get(1)<<endl;//3<-1
cout<<c.get(2)<<endl;//-1
return 0;
}