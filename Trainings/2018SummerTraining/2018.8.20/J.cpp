/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2018-08-20    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n[2],A[2][3];
void adjust(int x)
{
    A[x][0]+=2;
    A[x][1]+=1;
    switch(n[x])
    {
        case 1:
            break;
        case 2:
            if(A[x][1]<A[x][0])
                swap(A[x][0],A[x][1]);
            break;
        case 3:
			if(A[x][2]<A[x][1])
				swap(A[x][1],A[x][2]);
            break;
        default:
            break;
    }
    return;
}
int dcmp(int x)
{
    if(!x) return 0;
    return x<0?-1:1;
}
int comp(int a,int b)
{
    switch(n[a])
    {
        case 1:
            return dcmp(A[a][0]-A[b][0]);
            break;
        case 2:
            return dcmp(A[a][0]-A[b][0]);
            break;
        case 3:
			/*if(A[a][0]<A[a][1]&&A[b][0]<A[b][1])
				return dcmp(A[a][0]-A[b][0]);
			else if(A[a][1]<=A[a][0]&&A[b][0]<A[b][1])
			{
				if(A[a][1]==A[b][0])
					return -1;
				else return dcmp(A[a][1]-A[b][0]);
			}
			else if(A[b][1]<=A[b][0]&&A[a][0]<A[a][1])
			{
				if(A[b][1]==A[a][0])
					return 1;
				else return dcmp(A[a][0]-A[b][1]);
			}
			else if(A[a][1]<=A[a][0]&&A[b][1]<=A[b][0])
			{
				if(A[a][1]==A[b][1])
					return dcmp(A[a][2]-A[b][2]);
				return dcmp(A[a][1]-A[b][1]);
			}*/
			if(A[a][0]<A[a][1])
				A[a][1]=1000000050;
			else
			{
				A[a][0]=A[a][1];
				A[a][1]=A[a][2];
			}
			if(A[b][0]<A[b][1])
				A[b][1]=1000000050;
			else
			{
				A[b][0]=A[b][1];
				A[b][1]=A[b][2];
			}
			if(A[a][0]==A[b][0])
				return dcmp(A[a][1]-A[b][1]);
			return dcmp(A[a][0]-A[b][0]);
            break;
        default:
            break;
    }
    return 0;
}
int main()
{
    scanf("%d",&T_T);
    while(T_T--)
    {
        scanf("%d%d",&n[0],&n[1]);
        for(int k=0;k<2;k++)
        {
            for(int i=0;i<n[k];i++)
                scanf("%d",&A[k][i]);
            adjust(k);
        }
        if(n[0]<n[1]) for(int i=n[0];i<n[1];i++)
            A[0][i]=1000000050;
        else if(n[1]<n[0]) for(int i=n[1];i<n[0];i++)
            A[1][i]=1000000050;
        n[0]=max(n[0],n[1]);
        switch(comp(0,1))
        {
            case -1:
                puts("1");
                break;
            case 0:
                puts("0");
                break;
            case 1:
                puts("-1");
                break;
            default:
                break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

