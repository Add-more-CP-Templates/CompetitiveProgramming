#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve()
{
    int n,k;
    cin>>n;
    n*=2;
    vector<pair<int,int>> groups;
    cin>>k;
    groups.push_back({1,k});
    for (int i=1;i<n;++i)
    {
        cin>>k;
        if (k<groups.back().second)
            ++groups.back().first;
        else
            groups.push_back({1,k});
    }
    bool dp[n+1];
    dp[0]=1;
    for (int i=1;i<=n;++i)
        dp[i]=0;
    for (auto i : groups)
        for (int j=n;j>=i.first;--j)
            dp[j]=(dp[j-i.first]|dp[j]);
    if (dp[n/2])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}