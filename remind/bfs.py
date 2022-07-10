# -*- coding: utf-8 -*-
from collections import deque
def bfs(graph, start, visited):
    q = deque()
    q.append(start)

    while q:
        v = q.popleft()
        if visited[v] == False:
            print(v, end=' ')
            visited[v] = True
        for i in graph[v]:
            if visited[i] == False:
                q.append(i)


if __name__ == "__main__":
    graph = [
        [],
        [2, 3, 8],
        [1, 7],
        [1, 4, 5],
        [3, 5],
        [3, 4],
        [7],
        [2, 6, 8],
        [1, 7]
    ]

    visited = [False] * 9

    bfs(graph, 1, visited)

    print(" ")
    print("bfs check")
    # 1 2 3 8 7 4 5 6