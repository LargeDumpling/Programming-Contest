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
//ms��Ϊ����������Ҫ��,����ģ�崮��ͬʱ
struct ACautomata {
  int ch[MAXNODE][SIGMA_SIZE];
  int f[MAXNODE];    // fail����
  int val[MAXNODE];  // ÿ���ַ����Ľ�β��㶼��һ����0��val
  int last[MAXNODE]; // ����������һ�����
  int cnt[MAXS];
  int sz;

  void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(cnt, 0, sizeof(cnt));
//    ms.clear();
  }

  // �ַ�c�ı��
  int idx(char c) {
    if(c>='0'&&c<='9')return c-'0';
    else if(c>='A'&&c<='Z')return c-'A'+10;
    else if(c>='a'&&c<='z')return c-'a'+36;
  }

  // �����ַ�����v�����0
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

  // �ݹ��ӡƥ���ı���str[i]��β�ĺ�׺,�Խ��j��β�������ַ���
  void print(int i,int j) {
    if(j) {
      cnt[val[j]]++;
      print(i,last[j]);
    }
  }

  // ��T����ģ��
  int find(char* T) {
    int n = strlen(T);
    int j = 0; // ��ǰ����ţ���ʼΪ�����
    for(int i = 0; i < n; i++) { // �ı�����ǰָ��
      int c = idx(T[i]);
      j = ch[j][c];
      if(val[j]) print(i,j);
      else if(last[j]) print(i,last[j]); // �ҵ��ˣ�
    }
  }

  // ����fail����
  void getFail() {
    queue<int> q;
    f[0] = 0;
    // ��ʼ������
    for(int c = 0; c < SIGMA_SIZE; c++) {
      int u = ch[0][c];
      if(u) { f[u] = 0; q.push(u); last[u] = 0; }
    }
    // ��BFS˳�����fail
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
        val[u]|=val[f[u]];//�����ֹ���
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
