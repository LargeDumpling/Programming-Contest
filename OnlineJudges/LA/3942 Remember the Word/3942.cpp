#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int val[400050],ch[400050][26],ans[300050],len[4005],sz=0,n,m;
char tex[300050],temp[4005][105];
void insert(char T[],int x)
{
	int lenth=strlen(T),u=0;
	for(int i=0;i<lenth;u=ch[u][T[i++]-97])
		if(!ch[u][T[i]-97])
			ch[u][T[i]-97]=++sz;
	val[u]=x;
	return;
}
void find(int sta)
{
	int u=0;
	for(int i=sta;i<m&&ch[u][tex[i]-97];u=ch[u][tex[i++]-97])
		if(val[ch[u][tex[i]-97] ])
			ans[sta]=(ans[sta]+ans[sta+len[val[ch[u][tex[i]-97]]]])%20071027;
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("3942.txt","w",stdout);
	char temp[105];
	for(int k=1;;k++)
	{
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
		memset(ans,0,sizeof(ans));
		sz=0;
		if(scanf("%s%d",tex,&n)==-1)
			break;
		m=strlen(tex);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",temp);
			len[i]=strlen(temp);
			insert(temp,i);
		}
		ans[m]=1;
		for(int i=m-1;i>=0;i--)
			find(i);
		printf("Case %d: %d\n",k,ans[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


