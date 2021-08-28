
## 깊이 우선 탐색 (Depth First Search)
시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 탐색해 가다가 더 이상 갈 곳이 없게 되면,  
가장 마지막에 만났던 갈림길 간선이 있는 정점으로 되돌아와서  
다른 방향의 간선으로 탐색을 계속 반복하여  
결국 모든 정점을 방문하는 순회방법.
가장 마지막에 만났던 갈림길 간선의 정점으로 가장 먼저 되돌아가서  
다시 깊이 우선 탐색을 반복해야 하므로 후입선출 구조의 스택 사용.  
  
  
## 깊이 우선 탐색의 수행 순서
 - (1)시작 정점 v를 결정하여 방문한다.  
 - (2)정점 v에 인접한 정점 중에서  
   - (a)방문하지 않은 정점 w가 있으면, 정점 v를 스택에 push하고 정점 w를 방문한다.  
    그리고 w를 v로 하여 다시 (2)를 반복한다.
   - (b)방문하지 않은 정점이 없으면, 탐색의 방향을 바꾸기 위해서  
    스택을 pop하여 받은 가장 마지막 방문 정점을 v로 하여 다시 (2)를 반복한다.
 - (3)스택이 공백이 될 때까지 (2)를 반복한다.
~~~
DFS(v)
	for (i <- 0; i < n; i <-i+1) do {
		visited[i] <- false;
	}
	stack <- createStack();
	visited[v] <- true;
	v 방문;
	
	while(not isEmpty(stack)) do {
		if (visited[v의 인접 정점 w]=false) then {
            push(stack, v);
            visited[w] <- true;
            w 방문;
            v <- w;
        }
        else 
            v <- pop(stack);
	}
end DFS()
~~~
출처: https://itdexter.tistory.com/86 [IT_Dexter]
