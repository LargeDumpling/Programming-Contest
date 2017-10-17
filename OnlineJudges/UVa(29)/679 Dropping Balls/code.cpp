#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		c=1;
		while(--a)
		{
			if(b&1)
			{
				c=c<<1;
				b=(b+1)>>1;
			}
			else
			{
				c=c<<1|1;
				b>>=1;
			}
		}
		printf("%d\n",c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
