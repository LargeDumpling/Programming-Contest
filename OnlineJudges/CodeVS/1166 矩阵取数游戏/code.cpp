#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int n,m;
struct jp
{
	int num[30],ws;
	jp()
	{
		memset(num,0,sizeof(num));
		ws=0;
	}
	jp(int x)
	{
		memset(num,0,sizeof(num));
		if(x==0)
			ws=1;
		else
			for(ws=0;x;ws++,x/=10)
			num[ws]=x%10;
	}
	bool operator<(const jp X)const
	{
		if(ws<X.ws)
			return true;
		else if(ws>X.ws)
			return false;
		for(int i=ws-1;i>=0;i--)
			if(num[i]<X.num[i])
				return true;
			else if(num[i]>X.num[i])
				return false;
		return false;
	}
	jp operator+(const jp X)const
	{
		jp C;
		C.ws=X.ws>ws?X.ws:ws;
		for(int i=0;i<C.ws;i++)
		{
			C.num[i]+=num[i]+X.num[i];
			if(C.num[i]>=10)
			{
				C.num[i+1]++;
				C.num[i]-=10;
				if(i==C.ws-1)
					C.ws++;
			}
		}
		return C;
	}
	jp operator*(const jp X)const
	{
		jp tem;
		tem.ws=X.ws+ws;
		for(int i=0;i<tem.ws;i++)
		{
			for(int j=0;j<=i;j++)
				tem.num[i]+=X.num[j]*num[i-j];
			if(tem.num[i]>=10)
			{
				tem.num[i+1]+=tem.num[i]/10;
				tem.num[i]%=10;
				if(i==tem.ws-1)
					tem.ws++;
			}
		}
		while(tem.num[tem.ws-1]==0)tem.ws--;
		return tem;
	}
}num[100],f[100][100],er[100],ans=0,ans1=0;
int s[50];
void readln(jp &X)
{
	char ch;s[0]=0;X=jp(0);
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())s[++s[0]]=ch-'0';
	for(X.ws=0;s[0];X.num[X.ws++]=s[s[0]--]);
	return;
}
void writeln(jp X)
{
	for(int i=X.ws-1;i>=0;i--)
		printf("%c",X.num[i]+'0');
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int i,j,k;
	jp a=jp(2);
	er[0]=1;
	ans=ans1=jp(0);
	for(int i=1;i<100;i++)
		er[i]=er[i-1]*a;
	scanf("%d%d",&n,&m);
	for(k=1;k<=n;k++)
	{
		//memset(f,0,sizeof(f));
		ans1=jp(0);
		for(i=1;i<=m;i++)
		{
			//scanf("%d",&num[i]);
			readln(num[i]);
			for(int j=0;j<=i;j++)
				f[i][j]=jp(0);
		}
		for(i=1;i<=m;i++)
			for(j=0;j<=i;j++)
			{
				f[i][j]=max(f[i][j],f[i-1][j]+num[m-i+j+1]*er[i]);
				if(j>0)
					f[i][j]=max(f[i][j],f[i-1][j-1]+num[j]*er[i]);
			}
		for(int i=0;i<=m;i++)
			if(!(f[m][i]<ans1))
				ans1=f[m][i];
		ans=ans+ans1; 
	}
	//printf("%d",ans);
	writeln(ans);
	fclose(stdin);
	fclose(stdout);
    return 0;
}

