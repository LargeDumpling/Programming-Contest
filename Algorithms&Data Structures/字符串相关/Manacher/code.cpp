/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=11000050;
char str[MAXL<<1];
int r[MAXL<<1],len;
/*
 * 1, str should have double lenth
 */
void Manacher()
{
	int rig=0,id=0;
	len=strlen(str);
	str[len<<1]='#';
	for(int i=len-1;0<=i;i--)
	{
		str[i<<1|1]=str[i];
		str[i<<1]='#';
	}
	r[0]=0;
	for(int i=1;i<=(len<<1);i++)
	{
		if(i<=rig) r[i]=min(rig-i,r[2*id-i]);
		else r[i]=0;
		while(0<=i-r[i]-1
				&&i+r[i]+1<=(len<<1)
				&&str[i-r[i]-1]==str[i+r[i]+1])
			r[i]++;
		if(rig<i+r[i])
		{
			rig=i+r[i];
			id=i;
		}
	}
	return;
}
int main()
{
	int ans=0;
	scanf("%s",str);
	Manacher();
	for(int i=0;i<=(len<<1);i++)
		ans=max(ans,r[i]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

