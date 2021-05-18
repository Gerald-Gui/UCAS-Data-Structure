a, b, c = map(int, input().split())
if a < b:
    a, b = b, a
if c > a:
    a, b, c = c, a, b
elif c <= a and c >= b:
    a, b, c = a, c, b
print(a, end=" ")
print(b, end=" ")
print(c)