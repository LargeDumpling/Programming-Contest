/**************************************************************
    Problem: 2243
    User: Showson
    Language: C++
    Result: Accepted
    Time:2888 ms
    Memory:25704 kb
****************************************************************/
 
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cctype>
using namespace std;
 
const int Maxn=100010,Maxm=Maxn;
 
int n,m;
 
const int D=10000000;
char in[D],out[D/10],*I=in,*O=out;
 
inline char gc(){
    return *(I++);
}
 
inline void pc(const char& c){
    *(O++)=c;
}

template <typename Q>
inline void pt(Q x){
    if(x==0) pc('0');
    if(x<0) pc('-'),x=-x;
    static int stk[20],top;
    top=0;
    for(;x;x/=10) stk[++top] = x%10;
    for(int i=top;i;--i) pc(stk[i]+'0');
}
 
template <typename Q>
inline void gt(Q& x){
    static char c,f;
    for(c=gc(),f=0;!isdigit(c);c=gc()) if(c=='-') f=1;
    for(x=0;isdigit(c);c=gc()) x=x*10+c-'0';
    if(f) x=-x;
}
 
struct Data {
    int l,r,num;
    Data (int l=-1,int r=-1,int num=0):l(l),r(r),num(num) {}
    Data operator + (const Data& rhs)const {
        if(rhs.l==-1 && l==-1 ) exit(-1);
        if(rhs.l==-1) return *this;
        if(l==-1) return rhs;
        return Data(l,rhs.r,num+rhs.num-(r==rhs.l));
        Data ret(l,rhs.r,num+rhs.num);
        if(r==rhs.l) ret.num--;
        return ret;
    }
    Data operator ~()const {
        return Data(r,l,num);
    }
};
 
int tbld[Maxn];
 
struct SegmentTree {
    Data da[Maxn*4];
    int tag[Maxn*4];
    int lft,rgt,w;
 
    SegmentTree() {
        memset(tag,-1,sizeof tag);
    }
     
    void build(int o,int l,int r){
        if(l==r) {
            da[o] = Data(tbld[l],tbld[l],1);
            return;
        }
        int mid=(l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        da[o] = da[o<<1] + da[o<<1|1];
    }
 
    void add(int o,int col) {
        da[o]=Data(col,col,1);
        tag[o]=col;
    }
 
    void down(int o) {
        if(tag[o]==-1) return;
        add(o<<1,tag[o]);
        add(o<<1|1,tag[o]);
        tag[o]=-1;
    }
 
    void pp(int l,int r=0,int w=0) {
        lft=l,rgt=r;
        this->w=w;
    }
 
    void change(int o,int l,int r) {
        if(lft<=l && r<=rgt) {
            add(o,w);
            return;
        }
        down(o);
        int mid=(l+r)>>1;
        if(lft<=mid) change(o<<1,l,mid);
        if(mid<rgt) change(o<<1|1,mid+1,r);
        da[o]=da[o<<1]+da[o<<1|1];
    }
 
    Data query(int o,int l,int r) { 
        if(lft<=l && r<=rgt) {
            return da[o];
        }
        down(o);
        int mid=(l+r)>>1;
        if(rgt<=mid) return query(o<<1,l,mid);
        if(mid<lft) return query(o<<1|1,mid+1,r);
        return query(o<<1,l,mid)+query(o<<1|1,mid+1,r);
    }
     
    Data query(int l,int r){
        pp(l,r);
        return query(1,1,n);
    }
     
    void change2(int l,int r,int w){
        pp(l,r,w);
        change(1,1,n);
    }
} seg;
 
int fir[Maxn],next[Maxm*2],en[Maxm*2];
int tot=0;
void Add(int from,int to) {
    en[++tot] = to;
    next[tot] = fir[from];
    fir[from] = tot;
}
 
int sz[Maxn],son[Maxn],fa[Maxn],dep[Maxn];
 
void dfs(int u) {
    sz[u] = 1;
    son[u] = 0;
    for(int k=fir[u]; k; k=next[k]) {
        const int&v=en[k];
        if(v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u]+1;
        dfs(v);
        sz[u] += sz[v];
        if(sz[v]>sz[son[u]]) son[u] = v;
    }
}
 
int top[Maxn],pos[Maxn],color[Maxn],clk=0;
 
void build(int u,int pre) {
    top[u] = pre;
    pos[u] = ++clk;
    tbld[clk] = color[u];
    if(son[u]) build(son[u],pre);
    for(int k=fir[u]; k; k=next[k]) {
        const int&v = en[k];
        if(v==fa[u] || v==son[u]) continue;
        build(v,v);
    }
}
 
void change(int a,int b,int c){
    int ta=top[a],tb=top[b];
    for(;ta!=tb;a=fa[ta],ta=top[a]){
        if(dep[ta] < dep[tb] ) swap(a,b), swap(ta,tb);
        seg.change2(pos[ta],pos[a],c);
    }
    if(dep[a]>dep[b]) swap(a,b);
    seg.change2(pos[a],pos[b],c);
}
 
Data query(int a,int b) {
    int ta=top[a],tb=top[b];
     
    Data res1,res2;
     
    for(;ta!=tb;){
        if(dep[ta]>dep[tb]){
            res1 = seg.query(pos[ta],pos[a]) + res1;
            a=fa[ta],ta=top[a];
        } else {
            res2 = seg.query(pos[tb],pos[b]) + res2;
            b=fa[tb],tb=top[b];
        }
    }
//  Data tmp ( seg.query(pos[b],pos[a]) );
    if(dep[a]<dep[b]) return (~res1)+seg.query(pos[a],pos[b])+res2;
//  tmp=(~res2)+seg.query(pos[b],pos[a]);
//  tmp=tmp+res1;
    return (~res2)+seg.query(pos[b],pos[a])+res1;
}
 
int main() {
    fread(in,1,D,stdin);
 
    gt(n),gt(m);
     
    for(int i=1;i<=n;i++) gt(color[i]);
     
    for(int u,v,i=1;i<n;i++){
        gt(u),gt(v);
        Add(u,v);
        Add(v,u);
    }
     
    dfs(1);
    build(1,1);
    seg.build(1,1,n);
     
//  for(int i=1;i<=n;i++) printf("%d\n",son[i]);
//  return 0;
     
    char cmd;
    int a,b,c;
     
//  for(I=1;I<=m;I++)
    for(;m--;){
         
        /*if(I==2) {
            Data tmp=seg.query( pos[2],pos[7] );
            tmp=seg.query( pos[3],pos[4]);
            tmp=seg.query( pos[2],pos[6]);
            tmp=seg.query( pos[6],pos[7]);
            I=2;
        }*/
         
        for(cmd=gc();cmd!='Q'&&cmd!='C';cmd=gc());
        gt(a);gt(b);
        if(cmd == 'Q') pt(query(a,b).num),pc('\n');
        else gt(c), change(a,b,c);
    }
     
    return printf(out),0;
}
