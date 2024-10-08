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

/* clang-format on */

/* Main()  function */
int ninjaTrainingTab(vector<vector<int>> v, vector<vector<int>> &dp)
{
    dp = v;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int maxVal = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    if (dp[i][k] > maxVal)
                    {
                        maxVal = dp[i][k];
                    }
                }
            }
            // cout << i << " " << j << " " << maxVal << endl;
            dp[i + 1][j] += maxVal;
        }
    }
    int n = v.size() - 1;
    return max(dp[n][0], max(dp[n][1], dp[n][2]));
}
int ninjaTraining(vector<vector<int>> v, int prevActivity, int day, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int tempMax = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevActivity)
            {
                int val = v[day][i];
                if (val >= tempMax)
                {
                    tempMax = val;
                }
            }
        }
        return tempMax;
    }

    if (dp[day][prevActivity] != -1)
    {
        return dp[day][prevActivity];
    }
    int maxVal = INT_MIN;
    for (int i = 0; i < 3; i++)
    {

        if (i != prevActivity)
        {
            int val = ninjaTraining(v, i, day - 1, dp) + v[day][i];
            if (val >= maxVal)
            {
                maxVal = val;
            }
        }
    }
    return dp[day][prevActivity] = maxVal;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(4, -1)); // 4 just beacuse of last case we are passing 3 on ln 102

    f(i, 0, n)
    {
        f(j, 0, 3)
        {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }
    cout << ninjaTrainingTab(v, dp);
    // cout << ninjaTraining(v, 3, n - 1, dp); // this 3 was very intuitve else we have to call ninjatraining 3 times and take max of those values
    return 0;
}
/* Main() Ends Here */