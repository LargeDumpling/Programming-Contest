#include<bits/stdc++.h>
#define lc(x) (2*x)
#define rc(x) (2*x+1)
#define fi first
#define se second
#define low(x) (x&(-x))
using namespace std;
typedef long long ll;
const int maxn = 1e4+5;
const ll mod = 1e9+7;
const ll inf = 1e18;
int n;
int g[maxn][3];
int f[maxn][300];

void read1n(int &x)
{
    bool neg=false;
    char ch;
    for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
        if(ch==-1) return;
        else if(ch=='-') neg=true;
    for(x=0;'0'<=ch&&ch<='9';ch=getchar())
        x=(x<<1)+(x<<3)+ch-'0';
    if(neg) x=-x;
    return;
}

int main(){
    int t;
    char h[5];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int i,j;
        for(i=1;i<=n;i++){
            scanf("%s%d",h,&g[i][1]);
            if(h[2]=='d')g[i][0]=1;
            if(h[2]=='q')g[i][0]=2;
            if(h[2]=='e')g[i][0]=3;
            if(h[2]=='t'){
                if(h[1]=='l')g[i][0]=4;
                else g[i][0]=5;
            }
            if(g[i][0]!=1)scanf("%d",&g[i][2]);
        }
        i=1;j=0;
        while(i!=n+1&&!f[i][j]){
            f[i][j]=1;
            if(g[i][0]==1){
                j=(j+g[i][1])%256;
                i++;
            }
            if(g[i][0]==2){
                if(j==g[i][1])i=g[i][2];
                else i=i+1;
            }
            if(g[i][0]==3){
                if(j!=g[i][1])i=g[i][2];
                else i = i+1;
            }
            if(g[i][0]==4){
                if(j<g[i][1])i=g[i][2];
                else i=i+1;
            }
            if(g[i][0]==5){
                if(j>g[i][1])i=g[i][2];
                else i=i+1;
            }
        }
        if(i==n+1)printf("Yes\n");
        else printf("No\n");
        for(i=1;i<=n;i++)memset(f[i],0,sizeof(f[i]));
    }
}

