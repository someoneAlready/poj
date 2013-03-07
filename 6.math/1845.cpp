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
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

#define E 9901
#define N 50000
vi prm;
ll m,n;
bool v[N+10];

template <class T> 
T egcd(T a, T b, T &x, T &y){ 
    T t, d; 
    if (b==0) return x=1, y=0, a; 
    d=egcd(b, a%b, x, y); 
    t=x; x=y; y=t-a/b*y; 
    return d; 
} 

struct C{ 
    static const ll MOD=E; 
    ll it; 
    C(ll _it){ 
        it=(_it%MOD+MOD)%MOD; 
    } 
    C operator +(const C & c)const{ 
        return C(it+c.it); 
    } 
    C operator -(const C & c)const{ 
        return C((it-c.it)); 
    } 
    C operator *(const C & c)const{ 
        return C(it*c.it); 
    } 
    ll anti()const{ 
        ll x,y; 
        egcd(it, MOD, x, y); 
        return C(x).it; 
    } 
    C operator /(const C & c)const{ 
        return C(it*c.anti()); 
    } 
	C out(){cout<<it<<endl;}
};


void init(){
	repf(i, 2, N) if (!v[i]){
		prm.pb(i);
		repf(j, 2, N/i) v[i*j]=true;
	}
}

C pow(C a, ll b){
	C ret(1);
	while (b){
		if (b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

C gao(int p, int n){
	if (p%E==1) return C(m*n+1);
	C ret=pow(C(p), m*n+1)-C(1);
	ret=ret/C(p-1);
	return ret;
}

int main(){
	init();
	while (cin>>n>>m){
		if (n==0){
			cout<<0<<endl; continue;
		}
		C ret(1);
		rep(i, sz(prm)) if (n%prm[i]==0){
			int k=0;
			while (n%prm[i]==0) n/=prm[i], k++;
			ret=ret*gao(prm[i], k);	
		}
		if (n!=1) ret=ret*gao(n, 1);
		ret.out();
	}
	return 0;
}


