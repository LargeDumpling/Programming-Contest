#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;
#define _PI acos(-1.0)
#define esp 1e-9
#define INF 1 << 30
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pill;
/*===========================================
===============KinderRiven===================
===========================================*/
#define MAXD 25 + 1
int n,m;
map<string,int>name;
vector<string>Name;
int G[MAXD][MAXD],id;
int vis[MAXD];
void init(){
  name.clear();
  Name.clear();
  id = 0;
  memset(G,0,sizeof(G));
  memset(vis,0,sizeof(vis));
}
void dfs(int u){
  vis[u] = 1;
  for(int i = 0 ; i < n ; i++)
    if(G[u][i] == 1 && G[u][i] == G[i][u]){
     if(!vis[i]){
      cout << ", " << Name[i];
      dfs(i);
     }
  }
}
int main(){
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
  int Case = 1;
  while(cin >> n >> m){
    init();
    if(!n && !m) break;
    for(int i = 0 ; i < m ; i++){
      string s1,s2;
      cin >> s1 >> s2;
      if(!name.count(s1)){
        name[s1] = id++;
        Name.push_back(s1);
      }
      if(!name.count(s2)){
        name[s2] = id++;
        Name.push_back(s2);
      }
      int x = name[s1] , y = name[s2];  /*找出2个字符串对应的ID*/
      G[x][y] = 1;					  /*连接*/
    }
    for(int k = 0 ; k < n ; k++)
      for(int i = 0 ; i < n ; i++)
        if(G[i][k])
        for(int j = 0; j < n ; j++)
          if(G[k][j]){
             G[i][j] = 1;
        }
    if(Case > 1)
    cout << endl;
    cout << "Calling circles for data set " << Case++ <<":" << endl;
    for(int i = 0; i < n ; i++){
      if(!vis[i]){
        cout << Name[i];
        dfs(i);
        cout << endl;
      }
    }
  }
  return 0;
}
