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
    int n,k,doneZ=0,one=0;
    string s;
    cin>>n>>k;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='1')
        {
            ++one;
            continue;
        }
        if (one<=k)
        {
            k-=one;
            ++doneZ;
            continue;
        }
        for (int j=0;j<doneZ;++j)
            cout<<0;
        for (int j=0;j<(one-k);++j)
            cout<<1;
        cout<<0;
        for (int j=0;j<k;++j)
            cout<<1;
        for (int j=i+1;j<n;++j)
            cout<<s[j];
        cout<<"\n";
        return;
    }
    sort(s.begin(), s.end());
    cout<<s<<"\n";
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