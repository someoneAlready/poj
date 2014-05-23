#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define N 256

int i,j,k,m,n,l;
char s[100], t[100], input[110][100];

char g[][100]={"DCL", "GOTO", "INC", "DEC", "END"};

int gao(char *s){
    rep(i, 100) t[i]=toupper(s[i]);
    rep(i, 5) if (strcmp(g[i], t)==0) return i;
    return 5;
}

int dcl[N+10], used[N+10], val[N+10];
vector<pair<int,int> > ans;

int gg(int i){
    sscanf(input[i], "%s", s);
    int type = gao(s);
    switch(type){
        case 0:
            sscanf(input[i], "%s%s", t, s);
            if (dcl[s[0]] && !used[s[0]])
                ans.pb(make_pair(i, 1));
            dcl[s[0]]=i, used[s[0]] = val[s[0]] = 0;
            break;
        case 1:
            sscanf(input[i], "%s %s", t, s);
            if (isalpha(s[0])){
                sscanf(input[i], "%s %s %d", t, s, &k);
                if (dcl[s[0]]){
                    used[s[0]] = i;
                    if (val[s[0]]>0)
                        return k;
                }
                else ans.pb(make_pair(i, 2));
            }
            else{
                sscanf(input[i], "%s %d", s, &k);
                return k;
            }
            break;
        case 2:
        case 3:
            sscanf(input[i], "%s%s", t, s);
            if (dcl[s[0]]){
                if (type==2) val[s[0]]++;
                else val[s[0]]--;
                used[s[0]] = i;
            }
            else
                ans.pb(make_pair(i, 2));
            break;
        case 4:
            return n+1;
            break;
        case 5:
            sscanf(input[i], "%s = %d", s, &k);
            if (dcl[s[0]]){
                val[s[0]] = k;
                used[s[0]] = i;
            }
            else ans.pb(make_pair(i, 2));
    }
    return i+1;
}
    
int main(){
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        scanf("%d\n", &n);
        repf(i, 1, n)
            gets(input[i]);
         
        clr(dcl, 0);
        clr(used, 0);
        
        ans.clear();
        
        i = 1;
        
        while(i<=n){
            i = gg(i);
        }
        printf("%d\n", te);
        rep(i, sz(ans)) printf("%d %d\n", ans[i].first, ans[i].second);
        
    }
    return 0;
}
