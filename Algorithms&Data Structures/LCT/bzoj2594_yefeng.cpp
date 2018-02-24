#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N = (int)1e5+10;
const int M = (int)1e6+10;
const int maxn = 5*N;
int n, m, Q_num;
struct node{
    int a, b, t;
    bool operator < (const node &tmp) const{
        return t < tmp.t;
    }
}edge[M];
struct Query{
    int k,a,b;
}Q[N];

map< pair<int,int>, int > mp;
vector<int> S[2*N+10];

int getint(){
    char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar() );
    int tmp = 0;
    for(; ch > '0' && ch < '9'; ch = getchar() )
        tmp = tmp*10 + ch - '0';
    return tmp;
}

int st[maxn], top;
bool vis[M];

int find(int x){
    return st[x] == x ? x : find(st[x]);
}

void debug(){
    printf("n = %d, m = %d, Q_num = %d\n", n, m, Q_num );
    printf("Edge:\n");
    for(int i = 0; i < m; i++)
        printf("(%d,%d,t=%d)\n", edge[i].a, edge[i].b, edge[i].t );
    printf("Query:\n");
    for(int i = 0; i < Q_num; i++)
        printf("k=%d,(%d,%d)\n", Q[i].k, Q[i].a, Q[i].b );

}
void input(){
    n = getint(); m = getint(); Q_num = getint();
        
    for(int i = 0; i < m; i++){ // Edge infomation
        edge[i].a = getint();
        edge[i].b = getint();
        edge[i].t = getint();
    }
    for(int i = 0; i < Q_num; i++){ // Query 
        Q[i].k = getint();
        Q[i].a = getint();
        Q[i].b = getint();
    }
    sort( edge, edge+m ); // sort by t desc
    for(int i = 0; i < m; i++) // index
        mp[ make_pair( edge[i].a, edge[i].b ) ] = 
            mp[ make_pair( edge[i].b, edge[i].a ) ] = i;
    for(int i = 0; i < Q_num; i++){
        if( Q[i].k == 2 )    
            vis[ mp[make_pair(Q[i].a, Q[i].b)] ] = true;    
    }    
//    for(int i = 0; i < m; i++)
//        printf("%d ", vis[i] ); puts("");
}

int val[maxn];
int pos[maxn], dep[maxn], vec[maxn], idx;
int dp[maxn][50];

void dfs(int u,int d){
    dep[++idx] = d; vec[idx] = u;    
    if( pos[u] == -1 ) pos[u] = idx;
    dep[idx] = d;
    for(int i = 0; i < (int)S[u].size(); i++){
        dfs( S[u][i], d+1 );    
        dep[++idx] = d;    vec[idx] = u;    
    }
}

void print(){
    printf("Top = %d\n", top);
    for(int i = 1; i <= top; i++) printf("pos[%d] = %d, val[%d] = %d\n", i, pos[i], i, val[i]);

    printf("idx = %d\n", idx);
    for(int i = 1; i <= idx; i++)
        printf("i = %d, vec[%d] = %d, dep[%d] = %d\n", i, i, vec[i], i, dep[i] );    

}
void predeal(){
    for(int i = 0; i < 2*n+10; i++)
        st[i] = i, S[i].clear();    
    top = n;
    for(int i = 0; i < m; i++){
        if( vis[ mp[ make_pair( edge[i].a, edge[i].b )  ] ] == false ){
            int a = edge[i].a, b = edge[i].b, t = edge[i].t;
            int x = find(a), y = find(b);    
        //    printf("(%d,%d): x = %d, y = %d\n",a,b, x, y );    
            if( x != y ){
                st[x] = st[y] = ++top;
                val[top] = t;
                S[top].push_back(x), S[top].push_back(y);    
            }
        }    
    }

    for(int i = 1; i <= top; i++) 
        pos[i] = -1; 
    idx = 0;
    dfs( top, 0 );    

    //print();
    // init RMQ
    for(int i = 1; i <= idx; i++)
        dp[i][0] = i;
    for(int j = 1; (1<<j) <= idx; j++){
        for(int i = 1; i+(1<<j)-1 <= idx; i++){
            // dp[i][j] = min( dp[i][j-1], dp[i+(1<<(j-1))][j-1] );
            if( dep[ dp[i][j-1] ] < dep[ dp[i+(1<<(j-1))][j-1] ] )
                dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i+(1<<(j-1))][j-1];
        }    
    }
}
int RMQ_find(int l,int r){
    int d = r-l+1, k = 0;
    while( (1<<(k+1)) < d ) k++;
//    printf("RMQ: k = %d\n", k );
//    printf("RMQ: L = %d, R = %d\n", dp[l][k] , dp[r-(1<<k)+1][k] );
    if( dep[ dp[l][k] ] < dep[ dp[r-(1<<k)+1][k] ] ) return dp[l][k];
    return dp[ r-(1<<k)+1 ][k];
}

int ans[M], ans_cnt;

void solve(){
    int ans_cnt = 0;
    predeal();
    for(int i = Q_num-1; i >= 0; i-- ){ 
        if( Q[i].k == 1 ){
            int l = pos[ Q[i].a ], r = pos[ Q[i].b ];
        //    printf("(a=%d,b=%d),(l=%d,r=%d)\n", Q[i].a, Q[i].b, l, r);    
            if( l > r ) swap( l, r );
            int pt = RMQ_find(l,r);  //printf("pt = %d\n", pt );    
            ans[ ans_cnt++ ] = val[ vec[pt] ];
        }
        else{
            // Q[i].k == 2 
            vis[ mp[ make_pair( Q[i].a,Q[i].b ) ] ] = false;
            predeal(); // restructrue the min genaration tree
        }
    //    puts("******************************************************");    
    }
    for(int i = ans_cnt-1; i >= 0; i-- ){
        printf("%d\n", ans[i] );    
    }
}

int main(){
    freopen("in.txt","r",stdin);
	freopen("out_yefeng.txt","w",stdout);

    input();
    solve();

    return 0;
}