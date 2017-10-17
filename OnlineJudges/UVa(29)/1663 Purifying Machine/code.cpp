/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-26	File created.
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
map<string,int>s;
int get_ID(string x)
{
	if(!s.count(x))return s[x]=s.size();
	return 0;
}
int n,m,lEft[2050][2050],sz,rIght[2050];
bool exist[2050];
vector<string>str;
void addedge(int u,int v)
{
	//lEft[u][++lEft[u][0]]=v;
	lEft[v][++lEft[v][0]]=u;
	return;
}
bool check(string A,string B)
{
	int cnt=0;
	for(int i=0;i<n;i++)if(A[i]!=B[i])cnt++;
	return cnt==1;
}
bool fInd(int x)
{
	for(int i=1;i<lEft[x][0];i++)if(!exist[lEft[x][i]])
	{
		exist[lEft[x][i]]=true;
		if(!rIght[lEft[x][i]]||fInd(rIght[lEft[x][i]]))
		{
			rIght[lEft[x][i]]=x;
			return true;
		}
	}
	return false;
}
int max_match()
{
	memset(rIght,0,sizeof(rIght));
	int ans=0;
	for(int i=1;i<=sz;i++)
	{
		memset(exist,false,sizeof(exist));
		if(fInd(i+sz))ans++;
	}
	return ans>>1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	string tex;
	char tem[12];
	int pos,k;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		str.clear();
		//str.resize(m<<1);
		s.clear();
		memset(lEft,0,sizeof(lEft));
		//scanf("%d%d",&n,&m);
		tem[n]='\0';
		for(int i=1;i<=m;i++)
		{
			scanf("%s",tem);
			pos=-1;
			for(int j=0;j<n;j++)if(tem[j]=='*')pos=j;
			if(pos==-1)
			{
				tex=string(tem);
				k=get_ID(tex);
				if(k)str.push_back(tex);
			}
			else
			{
				tem[pos]='1';
				tex=string(tem);
				k=get_ID(tex);
				if(k)str.push_back(tex);
				tem[pos]='0';
				tex=string(tem);
				k=get_ID(tex);
				if(k)str.push_back(tex);
			}
			while(getchar()!='\n');
		}
		sz=s.size();
		for(int i=0;i<sz;i++)
			for(int j=i+1;j<sz;j++)
			{
				//cout<<str[i]<<" "<<str[j]<<" "<<i<<" "<<j<<"\n";
				if(check(str[i],str[j]))
					addedge(i+1,j+sz+1),addedge(j+1,i+sz+1);
			}
		printf("%d\n",m-(max_match()));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

