#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
int maxSum = INT_MIN;
/* clang-format on */
// int findMax(vector<int> arr, int n)
// {
//     // 1. represent it in turms of index
//     //[1,2,3,1]
//     //  0,1,2,3

//     // 2. Do stuff on index
//     // for f(n) I will get the maximum of sum for adjacant houses
//     // base case if I am at house (zero) I can rob the 0th and 2nd house if exists
//     if (n < 0)
//     {
//         return 0;
//     }
//     int maxSum = INT_MIN;
//     for (int i = n - 1; i >= 0; i++)
//     {
//         int val = findMax(arr, i -);
//         if (val > maxSum)
//         {
//             maxSum = val;
//         }
//     }
//     return maxSum;
//     // 3. take max of all stuffs
// }
/* Main()  function */
// void subseq(vector<int> arr, int i, int n, vector<int> sub)
// {
//     if (i >= n)
//     {
//         for (int i = 0; i < sub.size(); i++)
//         {
//             cout << sub[i];
//         }
//         cout << endl;
//         return;
//     }

//     // include the element
//     sub.push_back(arr[i]);
//     subseq(arr, i + 1, n, sub);

//     // exclude the element
//     sub.pop_back();
//     subseq(arr, i + 1, n, sub);
// }
void subseq(vector<int> arr, int n, int i, vector<int> sub, int sum)
{
    // cout << i << " " << arr[i] << endl;
    if (i >= n)
    {
        if (maxSum <= sum)
        {
            maxSum = sum;
        }
        return;
    }
    sub.push_back(arr[i]);
    subseq(arr, n, i + 2, sub, sum + arr[i]);
    sub.pop_back();
    subseq(arr, n, i + 1, sub, sum);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> sub;
    subseq(arr, arr.size(), 0, sub, 0);
    cout << maxSum;
    return 0;
}
/* Main() Ends Here */