#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int f[550][550],ans=0,Lenth;
char tex[550];
int calc(char *A,int LenA,char *B,int LenB)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=LenA;i++)
	{
		for(int j=1;j<=LenB;j++)
		{
			f[i][j]=max(max(f[i][j],f[i-1][j-1]),max(f[i][j-1],f[i-1][j]));
			if(A[i-1]==B[j-1])
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	}
	return f[LenA][LenB];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ch;
	scanf("%d",&Lenth);
	for(ch=getchar();ch<'a'||'z'<ch;ch=getchar());
	for(int i=1;i<=Lenth;i++)
	{
		tex[i-1]=ch;
		ch=getchar();
	}
	tex[Lenth]='\0';
	for(int i=1;i<Lenth;i++)
		ans=max(ans,calc(tex,i,tex+i,Lenth-i));
	printf("%d",Lenth-ans*2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

