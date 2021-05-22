visited = [False]
visited_tmp = [False]
def cycle(i, s = [], fst = [], lst = []):
    global visited
    global visited_tmp
    visited[i] = True
    if visited_tmp[i]:
        return True
    visited_tmp[i] = True
    j = fst[i]
    while j < lst[i]:
        if cycle(s[j], s, fst, lst):
            return True
        j += 1
    visited_tmp[i] = False
    return False

amt = int(input())
s = list(map(int, input().split()))
fst = list(map(int, input().split()))
lst = list(map(int, input().split()))
for i in range(len(fst)):
    visited.append(False)
    visited_tmp.append(False)
flg = False
for i in range(1, amt + 1):
    if not visited[i] and cycle(i, s, fst, lst):
        flg = True
        break
if flg:
    print("yes")
else:
    print("no")
