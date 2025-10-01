#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>>s1,s2;

void add_element(int x)
{
    int minimum = s1.empty() ? x:min(x,s1.top().second);
    s1.push({x,minimum});
}

void remove_element()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty()?element:min(element,s2.top().second);
            s2.push({element,minimum});
        }
    }
    s2.pop();
}

int minimum()
{
    int mn;
    if (s1.empty() || s2.empty())
        mn = s1.empty() ? s2.top().second : s1.top().second;
    else
        mn = min(s1.top().second, s2.top().second);

    return mn;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int len;
    cin>>len;

    for(int i=0;i<len;i++)
        add_element(a[i]);
    cout<<minimum()<<" ";

    for(int i=len;i<n;i++)
    {
        remove_element();
        add_element(a[i]);
        cout<<minimum()<<" ";
    }
    cout<<endl;
}

