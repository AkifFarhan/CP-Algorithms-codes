#include <bits/stdc++.h>
using namespace std;

#define N 100004
#define ll long long
ll parent[N], answer[N], lq[N], rq[N], cq[N];

void make(ll v)
{
    parent[v] = v;
}

ll find(ll v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

int main()
{

    ll n, m;
    cin>>n>>m;

    for(ll i=0; i<m; i++)
        cin>>lq[i]>>rq[i]>>cq[i];

    for (ll i = 0; i <= n + 1; i++)
        make(i);

    for (ll i=m-1; i>=0; i--)
    {
        ll l = lq[i], r = rq[i], c = cq[i];
        for (ll v = find(l); v <= r; v = find(v))
        {
            answer[v] = c;
            parent[v] = v + 1;
        }
    }

    for (ll i=1;i<=n;i++)
        cout<<answer[i]<<" ";
    cout<<endl;
}
