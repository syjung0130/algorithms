#-*-coding:utf-8-*-
def combination(n: int, k: int):
    results = []
    def dfs(elements, start: int, k: int):
        if k == 0:
            results.append(elements[:])
            return
        # 자신 이전의 모든 값을 고정하여 재귀 호출
        for i in range(start, n+1):
            elements.append(i)
            dfs(elements, i+1, k-1)
            elements.pop()
    dfs([], 1, k)
    return results


def combination_list(nums:list, k:int):
    results = []
    print("combination_list()")

    def dfs(elements, start:int, k:int):
        if k == 0:
            results.append(elements[:])
            return
        # elif k < 0:
        #     return
        
        for i in range(start, len(nums)):
            elements.append(nums[i])
            dfs(elements, i+1, k-1)
            elements.pop()
    
    dfs([], 0, k)
    return results

def comb_l2(nums:list[int], k:list):
    results = []

    def dfs(elements, start:int, k:int):
        if k == 0:
            results.append(elements[:])
            return
        
        for i in range(start, len(nums)):
            elements.append(nums[i])
            dfs(elements, i+1, k-1)
            elements.pop()
        

if __name__ == "__main__":
    reusult = combination(4, 2)
    print(reusult)
    nums = [1, 2, 3, 4]
    result_list = combination_list(nums, 2)
    print(result_list)