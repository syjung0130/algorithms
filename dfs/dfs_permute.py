#-*-coding:utf-8-*-
def permute(nums, k):
    results = []
    prev_elements = []
    n = len(nums)

    def dfs(elements, k):
        # 리프 노드일 때 결과 추가
        if len(elements) == n-k:
            results.append(prev_elements[:])
            print(prev_elements)
            return
        
        # 순열 생성 재귀 호출
        for e in elements:
            next_elements = elements[:]
            next_elements.remove(e)

            prev_elements.append(e)
            dfs(next_elements, k)
            prev_elements.pop()
    dfs(nums, k)
    return results

if __name__ == "__main__":
    l1 = [1, 2, 3]
    permute(l1, 2)