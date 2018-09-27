#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=100050;
char tex[MAXL],T[MAXL];
int pre[MAXL];
int KMP()
{
	int n=strlen(tex),m=strlen(T),i,k;
	pre[0]=-1;
	for(i=1,k=-1;i<n;pre[i++]=k)
	{
		while(k>=0&&tex[i]!=tex[k+1])
			k=pre[k];
		if(tex[i]==tex[k+1])
			k++;
	}
	for(i=0,k=-1;i<m;i++)
	{
		while(k>=0&&T[i]!=tex[k+1])
			k=pre[k];
		if(T[i]==tex[k+1])
		{
			k++;
			if(k==n-1)
				return i-k;
		}
	}
	return -1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("KMP.out","w",stdout);
	scanf("%s%s",tex,T);
	printf("%d",KMP());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

