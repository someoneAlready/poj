#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define itr iterator
#define pb push_back
#define N 100
#define sz(a) ((int)(a).size())

struct P{
    int i,j,k;
    P(){}
    P(int i, int j, int k):i(i),j(j),k(k){}
    bool operator <(const P &p)const{
        return k<p.k;
    }
};


int i,j,k,m,n,l;
int f[N+10];

int find(int i){
    if (i==f[i]) return i;
    return f[i]=find(f[i]);
}

int main(){
    while (~scanf("%d", &n)){
        vector<P> e;
        rep(i, n) rep(j, n){
            scanf("%d", &k);
            e.pb(P(i,j,k));
        }
        rep(i, n) f[i]=i;
        sort(e.begin(), e.end());
        int ans=0, tot=0;
        rep(mm, sz(e)){
            int i=find(e[mm].i), j=find(e[mm].j);
            if (i!=j){
                ans+=e[mm].k, tot++, f[i]=j;
                if (tot==n-1) break;
            }
        }
        cout<<ans<<endl;
    }   
    
    return 0;
}

