# -*- coding=utf-8 -*-

def mergeToArea(arr, left, mid, right):
    #left ~ mid, mid+1 ~ right까지 정렬이 되어있다고 가정
    l = left
    r = mid+1

    cur = l
    # print("l: {0}, r: {1}, mid: {2}, right: {3}, cur: {4}".format(l, r, mid, right, cur))
    tmp = [0 for i in range(right+1)]

    while l <= mid and r <= right:
        if arr[l] < arr[r]:
            tmp[cur] = arr[l]
            l+=1
        else:#elif arr[r] <= arr[l]:
            tmp[cur] = arr[r]
            r+=1
        cur+=1
    
    if l > mid:#left가 먼저 다 비워졌을 경우,
        for i in range(r, right+1, 1):
            tmp[cur] = arr[i]
            cur+=1
    else:
        for i in range(l, mid+1, 1):
            tmp[cur] = arr[i]
            cur+=1
    
    for i in range(left, right+1, 1):
        arr[i] = tmp[i]


def mergeSort(arr, left, right):
    #left와 right이 같으면 더 이상 분할할 수 없다.
    if left >= right:
        return
    
    #mid
    mid = (left + right) // 2
    
    mergeSort(arr, left, mid)
    mergeSort(arr, mid+1, right)

    print(arr)
    mergeToArea(arr, left, mid, right)
    print(arr)
    

if __name__ == '__main__':
    lst = [6, 5, 3, 1, 8, 7, 2, 4]

    mergeSort(lst, 0, len(lst)-1)

    print(lst)