import sys, random
n = int (input ())
vs = list (range (1, n + 1))
root = 0

def query (x):
    print (' '.join (map (str, ['?', len (x)] + x)))
    sys.stdout.flush ()
    sz = int (input ())
    return sz

chl = {}
def solve (ls, vs):
    if len (vs) == 0:
        return []

    l = random.choice (ls)
    il, ol = [], []
    for v in vs:
        if v == l:
            continue
        if v in ls:
            has = False
        else:
            has = (query ([root, v, l]) == 3)
        (il if has else ol).append (v)

    nls = list (ls)
    nls.remove (l)
    res = solve (nls, ol)

    for v in il:
        chl[v] = set ([l])
        for u in res:
            if query ([root, v, list (chl[u])[0]]) == 3:
                chl[v] |= chl[u]

    return [v for v in vs if all (not chl[v] < chl[u] for u in vs)]

lvs = []
for v in vs:
    cvs = list (vs)
    cvs.remove (v)
    sz = query(cvs)
    if sz == n - 1:
        lvs.append (v)

root = random.choice (lvs)
for l in lvs:
    chl[l] = set ([l])
chl[root] = set (lvs)

lvs.remove (root)
vs.remove (root)
solve (lvs, vs)

p = {}
for v in vs:
    par = root
    for u in vs:
        if u == v or u == root:
            continue
        if chl[v] <= chl[u] and chl[u] <= chl[par]:
            par = u
    p[v] = par
p[root] = 0

v = 1
prev = 0
while v != 0:
    nv = p[v]
    p[v] = prev
    prev, v = v, nv

print (' '.join (map (str, ['!'] + [p[v] for v in range (2, n + 1)])))
sys.stdout.flush ()
