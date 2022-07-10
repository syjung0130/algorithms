# -*- coding: utf-8 -*-
def dfs_r(graph, visited, node):
    # vertex = graph[node]
    print("{0} ".format(node))
    visited[node] = True
    for i in graph[node]:
        if visited[i] == False:
            dfs_r(graph, visited, i)

def dfs_s(graph, start):
    stack = [start]
    visited = [False] * 9
    while stack:
        v = stack.pop()
        if visited[v] == False:
            print(v, end=' ')
            visited[v] = True
        for i in graph[v]:
            if visited[i] == False:
                stack.append(i)


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
print("recursive dfs: ")
dfs_r(graph, visited, 1)

print("\n stack dfs: ")
dfs_s(graph, 1)

# 1
# 2
# 7
# 6
# 8
# 3
# 4
# 5