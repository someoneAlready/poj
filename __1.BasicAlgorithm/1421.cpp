#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a));
#define pb push_back
#define sz(a) ((int)(a).size())
#define S 200
#define N 50000

char  str[N+10][S+10];

template <int SZ>
struct Hash{
    int h[SZ+10];
    void clear(){
        clr(h, -1);
    }
    int gao(char *s){
        int ret=0, n = strlen(s);
        rep(i, n) ret=(ret*131+s[i])%SZ;
        return ret;
    }
    int find(char *s){
        int k = gao(s);
        while (h[k]!=-1 && strcmp(str[h[k]], s)!=0)
            k=(k+1)%SZ;
        return h[k];
    }
    void ins(char *s, int i){
        int k = gao(s);
        while (h[k]!=-1 && strcmp(str[h[k]], s)!=0)
            k=(k+1)%SZ;
        h[k] = i;
    }
};
Hash<1000003> hash;

struct X{
    int t;  //0: num, 1:symbol, 2:var
    int val;    //+-*/()
                //012345
    X(){}
    X(int t, int val):t(t),val(val){}
};

char s[S+10], t[S+10];
int idx = 0;

bool gg(char *&s, X &ret, X pre);

        
struct P{
    bool def;
    int val;
    vector<X> v;
    void gao(char *s){
        def = 0;
        v.clear();
        X x, pre(1, 0);
        while (gg(s, x, pre)) v.pb(x), pre = x;
    }
    void out(){
        rep(i, sz(v)) cout<<v[i].t<<' '<<v[i].val<<"    ";
        cout<<endl;
    }
};

int i,j,k,m,n,l;
P a[N+10];
char cc[] = "+-*()";

bool gg(char *&s, X &ret, X pre){
    while (isspace(*s)) ++s;
    if ((*s)=='\0') return false;
    
    if (isdigit(*s) || ((pre.t==1 && pre.val<=3) && s[0]=='-' && isdigit(s[1]))){
        bool f=0;
        if ((*s)=='-') f=1, ++s;
        ret = X(0, 0);
        while (isdigit(*s)) ret.val=ret.val*10+(*(s++))-'0';
        if (f) ret.val*=-1;
    }
    else if (strchr(cc, *s)!=0){
        ret = X(1, strchr(cc, *s)-cc);
        ++s;
    }    
    else if (isalpha(*s)){

        int l = 0, m;
        while (isalnum(*s))
            t[l++] = (*s), ++s;
        t[l] = '\0';
        m = hash.find(t);
        if (m==-1){
            m=idx++, memcpy(str[m], t, sizeof(str[0]));
            hash.ins(t, m), a[m].def = 0, a[m].v.clear();
        }
        ret = X(2, m);
    }
    return true;
}

bool cal(int k){
    if (!sz(a[k].v)) return false;
    
    rep(i, sz(a[k].v)){
        X &x = a[k].v[i];
        if (x.t==2 && !a[x.val].def) return false;
    }
   // cout<<k<<endl;
    //a[k].out();
    
    stack<int> num;
    stack<int> op;

    rep(i, sz(a[k].v)){
        X &x  = a[k].v[i];        
        if (x.t==0) num.push(x.val);
        else if (x.t==2) num.push(a[x.val].val);
        else{
            int k = x.val;
            switch (x.val){
                case 1:
                    --k;
                case 0:
                case 2:
                    while (sz(op) && op.top()<=2 && op.top()>=k){
                        int g = num.top(); num.pop();
                        int f = num.top(); num.pop();
                        if (op.top()==0) num.push(f+g);
                        else if (op.top()==1) num.push(f-g);
                        else if (op.top()==2) num.push(f*g);
                        op.pop();
                    }
                    op.push(x.val);
                    break;
                case 3:
                    op.push(x.val);
                    break;
                case 4:
                    while (sz(op) && op.top()!=3){
                        int g = num.top(); num.pop();
                        int f = num.top(); num.pop();
                        if (op.top()==0) num.push(f+g);
                        else if (op.top()==1) num.push(f-g);
                        else if (op.top()==2) num.push(f*g);
                        op.pop();                        
                    }
                    op.pop();
            }
        }
    }
    while (sz(op)){
        int g = num.top(); num.pop();
        int f = num.top(); num.pop();
        if (op.top()==0) num.push(f+g);
        else if (op.top()==1) num.push(f-g);
        else if (op.top()==2) num.push(f*g);
        op.pop();                        
    }    
    
    a[k].val = num.top();
    a[k].def = 1;
    return true;
}

void gao(char *s){
    X ret;
    if (gg(s, ret, X(1, 0)))
        if (ret.t==2){
            s = strstr(s, ":=");

            if (s!=NULL){
                int m = ret.val;
                a[m].gao(s+2);
                if (cal(m)){
                    rep(i, idx) if (i!=m) a[i].def = 0;
                    rep(i, idx){
                        bool f = 0;
                        rep(j, idx) if (!a[j].def)
                            if (cal(j)) f = 1;
                        if (!f) break;
                    }
                }
            }
        }
}

void deal(){
    int n=strlen(s);
    int l =0;
    rep(i, n) if (!isspace(s[i]))
        t[l++] = s[i];
    t[l]='\0';
    memcpy(s, t, sizeof(t));
}

int main(){
    hash.clear();
    while (gets(s)){
        deal();
        if (strcmp(s, "RESET")==0)
            idx = 0, hash.clear();
        else if (strstr(s, "PRINT")==s){
            sscanf(s+5, "%s", t);
            i = hash.find(t);
            if (i==-1 || !a[i].def) puts("UNDEF");
            else printf("%d\n", a[i].val);
        }
        else gao(s);
    }
    return 0;
}
