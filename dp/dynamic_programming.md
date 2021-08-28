## Dynamic programming
Dynamic programming은 작은 범위의 문제를 해결해서 큰 범위의 문제를 해결할 때 쓰는 방법이다.  
그 예로 피보나치 구현 방법들을 살펴보자.  
  
## recursive
재귀함수로 구현할 수 있다.  
하지만, 한번 계산한 값들을 중복해서 계산하기 때문에 성능상의 소모가 크다.  
그래서 한번 계산한 값들을 메모리에 저장해서 소모를 줄일 수 있는데,  
이런 방법을 메모이제이션이라고 한다.  
우선 재귀를 이용한 기본적인 구현부터 보자.  
~~~C++
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
~~~  
  
## memoization(top-down)
위에서 설명한 것처럼 이전에 계산한 값들을 재사용함으로서  
시간복잡도를 줄일 수 있다.  
~~~C++
int fib(int n, int memo[]) {
    if (memo[n] != 0) return memo[n];//기록해둔 것이 있으면 사용.
    memo[n] = (n==1 || n==2) ? 1: fibo(n-1, memo), fibo(n-2, memo);
    return memo[n];
}
~~~
  
## tabulation(bottom-up)
recursion을 사용하지 않는다.  
재귀의 경우, 하향식을 사용하는데, bottom-up은 상향식을 사용할 수 있다.  
(작은 것부터 순차적으로 풀어나간다)  
~~~C++
int fibo(int n) {
    int bottomUp[n+1];
    bottomUp[1] = 1;
    bottomUp[2] = 1;
    for (int i = 3; i <= n; i++) bottomUp[i] = bottomUp[i-1] + bottomUp[i-2];
    return bottomUp[n];
}
~~~  
  
## 참고 자료
https://yaboong.github.io/algorithms/2018/02/05/dynamic-programming-1/  
https://www.geeksforgeeks.org/tabulation-vs-memoization/  
  