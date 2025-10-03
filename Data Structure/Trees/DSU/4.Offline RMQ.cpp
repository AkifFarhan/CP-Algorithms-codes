#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define ll long long

struct Query
{
    ll L,R,idx;
};

ll parent[N], a[N], answer[N];

ll find_set(ll v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v)
{
    parent[v] = v;
}

int main()
{
    ll n,q;
    cin>>n>>q;

    for(ll i = 0; i < n; i++)
        cin>>a[i];

    vector<vector<Query>> container(n);
    for (ll i = 0; i < q; i++)
    {
        ll L, R;
        cin>>L>>R;
        L--; R--;
        container[R].push_back({L, R, i});
    }

    for (ll i = 0; i < n; i++)
        make_set(i);

    stack<ll> s;

    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] > a[i])
        {
            parent[s.top()] = i;
            s.pop();
        }
        s.push(i);

        for (auto q : container[i])
            answer[q.idx] = a[find_set(q.L)];
    }

    for (ll i = 0; i < q; i++)
        cout<<answer[i]<<endl;
}

