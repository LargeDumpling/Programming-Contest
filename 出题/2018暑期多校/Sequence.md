#Sequence
####2S/256MB
##Description
Let us define a sequence as below
$$\begin{eqnarray*}
F_1 &=& A \\
F_2 &=& B \\
F_n &=& CF_{n-2}+DF_{n-1}+\lfloor\frac{P}{n}\rfloor
\end{eqnarray*}$$
	Your job is simple, for each task, you should output $F_n$ module $10^9+7$.
##Input
The first line has only one integer $T$, indicates the number of tasks.
	Then, for the next $T$ lines, each line consists of $6$ integers, $A$ , $B$, $C$, $D$, $P$, $n$.
$1 \leq T \leq 20 \\
0 \leq A, B, C, D \leq 10^9 \\
1 \leq P, n \leq 10^9$
##Sample Input
1
3 3 2 1 3 5
3 2 2 2 1 4
##Sample Output
36
24
