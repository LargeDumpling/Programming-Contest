#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int u[100050],p[100050];
bool exist[100050];
void Mobius()
{
	memset(exist,true,sizeof(exist));
	u[1]=1;
	for(int i=2;i<100050;i++)
	{
		if(exist[i]) p[++p[0]]=i,u[i]=-1;
		for(int j=1;i*p[j]<100050&&j<=p[0];j++)
		{
			exist[i*p[j]]=false;
			if(i%p[j]) u[i*p[j]]=-u[i];
			else
			{
				u[i*p[j]]=0;
				break;
			}
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	scanf("%d",&n);
	Mobius();
	for(int i=1;i<=n&&i<100050;i++)
		printf("%d %d\n",i,u[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

