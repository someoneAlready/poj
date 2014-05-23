#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())

#define N 100
#define S 80
#define L 1500

int i,j,k,m,n,l;
char s[L+10][S+10], t[S +10], x[S +10], y[S +10], z[S +10];
int len[L+10];
pair<int,int> art[N+10];
set<pair<int,int> > a[L*S+10];
set<int> st[N+10];
int idx;
char str[L*S+10][S +10];

template<int SZ>
struct Hash{
	int h[SZ+10];
	Hash(){ clr(h, -1); }
	int gao(char *s){
		int ret=0, n=strlen(s);
		rep(i, n) ret=(ret*131+s[i])%SZ;
		return ret;
	}
	int find(char *s){
		int k=gao(s);
		while (h[k]!=-1 && strcmp(str[h[k]], s)!=0)
			k=(k+1)%SZ;
		return h[k];
	}
	void ins(char *s, int i){
		int k=gao(s);
		while (h[k]!=-1 && strcmp(str[h[k]], s)!=0)
			k=(k+1)%SZ;
		h[k]=i;
	}
};
Hash<L*S+1000000> hash;

inline int get(char *t){
    int ret=hash.find(t);
    if (ret!=-1) return ret;
    memcpy(str[++idx], t, sizeof(str[0]));
    hash.ins(t, idx);
    return idx;
}


inline int find(char *t){
    int ret=hash.find(t);
    if (ret!=-1) return ret;
    return L*S;
}

void gao(){
    rep(i, n) st[i].clear();
    idx = 0;
    rep(i, L*S+10) a[i].clear();
    
    rep(x, n) repf(i, art[x].first, art[x].second){
        int l=0;
        len[i] = strlen(s[i]);
        rep(j, len[i]+1) if (isalpha(s[i][j]))
            y[l++]=tolower(s[i][j]);
        else if (l){
            y[l]='\0';
            int k =get(y);
            st[x].insert(k);
            a[k].insert(make_pair(x, i));
            //cout<<y<<' '<<k<<endl;
            l=0;
        }
    }
}

void out(set<pair<int,int> > &v){
    int pre = v.begin()->first;
    for (set<pair<int,int> >::iterator it=v.begin(); it!=v.end(); ++it){
        if (it->first != pre)
            pre=it->first, puts("----------");
        puts(s[it->second]);
    }
}



int main(){
        scanf("%d\n", &n);
        j=0;
        rep(i, n){
            art[i].first = j;
            gets(s[j]);
            while (strcmp(s[j], "**********")!=0) gets(s[++j]);
            art[i].second = j-1;
        }
        

        gao();
        scanf("%d\n", &m);
        while (m--){
            gets(t);
            set<pair<int, int> > v;
            int w=strlen(t);
//            rep(i, w) t[i]=tolower(t[i]);
            if (strstr(t, "NOT")!=0){
                sscanf(t, "%s %s",z, x);
                int k = find(x);
                //cout<<x<<' '<<k<<endl;
                rep(i, n) if (st[i].find(k)==st[i].end()) 
                    repf(j, art[i].first, art[i].second) v.insert(make_pair(i, j));
            }            
            else if (strstr(t, " AND ")!=0){
                sscanf(t, "%s %s %s", x, z, y);
                int j=find(x), k=find(y);  
                    
                set<pair<int, int> >::iterator f=a[j].begin(), g=a[k].begin();
                
                while (f!=a[j].end() && g!=a[k].end()){
                    if (f->first==g->first){
                        int w=f->first;
                        while (f!=a[j].end() && f->first==w) v.insert(*(f++));
                        while (g!=a[k].end() && g->first==w) v.insert(*(g++));
                    }
                    else if (f->first<g->first) ++f;
                    else ++g;
                }
            }
            else if (strstr(t, " OR ")!=0){
                sscanf(t, "%s %s %s", x, z, y);
                int j=find(x), k=find(y);
                set<pair<int, int> >::iterator f=a[j].begin(), g=a[k].begin();
                
                while (f!=a[j].end()) v.insert(*(f++));
                while (g!=a[k].end()) v.insert(*(g++));
            }
            else if (strlen(t)){
                int k = find(t);
                v = a[k];
            }
            if (sz(v)) out(v);
            else puts("Sorry, I found nothing.");
        
            puts("==========");
        }
     
    return 0;
}
