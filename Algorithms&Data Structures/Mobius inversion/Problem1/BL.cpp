#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,ans=0;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool check(int x)
{
	if(x==1)return false;
	for(int i=sqrt(x);i>=2;i--)
		if(!(x%i))
			return false;
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(check(gcd(i,j)))
				ans=ans==mod-1?0:ans+1;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

