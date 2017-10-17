/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
char tex[10050][50];
int len[10050],n;
void solve()
{
	set<string>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<len[i];k++)
				for(int l=0;l<len[j];l++)
				{
					string temp;
					for(int p=0;p<=k;p++) temp.push_back(tex[i][p]);
					for(int p=l;p<len[j];p++) temp.push_back(tex[j][p]);
					s.insert(temp);
				}
	for(int i=1;i<=n;i++)
	{
		string temp(tex[i]);
		s.insert(temp);
	}
	cout<<s.size()<<"\n";
	//for(set<string>::iterator it=s.begin();it!=s.end();it++)
		//cout<<*it<<"\n";
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	while(scanf("%d",&n)!=-1&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex[i]);
			len[i]=strlen(tex[i]);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

