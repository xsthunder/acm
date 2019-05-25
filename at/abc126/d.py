# 二分图染色，本题中图是树
read = input
n = int(read())
v = [[] for i in range(n+1)] # 邻接
used = [0 for i in range(n+1)] # 节点 1~n
def add(f,t,w):
    v[f].append((t, w))
for i in range(n-1):
    f,t,w = map(int, read().split())
    add(f,t,w)
    add(t,f,w)
# 从1出发，贪心即可，1画1，理论不会有回环
# def dfs(f, s, fa=-1):
#     if s % 2 == 0: 
#         used[f] = 1
#     for t, w in v[f]:
# #         print('%d->%d->%d'%(fa, f, t,), s, w)
#         if t == fa:continue
#         dfs(t, w + s, f)
from queue import Queue
q = Queue() # 队列
#def dfs(f, s, fa=-1):
#    if s % 2 == 0: 
#        used[f] = 1
#    for t, w in v[f]:
##         print('%d->%d->%d'%(fa, f, t,), s, w)
#        if t == fa:continue
#        dfs(t, w + s, f)
#
#
#dfs(1,0)
q.put_nowait((1, 0, -1))
while not q.empty():
    f, s, fa = q.get_nowait()
    if s % 2 == 0: 
        used[f] = 1
    for t, w in v[f]:
#         print('%d->%d->%d'%(fa, f, t,), s, w)
        if t == fa:continue
        q.put_nowait(
            (t, w + s, f)
        )
    
for i in used[1:]:
    print(used[i])
