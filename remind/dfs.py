# -*- coding: utf-8 -*-
def dfs_r(graph, visited, node):
    print(node, end=' ')
    visited[node] = True
    for child in graph[node]:
        if visited[child] == False:
            dfs_r(graph, visited, child)

def dfs_s(graph, start):
    stack = [start]
    visited = [False] * 10
    while stack:
        node = stack.pop()
        if visited[node] == False:
            print(node, end=' ')
            visited[node] = True
            for child in graph[node]:
                if visited[child] == False:
                    stack.append(child)
    print('')


if __name__ == "__main__":
    '''
          1
        / | \
       2  3  4
       |  
       5  
      / \ 
     6   7
    '''

    #트리라면,,
    tree = [
        [],
        [2, 3, 4],  #1
        [5],        #2
        [],         #3
        [],         #4
        [6, 7],     #5
        [],         #6
        []          #7
    ]
    print("### iterate tree ###")
    visited = [False] * 9
    print("recursive dfs: ")
    dfs_r(tree, visited, 1)

    print("\nstack dfs: ")
    dfs_s(tree, 1)

    # recursive와 stack의 순회 순서가 약간 상이하지만
    # 두 방식 모두 맞는 순회이다.
    """
        recursive dfs: 
        1
        2
        5
        6
        7
        3
        4

        stack dfs:
        1 4 3 2 5 7 6
    """



    # 그래프라면,,
    ## case 1
    ##        1 - 2
    ##      / |   |
    ##     3  |   |
    ##   / \  |   |
    ##  4 - 5 |   7
    ##        |  / \
    ##         8    6
    graph1 = [
        [],
        [2, 3, 8],  #1
        [1, 7],     #2
        [1, 4, 5],  #3
        [3, 5],     #4
        [3, 4],     #5
        [7],        #6
        [2, 6, 8],  #7
        [1, 7]      #8
    ]
    print("### iterate graph1 ###")
    visited2 = [False] * 10
    print("recursive dfs: ")
    dfs_r(graph1, visited2, 1)

    print("\nstack dfs: ")
    dfs_s(graph1, 1)

    ## case 2
    ##       1
    ##     / | \
    ##    2  3   4
    ##    | /| 
    ##    5  |
    ##   / \ |
    ##  6   7
        ## map<int, list<int>> graph = {
        ##     {0, {}},
        ##     {1, {2, 3, 4}},
        ##     {2, {5}},
        ##     {3, {5}},
        ##     {4, {}},
        ##     {5, {6, 7}},
        ##     {6, {}},
        ##     {7, {3}},
        ## };
    graph2 = [
        [],
        [2, 3, 4],  #1
        [1, 5],     #2
        [1, 5],     #3
        [1],        #4
        [2, 3, 6, 7],#5
        [5],        #6
        [5],        #7
    ]
    print("### iterate graph2 ###")
    visited2 = [False] * 10
    print("recursive dfs: ")
    dfs_r(graph2, visited2, 1)

    print("\nstack dfs: ")
    dfs_s(graph2, 1)
    """
        # 연결된 그래프도 순회가 가능하다.
        ## case 1
        ##        1 - 2
        ##      / |   |
        ##     3  |   |
        ##   / \  |   |
        ##  4 - 5 |   7
        ##        |  / \
        ##         8    6
        ## map<int, list<int>> graph = {
        ##     {0, {}},
        ##     {1, {2, 3, 8}},
        ##     {2, {1, 7}},
        ##     {3, {1, 4, 5}},
        ##     {4, {3, 5}},
        ##     {5, {3, 4}},
        ##     {6, {7}},
        ##     {7, {2, 6, 8}},
        ##     {8, {1, 7}},
        ## };

        ## case 2
        ##       1
        ##     / | \
        ##    2  3   4
        ##    | /| 
        ##    5  |
        ##   / \ |
        ##  6   7
        ## map<int, list<int>> graph = {
        ##     {0, {}},
        ##     {1, {2, 3, 4}},
        ##     {2, {5}},
        ##     {3, {5}},
        ##     {4, {}},
        ##     {5, {6, 7}},
        ##     {6, {}},
        ##     {7, {3}},
        ## };
    """