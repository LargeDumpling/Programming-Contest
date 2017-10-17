/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
int q,n,sz=0,num[100050][20],pre[100050];
int get_pos(int x){return std::lower_bound(pre+1,pre+sz+1,x)-pre;}
int max(int a,int b){return a<b?b:a;}
void st_pre()
{
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<(i-1))<=n;j++)
			num[j][i]=max(num[j][i-1],num[j+(1<<(i-1))][i-1]);
	return;
}
int RMQ(int l,int r)
{
	if(l>r)return 0;
	int x,len=r-l+1;
	for(x=0;(1<<(x+1))<len;x++);
	len=1<<x;
	return max(num[l][x],num[r-len+1][x]);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,x,ans,A,B;
	while(scanf("%d",&n)!=-1&&n)
	{
		scanf("%d%d",&q,&b);
		memset(num,0,sizeof(num));
		x=1;
		sz=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(a==b)x++;
			else
			{
				num[++sz][0]=x;
				b=a;
				x=1;
			}
		}
		num[++sz][0]=x;
		for(int i=1;i<=sz;i++)pre[i]=pre[i-1]+num[i][0];
		st_pre();
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&a,&b);
			A=get_pos(a);B=get_pos(b);
			if(A==B)ans=b-a+1;
			else ans=max(RMQ(A+1,B-1),max(pre[A]-a+1,b-pre[B-1]));
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

