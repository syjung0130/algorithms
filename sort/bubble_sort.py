
def bubble_sort():
    arr = [1, 5, 3, 2, 7]
    print("before sort: {0}".format(arr))

    for i in range(len(arr)-1):
        for j in range(len(arr)-1-i):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    
    print("after sort: {0}".format(arr))
    
def reverse_bubble_sort():
    arr = [1, 5, 3, 2, 7]

    # print(range(len(arr)-1, 0-1, -1))
    print("before reverse sort: {0}".format(arr))

    for i in range(len(arr)-1, 1, -1):
        for j in range(len(arr)-1, 1, -1):
            if arr[j-1] > arr[j]:
                print("**")
                temp = arr[j-1]
                arr[j-1] = arr[j]
                arr[j] = temp
    
    print("after reverse sort: {0}".format(arr))



bubble_sort()

reverse_bubble_sort()