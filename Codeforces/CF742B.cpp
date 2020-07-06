#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x;
    ll ans=0;
    cin>>n>>x;
    ll a[n];
    vector<ll> v;
    map<ll,ll> m;
    for (ll i=0;i<n;++i)
    {
        cin>>a[i];
        if (!m[a[i]])
        {
            v.push_back(a[i]);
        }
        ++m[a[i]];
    }
    if (x==0)
    {
        for (ll i=0;i<sz(v);++i)
        {
            ans+=m[v[i]]*(m[v[i]]-1);
        }
        cout<<ans/2;
        return 0;
    }
    for (ll i=0;i<sz(v);++i)
    {
        ans+=m[v[i]]*m[x^v[i]];
    }
    cout<<ans/2;
    return 0;
}