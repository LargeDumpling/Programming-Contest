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
            prev[i]=-1;// �� i Ϊ·�����
            bool flag=false;// ��δ�ҵ�����·
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
						{// �˵�Ϊƥ���
                            prev[matching[v]]=u;
                        }
						else
						{// �ҵ�δƥ��㣬����·��Ϊ����·
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
