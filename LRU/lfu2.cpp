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
class LFUCache{
public:
	unordered_map<int,std::vector<int>> key_freq_val;
	unordered_map<int,list<int>> freq_keyList;
	unordered_map<int,list<int>::iterator>key_listIterator;
	int maxCap;
	int size;
	int minFreq;

	LFUCache(int capacity)
	{
		this->maxCap = capacity;
		this->size = 0;
		this->minFreq = 0;
	}
	void put(int key, int value){
		if(maxCap<=0) return;

		if(get(key)!=-1) key_freq_val[key][1] = value;
		if(maxCap==size)
		{
			//remove the least frequent
			int key_to_be_removed = freq_keyList[minFreq].front();
			freq_keyList[minFreq].pop_front();
			key_freq_val.erase(key_to_be_removed);
			key_listIterator.erase(key_to_be_removed);
		}

		key_freq_val[key] = {value,1};
		freq_keyList[1].push_back(key);
		key_listIterator[key] = --freq_keyList[1].end();
		minFreq = 1;
		if(size<maxCap) size++;

	}
	int get(int key)
	{
		if(!key_freq_val.count(key)) return -1;
		
		int freq = key_freq_val[key][0];
		int value = key_freq_val[key][1];

		auto it = key_listIterator[key];
		freq_keyList[freq].erase(it);
		freq_keyList[freq+1].push_back(key);

		key_listIterator[key] = --freq_keyList[freq+1].end();
		if(!freq_keyList[1].size()) minFreq++;
		return value;



	}
};
int main()
{
fastIO
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
LFUCache c(2);


c.put(4,2);
c.put(5,1);
c.put(6,1);
cout<<c.get(1)<<endl;
cout<<c.get(2)<<endl;
cout<<c.get(3)<<endl;
cout<<c.get(4)<<endl;
cout<<c.get(5)<<endl;
cout<<c.get(6)<<endl;

return 0;
}