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
#define N 10000
#define S 15

int i,j,k,m,n,l;
char sa[N+10][S+10];

template<int SZ>
struct H{
	int h[SZ+10];
	H(){ fill(h, -1); }
	int gao(const char *s){
		int ret=0, n=strlen(s);
		rep(i, n) ret=(ret*131+s[i])%SZ;
		return ret;
	}
	int operator[](const char *s){
		int k=gao(s);
		while (h[k]!=-1 && strcmp(sa[h[k]], s)!=0)
			k=(k+1)%SZ;
		return h[k];
	}
	void gao(const char *s, int i){
		int k=gao(s);
		while (h[k]!=-1 && strcmp(sa[h[k]], s)!=0)
			k=(k+1)%SZ;
		h[k]=i;
	}
};

H<1000003> hash;
char s[S+10];

int main(){
	rep(i, INF){
		scanf("%s", sa[i]);
		if (strcmp(sa[i], "#")==0){
			n=i;
			break;
		}
		hash.gao(sa[i], i);
	}
	rep(i, INF){
		scanf("%s", s);
		if (strcmp(s, "#")==0) break;
		if ((k=hash[s])!=-1)
			printf("%s is correct\n", s);
		else{
			set<int> st;
			n=strlen(s);
			rep(i, n){						//deleting
				string t;
				rep(j, n) if (i!=j) t+=s[j];
				if ((k=hash[t.c_str()])!=-1) st.insert(k);
			}
			rep(i, n){						//replacing
				char ch=s[i];
				rep(j, 26){
				   s[i]=j+'a';
				   if ((k=hash[s])!=-1) st.insert(k);
				}
				s[i]=ch;
			}
			rep(j, 26)						//inserting
			repf(i, 0, n){
				string t;
				repf(l, 0, i-1) t+=s[l];
				t+=j+'a';
				repf(l, i, n-1) t+=s[l];
				if ((k=hash[t.c_str()])!=-1) st.insert(k);
			}
			printf("%s:", s);
			foreach(it, st) printf(" %s", sa[*it]);
			putchar('\n');
		}
	}
	return 0;
}


