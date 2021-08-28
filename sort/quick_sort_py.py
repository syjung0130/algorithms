def partition(arr, left, right):
    pivot = right
    l = left

    for r in range(left, right):
        if arr[r] < arr[pivot]:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
    
    # print("pivot:{0}, l:{1}".format(pivot, l))
    arr[pivot], arr[l] = arr[l], arr[pivot]
    
    return l

def quicksort(A, lo, hi):
    if lo < hi:
        pivot = partition(A, lo, hi)
        quicksort(A, lo, pivot-1)
        quicksort(A, pivot+1, hi)

A = [5, 1, 3, 7, 2]
quicksort(A, 0, 4)

print(A)
