#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<numeric>
using namespace std;
typedef int ll;
const int N=10;
ll dp[N+1][10];//dp[i][j]表示第i位为j的windy数的个数
void mk_tb(){
    for(int i=0;i<=9;i++)dp[1][i]=1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(abs(j-k)>=2){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
}
ll f(ll n){
    int ans=0,a[N+1]={0},len=0;
    for(int tmp=n;tmp;tmp/=10)a[++len]=tmp%10;
    for(int i=1;i<len;i++)ans+=accumulate(dp[i]+1,dp[i]+N,0);
    for(int i=1;i<a[len];i++)ans+=dp[len][i];
    for(int i=len;--i;){
        for(int j=0;j<a[i];j++)if(abs(j-a[i+1])>=2)ans+=dp[i][j];
        if(abs(a[i]-a[i+1])<2)break;
    }
    return ans;
}
int main() {
    freopen("code.in","r",stdin);
    freopen("showson.out","w",stdout);
    
    mk_tb();
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",f(b+1)-f(a));
    
    return 0;
}
