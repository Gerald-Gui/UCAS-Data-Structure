class stack:
    def __init__(self):
        self.base = []
    def push(self, data):
        self.base.append(data)
    def pop(self):
        return self.base.pop()
    def top(self):
        return self.base[len(self.base) - 1]
    def empty(self):
        return len(self.base) == 0

def PreOrderPrint(root, value = [], left = [], right = []):
    stk = stack()
    p = root
    while p != -1 or not stk.empty():
        if p != -1:
            print(value[p], end=" ")
            stk.push(p)
            p = left[p]
        else:
            p = stk.pop()
            p = right[p]
    print()

value = [0]
left = [0]
right = [0]
try:
    while True:
        line = input()
        inputList = line.split()
        value.append(inputList[0])
        left.append(int(inputList[1]))
        right.append(int(inputList[2]))
except EOFError:
    pass
PreOrderPrint(1, value, left, right)
