#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define ll long long
ll a[N];
ll m[N][19];
ll bin_log[N];

ll query(ll L,ll R)
{
    ll length = R-L+1;

    ll k = bin_log[length];

    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main()
{
    ll n,q;
    cin>>n>>q;

    bin_log[1] = 0;

    for (ll i=2; i<=n; i++)
        bin_log[i] = bin_log[i/2] + 1;

    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }

    for (ll k=1; k<19; k++)
    {
        for (ll i=0; i + (1<<k) <= n; i++)
        {
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }

    while (q--)
    {
        ll l, r;
        cin>>l>>r;
        l--; r--;
        cout<<query(l, r)<<endl;
    }
}
