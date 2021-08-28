#-*-coding=utf-8-*-

def merge_to_area(arr, left, mid, right):
    l = left
    r = mid+1
    pivot = arr[left]
    cur = left

    tmp = [0 for i in range(right+1)]

    while l <= mid and r <= right:
        if arr[l] < arr[r]:
            tmp[cur] = arr[l]
            l += 1
        else:
            tmp[cur] = arr[r]
            r += 1
        cur += 1
    
    if l > mid:#좌측이 남아있는 상태일 경우, 
        for i in range(r, right+1, 1):
            tmp[cur] = arr[i]
            cur += 1
    else:#우측이 남아있는 상태일 경우,
        for i in range(l, mid+1, 1):
            tmp[cur] = arr[i]
            cur += 1
    
    for i in range(left, right+1, 1):
        arr[i] = tmp[i]

def merge_sort(arr, left, right):
    if left >= right:
        return
    
    mid = (left + right) // 2
    merge_sort(arr, left, mid)
    merge_sort(arr, mid+1, right)

    merge_to_area(arr, left, mid, right)

if __name__ == '__main__':
    lst = [6, 5, 3, 1, 8, 7, 2, 4]

    merge_sort(lst, 0, len(lst)-1)

    print(lst)