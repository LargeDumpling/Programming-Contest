#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[20050],ans;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("BL.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if((a[i]<a[j]&&a[j]<a[k])||(a[i]>a[j]&&a[j]>a[k]))
					ans++;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

