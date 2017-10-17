#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>

#include<cstring>

using namespace std;



long long n,a[200+10];

long long f[200+10][200+10];



long long max(long long x,long long y){

if(x>y)

return x;

else

return y;

}



long long mdfs(int l,int r){

if(f[l][r]!=-1){

return f[l][r];

}

if(l+1==r){

return f[l][r]=0;

}

long long cans=-1;

for(long long k=l+1;k<r;k++){

cans=max(cans,mdfs(l,k)+mdfs(k,r)+a[l]*a[r]*a[k]);

}

return f[l][r]=cans;

}



void work(){

long long ans=-1;

for(long long i=1;i<=n;i++){

long long cans=mdfs(i,i+n);

ans=max(ans,cans);

}

printf("%lld",ans);

}



void read(){

scanf("%lld",&n);

for(long long i=1;i<=n;i++){

scanf("%lld",&a[i]);

a[i+n]=a[i];

}

memset(f,-1,sizeof(f));

}



int main(){
freopen("code.in","r",stdin);
freopen("other.out","w",stdout);
read();

work();

}
