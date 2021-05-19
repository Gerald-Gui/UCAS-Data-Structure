def InsertVex(rows, v):
    for row in rows:
        row.insert(v, 0)
    list = []
    for i in range(len(rows) + 1):
        list.append(0)
    rows.insert(v, list)

def InsertArc(rows, v, w):
    rows[v][w] = rows[w][v] = 1

def DeleteVex(rows, v):
    for i in range(len(rows)):
        del rows[i][v]
    del rows[v]

def DeleteArc(rows, v, w):
    rows[v][w] = rows[w][v] = 0

rows = []
r = int(input())
for i in range(r):
    line = list(map(int, input().split()))
    rows.append(line[:])
try:
    while True:
        oplist = input().split()
        if oplist[0] == "IV":
            InsertVex(rows, int(oplist[1]))
        elif oplist[0] == "IA":
            InsertArc(rows, int(oplist[1]), int(oplist[2]))
        elif oplist[0] == "DV":
            DeleteVex(rows, int(oplist[1]))
        else:
            DeleteArc(rows, int(oplist[1]), int(oplist[2]))
except EOFError:
    pass
for line in rows:
    for i in range(len(line)):
        if i == len(line) - 1:
            print(line[i])
        else:
            print(line[i], end=" ")
