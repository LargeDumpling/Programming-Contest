/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=105;
int len;
int cnt[26*26],ans=-1;
char str[MAXL];
int main()
{
	scanf("%d",&len);
	scanf("%s",str);
	for(int i=0;i<len-1;i++)
	{
		int k=(str[i]-'A')*26+str[i+1]-'A';
		cnt[k]++;
		if(ans==-1||cnt[ans]<cnt[k])
			ans=k;
	}
	printf("%c%c",ans/26+'A',ans%26+'A');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

