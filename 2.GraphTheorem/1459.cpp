#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
#define INF (INT_MAX/20)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 200

struct e_t {
	int to, cap, rev; 
	e_t(int to, int cap, int rev):to(to),cap(cap),rev(rev){}
};

vector<e_t> a[N+10];
int lev[N+10], done[N+10];
int i,j,k,m,n,l;
int s, t;

void add(int i, int j, int c){ 
        a[i].pb(e_t(j, c, sz(a[j]))); 
        a[j].pb(e_t(i, 0, sz(a[i])-1)); 
} 
 
bool levelize(){ 
        fill(lev, -1); 
        queue<int> q; 
        lev[s]=0; 
        q.push(s); 
        while (!q.empty()){ 
                int i=q.front(); q.pop(); 
                rep(k, sz(a[i])){ 
                        e_t e=a[i][k]; 
                        if (!e.cap || lev[e.to]!=-1) continue; 
                        lev[e.to] = lev[i]+1; 
                        q.push(e.to); 
                } 
        } 
        return lev[t]!=-1; 
} 
 
int augmemt(int v, int f){ 
        if (v==t || !f) return f; 
        for (; done[v] < sz(a[v]); done[v]++){ 
                e_t &e = a[v][done[v]]; 
                if (lev[e.to] <= lev[v] || !e.cap) continue; 
                int t = augmemt(e.to, min(f, e.cap)); 
                if (t>0){ 
                        e.cap-=t; 
                        a[e.to][e.rev].cap+=t; 
                        return t; 
                } 
        } 
        return 0; 
} 
 
int max_flow(){ 
        int f=0, t; 
        while (levelize()){ 
                fill(done ,0); 
                while (t=augmemt(s, INF)) 
                         f+=t; 
        } 
        return f; 
}

char S[N+10];

int main(){
	int np, nc;
	while (~scanf("%d%d%d%d", &n, &np, &nc, &m)){
		s=n, t=n+1;
		rep(i, t+1) a[i].clear();

		while (m--){
			scanf("%s", S);
			sscanf(S, "(%d,%d)%d", &i, &j, &k);
			add(i, j, k);
		}

		while (np--){
			scanf("%s", S);
			sscanf(S, "(%d)%d", &i, &k);
			add(s, i, k);
		}
		while (nc--){
			scanf("%s", S);
			sscanf(S, "(%d)%d", &i, &k);
			add(i, t, k);
		}
		cout<<max_flow()<<endl;
	}	
	return 0;
}


