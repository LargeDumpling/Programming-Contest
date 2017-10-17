/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2016-03-22  File created.
*/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,L,l,r,q[50050];
long long C[50050],S[50050],f[50050],c;
long long calc_y(int x) { return f[x]+S[x]*S[x]-2*c*S[x]; }
long long calc_x(int x) { return -2*S[x]; }
double Slope(int a,int b)
//{ return (double)(calc_y(b)-calc_y(a))/(calc_x(b)-calc_x(a)); }
{ return (f[b]-f[a]+(S[b]+c)*(S[b]+c)-(S[a]+c)*(S[a]+c))/(2.0*(S[b]-S[a])); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("pre.out","w",stdout);
    scanf("%d%d",&n,&L);
    c=L+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&C[i]);
        //printf("%d ",S[i]=S[i-1]+C[i]+1);
        S[i]=S[i-1]+C[i]+1;
    }
    //putchar('\n');
    l=1; r=0; q[++r]=0;
    for(int i=1;i<=n;i++)
    {
        while(l<r&&Slope(q[l],q[l+1])<=S[i]) l++;
        //printf("%d %d\n",i,q[l]);
        f[i]=f[q[l]]+(S[i]-S[q[l]]-c)*(S[i]-S[q[l]]-c);
        while(l<r&&Slope(q[r],i)<Slope(q[r-1],q[r])) r--;
        q[++r]=i;
    }
    printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
