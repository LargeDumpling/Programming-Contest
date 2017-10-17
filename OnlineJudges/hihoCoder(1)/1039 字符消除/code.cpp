#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int T,Lenth,L[105],R[105];
char tex[105];
void init()
{
	R[0]=1;
	L[Lenth+1]=Lenth;
	tex[0]='\000';tex[Lenth+1]='\001';
//	L[Lenth+2]=R[Lenth+2]=Lenth+2;
	for(int i=1;i<=Lenth;i++)
		L[i]=i-1,R[i]=i+1;
	return;
}
int calc(int pos,int x)
{
	int sum=0,now,next,sum1=0;
	bool flag=true;
	R[Lenth+2]=R[pos];
	L[Lenth+2]=pos;
	L[R[Lenth+2]]=Lenth+2;
	R[L[Lenth+2]]=Lenth+2;
	tex[Lenth+2]=x+'A';
	while(flag)
	{
		flag=false;
		for(now=0;now!=Lenth+1;now=next)
		{
			next=R[now];
			sum1=1;
			while(tex[now]==tex[next])
			{
				sum1++;
				next=R[next];
			}
			if(sum1!=1)
			{
				sum+=sum1;
				L[next]=L[now];
				R[L[now]]=next;
				flag=true;
			}
		}
	}
	return sum;
}
int main()
{
	int ans=0,temp;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%s",tex+1);
		Lenth=strlen(tex+1);
		for(int i=1,j;i<=Lenth;i++)
			for(j=0;j<=2;j++)
			{
				init();
				temp=calc(i,j);
				ans=max(ans,temp);
			}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

