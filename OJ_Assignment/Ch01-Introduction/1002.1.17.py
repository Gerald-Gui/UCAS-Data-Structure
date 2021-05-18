def fibonacci(k, m):
    if m < k - 1:
        return 0
    if m == k - 1:
        return 1
    arr = []
    i = 0
    while i < k:
        if i == k - 1:
            arr.append(1)
        else:
            arr.append(0)
        i += 1
    cnt = 1
    while i <= m:
        arr.append(cnt)
        cnt = cnt - arr[i - k] + arr[i]
        i += 1
    return arr[m]

k, m = map(int, input().split())
print(fibonacci(k, m))
