import sys
import heapq

# input = sys.stdin.readline
INF = int(1e9) #무한을 의미

# 노드의 개수, 간선의 개수를 입력받기
n, m = map(int, input('[input] num of node, edge: ').split())
print("n: {0}, m: {1}".format(n, m))

start = int(input("start node number: "))
graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):#간선입력 받기
    a, b, c = map(int, input("graph row{0} input(node_n, cost): ".format(_)).split())
    graph[a].append((b, c))#(b, c): b번 노드, c만큼의 비용(거리)가 소요.

def dijkstra(start):
    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:# 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 skip.
        if (distance[now] < dist):
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:# graph는 (노드, 비용)이므로 
            cost = dist + i[1]# 현재 거리에 가장 가까운 노드의 비용을 더한다.
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우,
            if cost < distance[i[0]]:#현재 계산한 거리가 이전에 계산한 값보다 비용이 적을 경우,
                distance[i[0]] = cost#계산한 값으로 대체
                #heapq는 첫번째 원소를 기준으로 minq방식으로 정렬하므로
                # cost를 먼저, 노드 번호를 다음으로 하는 튜플을 넣는다.
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

print("===== print shortest path =====")
# 모든 노드로 가기 위한 최단 거리를 출력
for i in range(1, n+1):
    # 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])

