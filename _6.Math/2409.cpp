#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
using namespace std;
#define sqr(x) ((x)*(x))
#define ll long long

const int N=32;

ll i,j,k,m,n,l;
ll a[N+10];
bool v[N+10];

ll pow(ll x, ll y)
{
    ll res=1;
    for (int i=0; i<y; i++)
        res*=x;
    return res;
}

ll c()
{
    ll res=0;
    memset(v, 0, sizeof(v));
    for (i=0; i<n; i++) if (!v[i])
    {
        int k=i;
        while (!v[k])
        {
              v[k]=true;
              k=a[k];
        }
        res++;
    }
    return res;    
}

int main()
{
    while (cin>>m>>n && !(m==0 && n==0))
    {
        ll ans=0;
        for (i=0; i<n; i++) a[i]=i;                 
        for (int delta=0; delta<n; delta++)
        {
            ans+=pow(m,c());
            for (i=0; i<n; i++)
                a[i]=(a[i]+1)%n;
        }
        
        
        k=0;
        for (i=n-1; i>=0; i--) a[i]=k++;
        for (int delta=0; delta<n; delta++)
        {
            ans+=pow(m,c());
            for (i=0; i<n; i++)
                a[i]=(a[i]+1)%n;
        }
        
        
        
        ans/=2*n;
        cout<<ans<<endl;
    }
    return 0;
}
