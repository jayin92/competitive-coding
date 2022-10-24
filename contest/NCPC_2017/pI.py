from collections import defaultdict
import queue



n = int(input())
name = list(input().split(" "))

adj = dict()

for i in name:
    adj[i] = list()

for i in range(n):
    cur, n = input().split(" ")
    n = int(n)
    for j in range(n):
        s = list(input().split(" "))
        if len(s) == 2:
            if s[1][-1] == ',':
                adj[cur].append(s[1][:-1])
            else:
                adj[cur].append(s[1])
        else:
            for ss in s[1:]:
                if ss[-1] == ',':
                    adj[cur].append(ss[:-1])
                else:
                    adj[cur].append(ss)

def false():
    return False


def bfs(src):
    vis = defaultdict(false)
    q = []
    q.append(src)
    step = 1
    while len(q) != 0:
        sz = len(q)
        for i in range(sz):
            cur = q.pop(0)
            for i in adj[cur]:
                if i == src:
                    return step
                if not vis[i]:
                    vis[i] = True
                    q.append(i)
        step += 1    
    return None

path = []

ans = 1e10
tar = ""
for i in name:
    tmp = bfs(i)
    if tmp and tmp < ans:
        ans = tmp
        tar = i

if ans == 1e10:
    print("SHIP IT")
    exit(0)

def dfs(src, cur, vis, dep):
    if dep != 0 and src == cur:
        if dep != ans:
            return
        for i in path[:-1]:
            print(i, end=" ")
        print(path[-1])
        exit(0)
    vis[cur] = True
    path.append(cur)
    for i in adj[cur]:
        if i == src or not vis[i]:
            dfs(src, i, vis, dep+1)
    path.pop()

dfs(tar, tar, defaultdict(false), 0)