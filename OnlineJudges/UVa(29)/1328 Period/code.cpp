/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int lenth,pre[1000050];
char str[1000050];
void get_fail()
{
	memset(pre,-1,sizeof(pre));
	for(int i=1,k=-1;i<lenth;i++)
	{
		while(k>=0&&str[i]!=str[k+1])k=pre[k];
		if(str[i]==str[k+1])k++;
		pre[i]=k;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d",&lenth)!=-1&&lenth;cAse++)
	{
		printf("Test case #%d\n",cAse);
		scanf("%s",str);
		get_fail();
		for(int i=0;i<lenth;i++)// printf("%d ",pre[i]);
			if(pre[i]>=0&&!((i+1)%(i-pre[i])))
				printf("%d %d\n",i+1,(i+1)/(i-pre[i]));
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

