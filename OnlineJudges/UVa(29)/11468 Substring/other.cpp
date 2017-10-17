#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int SIGMA_SIZE = 62;
const int MAXNODE = 1000;
const int MAXS = 150 + 10;

//map<string,int> ms;
//ms是为了满足特殊要求,比如模板串相同时
struct ACautomata {
  int ch[MAXNODE][SIGMA_SIZE];
  int f[MAXNODE];    // fail函数
  int val[MAXNODE];  // 每个字符串的结尾结点都有一个非0的val
  int last[MAXNODE]; // 输出链表的下一个结点
  int cnt[MAXS];
  int sz;

  void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(cnt, 0, sizeof(cnt));
//    ms.clear();
  }

  // 字符c的编号
  int idx(char c) {
    if(c>='0'&&c<='9')return c-'0';
    else if(c>='A'&&c<='Z')return c-'A'+10;
    else if(c>='a'&&c<='z')return c-'a'+36;
  }

  // 插入字符串。v必须非0
  void insert(char *s, int v) {
    int u = 0, n = strlen(s);
    for(int i = 0; i < n; i++) {
      int c = idx(s[i]);
      if(!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
    val[u] =1;
    //ms[string(s)] = v;
  }

  // 递归打印匹配文本串str[i]结尾的后缀,以结点j结尾的所有字符串
  void print(int i,int j) {
    if(j) {
      cnt[val[j]]++;
      print(i,last[j]);
    }
  }

  // 在T中找模板
  int find(char* T) {
    int n = strlen(T);
    int j = 0; // 当前结点编号，初始为根结点
    for(int i = 0; i < n; i++) { // 文本串当前指针
      int c = idx(T[i]);
      j = ch[j][c];
      if(val[j]) print(i,j);
      else if(last[j]) print(i,last[j]); // 找到了！
    }
  }

  // 计算fail函数
  void getFail() {
    queue<int> q;
    f[0] = 0;
    // 初始化队列
    for(int c = 0; c < SIGMA_SIZE; c++) {
      int u = ch[0][c];
      if(u) { f[u] = 0; q.push(u); last[u] = 0; }
    }
    // 按BFS顺序计算fail
    while(!q.empty()) {
      int r = q.front(); q.pop();
      for(int c = 0; c < SIGMA_SIZE; c++) {
        int u = ch[r][c];
        if(!u) {
            ch[r][c]=ch[f[r]][c];
            continue;
        }
        q.push(u);
        int v = f[r];
        while(v && !ch[v][c]) v = f[v];
        f[u] = ch[v][c];
        last[u] = val[f[u]] ? f[u] : last[f[u]];
        val[u]|=val[f[u]];//计算禁止结点
      }
    }
  }
  
};
int L;
ACautomata solver;
double d[MAXNODE][105];
bool vis[MAXNODE][105];
double prob[65];
double dfs(int u,int k){
    if(!k)return 1.0;
    if(vis[u][k])return d[u][k];
    double &ans=d[u][k];
    ans=0;
    vis[u][k]=1;
    for(int i=0;i<SIGMA_SIZE;i++)
    {
        if(!solver.val[solver.ch[u][i]])
            ans+=prob[i]*dfs(solver.ch[u][i],k-1);
    }
    return ans;
}
int main(){
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        char str[30];
        int k;
        solver.init();
        scanf("%d",&k);
        REP(i,1,k)
        {
            scanf("%s",&str);
            solver.insert(str,i);
        }
        solver.getFail();
        CL(vis,0);
        scanf("%d",&k);
        double a;
        REP(i,0,64)prob[i]=0;
        REP(i,1,k){
            scanf("%s%lf",str,&a);
            prob[solver.idx(str[0])]=a;
        }
        int L;
        scanf("%d",&L);
        printf("Case #%d: %.6lf\n",++cas,dfs(0,L));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
