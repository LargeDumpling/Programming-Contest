#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int dp[10][3];//dp[i]表示第i位,dp[i][0]吉利的,dp[i][1]第一位为2的吉利的，dp[i][2]为不吉利的 
void table_maker() {
    dp[0][0]=1;
    for(int i=1;i<=6;i++){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
    }
}
int calc(int n) {
    int a[10]={0},ans=0,flag=0,tmp=n*10,len=0;
    for(;tmp/=10;)a[++len]=tmp%10;
    for(int i=len;i>=1;i--){
        ans+=a[i]*dp[i-1][2];
        if(flag)ans+=a[i]*dp[i-1][0];
        else{
            if(a[i]>4)ans+=dp[i-1][0];
            if(a[i]>6)ans+=dp[i-1][1];
            if(a[i+1]==6&&a[i]>2)ans+=dp[i][1];
            if(a[i]==4||(a[i+1]==6&&a[i]==2))flag=1;
        }
    }
    return n-ans;
}

int main() {
    freopen("code.in","r",stdin);
    freopen("showson.out","w",stdout);
    
    table_maker();
    for(int l,r;~scanf("%d%d",&l,&r)&&(l||r);)printf("%d\n",calc(r+1)-calc(l));
    return 0;
}
