#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		a=a%b;
		a^=b;
		b=a^b;
		a^=b;
	}
	return a;
}
int f(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
		for(int j=i+1;j<=x;j++)
			if(ans<gcd(i,j))
				ans=gcd(i,j);
	return ans;
}
int calc(int x)
{
	int ans=0;
	for(int i=2;i<=2*x+1;i++)
		ans=(ans+f(i)*f(i))%10007;
	return ans;
}
int main()
{
	freopen("T1.in","r",stdin);
	freopen("T1_BL.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%d",calc(n));
	fclose(stdin);
	fclose(stdout);
    return 0;
}

