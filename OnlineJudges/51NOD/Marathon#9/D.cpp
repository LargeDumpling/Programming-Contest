#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long f1,f2,f3;
int main()
{
    long long n,x=128;
    scanf("%lld",&n);
    if(n==1)printf("32");
    else
    {
        f1=1;
        f2=32;
        n-=1;
        for(long long i=1;i<=n;i++)
        {
            f3=(x*f1%mod+32*f2%mod)%mod;
            f1=f2;
            f2=f3;
        }
        printf("%lld",f2);
    }
    return 0;
}
