#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int du[26],end[100050],next[100050],fir[26],ed=0;
int get_len(char tex[])
{
	int k=0;
	while(tex[k]!='\0')k++;
	return k;
}
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,T,lenth,pri;
	char tex[1050];
	scanf("%d",&T);
	while(T--)
	{
		pri=0;
		scanf("%d",&n);
		for(int i=0;i<26;i++)
			du[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex);
			lenth=get_len(tex);
			addedge(tex[0]-'a',tex[lenth-1]-'a');
			du[tex[0]-'a']++;
			if(du[tex[0]-'a']&1)
				pri++;
			else
				pri--;
			du[tex[lenth-1]-'a']++;
			if(du[tex[lenth-1]-'a']&1)
				pri++;
			else
				pri--;
		}
		if(pri&&pri!=2)
			printf("The door cannot be opened. \n");
		else
			printf("Ordering is possible. \n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

