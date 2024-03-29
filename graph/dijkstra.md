# dijkstra algorithm
다익스트라(테이크스트라)알고리즘은 그래프에서 여러 개의 노드가 있을 때,  
특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘이다.  
다익스트라 최단 경로 알고리즘은 기본적으로 그리디 알고리즘으로 분류된다.  
(동적계획법인것같은데,, 일단 다른 책을 찾아보고 설명을 보충하기로 하고..)  
  
## 알고리즘의 동작과정  
 1. 출발 노드를 설정한다.
 2. 최단 거리 테이블을 초기화한다.
 3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택한다.
 4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산해서 최단 거리 테이블을 갱신한다.
 5. 위 과정에서 3번과 4번을 반복한다.

## 다익스트라 알고리즘 특징.
 - 다익스트라 알고리즘은 최단 경로를 구하는 과정에서  
'각 노드에 대한 현재까지의 최단 거리' 정보를 항상 1차원 리스트에 저장하며  
리스트를 계속 갱신한다는 특징이 있다.  
 - 매번 현재 처리하고 있는 노드를 기준으로 주변 간선을 확인한다.  
 나중에 현재 처리하고 있는 노드와 인접한 노드로 도달하는  
 더 짧은 경로를 찾으면 '더 짧은 경로도 있었네? 이제부터는 이 경로가 제일 짧은 경로야'라고  
 판단한다.  
 - '방문하지 않은 노드 중에서 현재 최단 거리가 가장 짧은 노드를 확인'해 그 노드에 대해  
 4번의 과정을 수행한다는 점에서 그리디 알고리즘으로 볼 수 있다.    
