#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[1000050];
int pre[1000050],n;
void getfail()
{
	pre[0]=-1;
	for(int i=1,k=-1;i<n;i++)
	{
		while(k>=0&&tex[i]!=tex[k+1])
			k=pre[k];
		if(tex[i]==tex[k+1])
			k++;
		pre[i]=k;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int k=1;;k++)
	{
		scanf("%d",&n);
		if(!n)
			break;
		printf("Test case #%d\n",k);
		scanf("%s",tex);
		getfail();
//		for(int i=0;i<n;i++)
//			printf("%d ",pre[i]);
//		printf("\n");
		for(int i=0;i<n;i++)
			if(pre[i]>=0&&!((i+1)%(i-pre[i])))
				printf("%d %d\n",i+1,(i+1)/(i-pre[i]));
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

