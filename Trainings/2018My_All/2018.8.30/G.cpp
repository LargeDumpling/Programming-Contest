/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int T_T,n,cnt[MAXN],kth[MAXN],x[MAXN],y[MAXN],Log[MAXN];
long long nex[40][MAXN];
char str[MAXN],tex[MAXN];
int main()
{
	//int *x=t1,*y=t2,u;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	long long *nek,*nek2;
	Log[0]=-1;
	for(int i=1;i<MAXN;i++) Log[i]=Log[i>>1]+1;
	int u,t;
	scanf("%d",&T_T);
	memset(cnt,0,sizeof(cnt));
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d",&n);
		scanf("%s",str);
		t=Log[n];
		if((n&-n)!=n) t++;
		for(int i=0;i<n;i++) cnt[str[i]-'0']++;
		for(int i=8;0<=i;i--) cnt[i]+=cnt[i+1];
		nek=nex[0];
		for(long long i=n-1;0<=i;i--)
		{
			nek[i]=(i*i+1LL)%n;
			kth[x[i]=--cnt[str[i]-'0']]=i;
		}
		for(int i=0;i<10;i++) cnt[i]=0;
		for(int k=1;k<19;k++)
		{
			nek=nex[k];
			nek2=nex[k-1];
			for(int i=0;i<n;i++) cnt[x[nek2[i]]]++;
			for(int i=1;i<n;i++) cnt[i]+=cnt[i-1];
			for(int i=n-1;0<=i;i--) y[--cnt[x[nek2[i]]]]=i;
			for(int i=0;i<n;i++) cnt[i]=0;

			for(int i=0;i<n;i++) cnt[x[y[i]]]++;
			for(int i=1;i<n;i++) cnt[i]+=cnt[i-1];
			for(int i=n-1;0<=i;i--) kth[--cnt[x[y[i]]]]=y[i];
			for(int i=0;i<n;i++) x[kth[i]]=i;
			for(int i=0;i<n;i++)
			{
				nek[i]=nek2[nek2[i]];
				cnt[i]=0;
			}
		}
		/*for(int i=0;i<n;i++)
			printf("%d ",kth[i]);
		putchar('\n');*/
		printf("Case #%d: ",T);
		u=kth[0];
		for(int i=0;i<n;i++)
		{
			putchar(str[u]);
			//tex[i]=str[u];
			//u=nex[u][0];
			u=((long long)u*u+1)%n;
		}
		putchar('\n');
		//tex[n]='\0';
		//puts(tex);
		//cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

