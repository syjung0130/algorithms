
def dfs(graph, v, visited):
    visited[v] = True
    print(v)

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def dfs_s(graph, start_vertex):
    visited = []
    stack = [start_vertex]
    while stack:
        vertex = stack.pop()
        # print(vertex)
        if vertex not in visited:
            print(vertex)
            visited.append(vertex)
            for item in graph[vertex]:
                stack.append(item)
    return visited

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
dfs(graph, 1, visited)
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