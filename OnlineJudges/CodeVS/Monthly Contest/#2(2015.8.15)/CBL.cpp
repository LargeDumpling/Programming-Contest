#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("CBL.out","w",stdout);
	int n,m,num[100050],a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1,sum;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
			num[b]=c;
		else if(a==2)
			for(int j=b;j<=c;j++)
				num[j]=log(num[j]);
		else if(a==3)
		{
			sum=0;
			for(int j=b;j<=c;j++)
				sum+=num[j];
			printf("%d\n",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

