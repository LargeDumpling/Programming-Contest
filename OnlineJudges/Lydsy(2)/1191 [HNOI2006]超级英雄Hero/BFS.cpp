queue<int>Q;
int prev[__maxNodes];
int Hungarian()
{
    int ans=0;
    memset(matching,-1,sizeof(matching));
	memset(check,-1,sizeof(check));
    for(int i=0;i<num_left;++i)
	{
        if(matching[i]==-1)
		{
            while(!Q.empty())Q.pop();
            Q.push(i);
            prev[i]=-1;// 设 i 为路径起点
            bool flag=false;// 尚未找到增广路
            while(!Q.empty()&&!flag)
			{
                int u=Q.front();
                for(iterator_tix=G[u].begin();ix!=G[u].end()&&!flag;++ix)
				{
                    int v=edges[*ix].to;
                    if(check[v]!=i)
					{
                        check[v]=i;
                        Q.push(matching[v]);
                        if(matching[v]>=0)
						{// 此点为匹配点
                            prev[matching[v]]=u;
                        }
						else
						{// 找到未匹配点，交替路变为增广路
                            flag=true;
                            int d=u,e=v;
                            while(d!=-1)
							{
                                int t=matching[d];
                                matching[d]=e;
                                matching[e]=d;
                                d=prev[d];
                                e=t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if(matching[i]!=-1)++ans;
       }
    }
    return ans;
}
