# -*- coding:utf8 -*




class Edge:

    def __init__(self,u,v,w,c):
        self.u = u
        self.v = v
        self.w = w
        self.c = c


class Union:
    def __init__(self,n):
        self.n = n
        self.tree = list(range(n+1))
        self.weights = [1]*(n+1)

    def connect(self,u,v):
        if self.weights[u] < self.weights[v]:
            self.weights[v] += self.weights[u]
            self.tree[u] = v
        else:
            self.weights[u] += self.weights[v]
            self.tree[v] = u

    def find_parent(self,u):
        while self.tree[u] != u:
            u = self.tree[u]
        return u

    def part_num(self,j):
        c = 0
        for i in range(1,self.n+1):
            if i != j and self.tree[i] == i:
                c += 1
        return c


def min_tree(n,edges):
    edges.sort(key=lambda x:x.w)
    max_val = 0
    MAX = 10000000
    cost = [0] * (n + 1)
    for i in range(1,n+1):
        union = Union(n)
        tmp = []
        for edge in edges:
            u,v,w,c = edge.u,edge.v,edge.w,edge.c
            if i in (u,v):
                continue
            if c == 1:
                parent_u = union.find_parent(u)
                parent_v = union.find_parent(v)
                if parent_v != parent_u:
                    union.connect(parent_v,parent_u)
                continue
            tmp.append(edge)
        for edge in tmp:
            u, v, w, c = edge.u, edge.v, edge.w, edge.c
            parent_u = union.find_parent(u)
            parent_v = union.find_parent(v)
            if parent_v != parent_u:
                union.connect(parent_u,parent_v)
                cost[i] += w

        if union.part_num(i) > 1:
            cost[i] = max(cost[i],MAX)

        max_val = max(cost[i],max_val)

    if max_val > 0:
        flag = True
        for i in range(1,n+1):
            if cost[i] == max_val:
                if flag:
                    print(i,end='')
                    flag = False
                else:
                    print(' '+str(i))
        return
    print(0)


def construct():
    s = """4 5
    1 2 1 1
    1 3 1 1
    2 3 1 0
    2 4 1 1
    3 4 1 0"""

    s1 = """4 5
    1 2 1 1
    1 3 1 1
    2 3 1 0
    2 4 1 1
    3 4 2 1"""

    arr = s.split('\n')
    edges = []
    n,m = [int(t) for t in arr[0].split(' ')]
    for i in range(1,m+1):
        u, v, w, c = [int(t) for t in arr[i].split(' ')]
        edges.append(Edge(u, v, w, c))
    min_tree(n,edges)


# construct()

if __name__ == '__main__':
    edges = []
    line = input()
    n,m = [int(t) for t in line.split(' ')]
    for i in range(m):
        line = input()
        u, v, w, c = [int(t) for t in line.split(' ')]
        edges.append(Edge(u, v, w, c))
    min_tree(n,edges)







