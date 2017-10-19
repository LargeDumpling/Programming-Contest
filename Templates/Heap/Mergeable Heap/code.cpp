template<typename Ty>
struct jp
{
	static const int MAXN=100050;
	int L[MAXN],R[MAXN],dist[MAXN],tOp,sz;
	Ty data[MAXN];
	jp()
	{
		tOp=sz=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
	}
	void clear()
	{
		tOp=sz=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
		return;
	}
	bool empty() { return (bool)tOp; }
	int merge(int A,int B)
	{
		if(!A) return B;
		if(!B) return A;
		if(data[A]<data[B]) swap(A,B);
		R[A]=merge(R[A],B);
		if(dist[L[A]]<dist[R[A]]) swap(L[A],R[A]);
		dist[A]=R[A]?dist[R[A]]+1:0;
		return A;
	}
	void push(Ty X)
	{
		data[++sz]=X;
		tOp=merge(tOp,sz);
		return;
	}
	void pop()
	{
		tOp=merge(L[tOp],R[tOp]);
		return;
	}
	Ty top() { return data[tOp]; }
};

