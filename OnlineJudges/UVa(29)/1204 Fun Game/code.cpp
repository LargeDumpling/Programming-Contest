/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x7f7f7f7f;
struct jp
{
	char str[105];
	int len;
	jp() { }
	jp(char *T)
	{
		len=0;
		while(*T!='\0')
			str[len++]=*(T++);
	}
	bool operator<(const jp &x)const
	{
		for(int i=0;i<=len&&i<=x.len;i++)
			if(str[i]<x.str[i])
				return true;
			else if(str[i]>x.str[i])
				return false;
		return false;
	}
	bool operator==(const jp &x)const
	{
		if(len!=x.len) return false;
		for(int i=0;i<len;i++)
			if(str[i]!=x.str[i])
				return false;
		return true;
	}
	char operator[](const int &x)const { return str[x]; }
	char &operator[](const int &x){ return str[x]; }
}tex[32],wor[32];
int n,nn,f[65536][32],com[32][32];
bool check(int a,int b)
{
	for(int i=0,j;i<=tex[a].len-tex[b].len;i++)
	{
		for(j=0;j<tex[b].len&&tex[a][i+j]==tex[b][j];j++);
		if(j==tex[b].len)
			return true;
	}
	return false;
}
int calc_com(int a,int b)
{
	for(int i=max(0,wor[a].len-wor[b].len),j;i<wor[a].len;i++)
	{
		for(j=0;i+j<wor[a].len&&j<wor[b].len&&wor[a][i+j]==wor[b][j];j++);
		if(i+j==wor[a].len)
			return j;
	}
	return 0;
}
int calc_com2(int a,int b)
{
	for(int i=max(1,wor[a].len-wor[b].len),j;i<wor[a].len;i++)
	{
		for(j=0;i+j<wor[a].len&&j<wor[b].len&&wor[a][i+j]==wor[b][j];j++);
		if(i+j==wor[a].len)
			return j;
	}
	return 0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&n)!=-1&&n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",tex[i].str);
			tex[i].len=strlen(tex[i].str);
			tex[i+n]=tex[i];
			for(int j=(tex[i].len>>1)-1;j>=0;j--)
				swap(tex[i+n][j],tex[i+n][tex[i].len-j-1]);
		}
		sort(tex,tex+n+n);
		n=unique(tex,tex+n+n)-tex;
		for(int i=0;i<n;i++)
		{
			tex[i].len=strlen(tex[i].str);
			tex[i+n]=tex[i];
			for(int j=(tex[i].len>>1)-1;j>=0;j--)
				swap(tex[i+n][j],tex[i+n][tex[i].len-j-1]);
		}
		nn=0;
		for(int i=0;i<n;i++)
		{
			bool flag=true;
			for(int j=0;j<n&&flag;j++)
				if(i!=j&&(check(j,i)))
					flag=false;
			if(flag) wor[nn++]=tex[i];
		}
		sort(wor,wor+nn);
		nn=unique(wor,wor+nn)-wor;
		memset(f,127,sizeof(f));
		for(int i=0;i<nn;i++)
		{
			//f[1<<i][i]=f[1<<i][i+nn]=wor[i].len;
			wor[i+nn]=wor[i];
			for(int j=(wor[i].len>>1)-1;j>=0;j--)
				swap(wor[i+nn][j],wor[i+nn][wor[i].len-j-1]);
		}
		f[1][0]=wor[0].len;
		for(int i=0;i<nn*2;i++)
			for(int j=0;j<nn*2;j++)
				com[i][j]=calc_com(i,j);
		for(int S=0;S<65536;S++)
		{
			for(int i=0;i<nn*2;i++)
				if((i<nn&&(S&(1<<i)))||(nn<=i&&(S&(1<<(i-nn)))))
				{
					for(int j=0;j<nn*2;j++)
						if((j<nn&&!(S&(1<<j)))||(nn<=j&&!(S&(1<<(j-nn)))))
						{
							int Sp=j<nn?(S|(1<<j)):(S|(1<<(j-nn)));
							f[Sp][j]=min(f[Sp][j],f[S][i]+wor[j].len-com[i][j]);
						}
				}
		}
		int ans=0x7f7f7f7f,limit=1<<nn;
		for(int i=0;i<nn*2;i++)
			ans=min(ans,f[limit-1][i]-calc_com2(i,0));
		if(ans<=1) ans=2;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

