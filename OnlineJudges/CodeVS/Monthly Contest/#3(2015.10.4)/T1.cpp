#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("T1.in","r",stdin);
	freopen("T1.out","w",stdout);
	int n,mod=10007;
	long long ans=3336;
	scanf("%d",&n);
	ans=(((((ans*n)%mod)*(n+1))%mod)*(2*n+1))%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

