#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num[100050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int opt,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&a,&b);
			num[a]+=b;
		}
		else if(opt==2)
		{
			scanf("%d%d%d",&a,&b,&c);
			for(int j=a;j<=b;j++)
				num[j]+=c;
		}
		else if(opt==3)
		{
			scanf("%d",&a);
			printf("%d\n",num[a]);
		}
		else if(opt==4)
		{
			scanf("%d%d",&a,&b);
			c=0;
			for(int j=a;j<=b;j++)
				c+=num[j];
			printf("%d\n",c);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

