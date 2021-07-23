// LFU => it stands for least frequently used
// whenver the cache gets full the block with the least frequency is replaced with new value
// it must support two operations 
// 1. get(string key)
// 2. put(string key,string value)

// we will need a hashmaps
// hashmap-1 => This will store the [key ,{value,frequency}]

// whenever a put call is made the map will be checked if not found a new key will be inserted with frequency 1
// but we need to check the capacity too for that we need to have the keys with minimum frequency
// for this we need another map that stores 

// hashmap-2 => store [freq,[key1, key2, key3]]
// Now this map will store freq along with a list of keys corresponding to that frequency

// put call=>

// put(key,value)
// 1. if key is present =>
    // a) update frequency.  
    // b) update value.
// 2. if key is not present => 
    // a)add a new key in map 1
    // b)insert the key in map 2 in frequency 1;


// get (key)
// if key is not present return NULL;
// if key is present
// a. return the value
// b. take the freq. from map-1
// c. delete the key mapped with freq. from map-2
// d. add the key mapped with freq. + 1 in map-2

// special case -> in put if the capacity == maxCapacity
// we need to remove the key with min. Freq.
// we can traverse the entire map-1 to find minimum key but if we store it in a variable we can reduce the time complexity
// we will now remove the first item from the list of keys and insert the new key in the last;

// we can further reduce the complexity by taking another hashmap-3

// hashmap-3  [key,iterator_to_keyList_map_2]

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
    unordered_map<int,vector<int>>key_value_freq;//[key,{value,frequency}]
    unordered_map<int, list<int>> freq_keylist;
    unordered_map<int, list<int>::iterator>key_listIterator;
    int min_freq;
    int size;
    int c;
    LFUCache(int capacity){
        this->c = capacity;
        this->min_freq = 0;
        this->size = 0;
    }
    int get(int key){
        if(!key_value_freq.count(key)) return -1;
        else
        {
            int value = key_value_freq[key][0];
            int freq = key_value_freq[key][1];

            //remove the key from freq. and add to freq+1;
            auto it = key_listIterator[key];
            freq_keylist[freq].erase(it);
            freq_keylist[freq+1].push_back(key);

            key_listIterator[key] = --freq_keylist[freq+1].end();

            if(!freq_keylist[min_freq].size()) min_freq++;
            return value;
        }
    }
    void put(int key, int value)
    {
        if(c<=0) return;
        //update key value
        if(get(key)!=-1)
        {
            key_value_freq[key][0] = value;
            return;
        }
        if(c==size){
            //remove the min.freq. key and add new key
            int key = freq_keylist[min_freq].front();
            freq_keylist[min_freq].pop_front();
            key_value_freq.erase(key);
            key_listIterator.erase(key);
        }
        key_value_freq[key] = {value,1};
        freq_keylist[1].push_back(key);
        key_listIterator[key] = --freq_keylist[1].end();//pointer to last element
        min_freq = 1;
        if(size<c)size++;
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
c.put(1,1);
c.put(2,2);
c.put(3,1);
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