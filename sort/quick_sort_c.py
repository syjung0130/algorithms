#-*-coding=utf-8-*-
def partition(arr, left, right):
    pivot = left
    l = left+1
    r = right

    while l <= r:
        while arr[l] < arr[pivot]:#pivot보다 큰 값을 만날 때까지
            l += 1
        while arr[r] > arr[pivot]:#pivot보다 작은 값을 만날 때까지
            r -= 1
        if l <= r:
            arr[l], arr[r] = arr[r], arr[l]
    
    arr[pivot], arr[r] = arr[r], arr[pivot]

    return r

def quicksort(arr, left, right):
    if left >= right:
        return
    
    pivot = partition(arr, left, right)
    quicksort(arr, left, pivot-1)
    quicksort(arr, pivot+1, right)


A = [5, 1, 3, 7, 2]
quicksort(A, 0, 4)

print(A)
