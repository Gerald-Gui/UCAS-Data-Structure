class TreeNode:
    def __init__(self, val = "", left = None, right = None):
        self.data  = val
        self.left  = left
        self.right = right

def OpHigher(op1, op2):
    return (op1 == '*' or op1 == '/') and (op2 == '+' or op2 == '-')

def SubLowOp(op1, op2):
    return (op1 == '-') and (op2 == '+' or op2 == '-')

i = 0
def CreateTree(tnode, str):
    global i
    c = str[i]
    i += 1
    if c == '#':
        return None
    else:
        tnode = TreeNode(c)
        tnode.left  = CreateTree(tnode.left, str)
        tnode.right = CreateTree(tnode.right, str)
        return tnode

def InOrder(tnode):
    if tnode is None:
        return
    flg = False

    if tnode.left is not None:
        flg = OpHigher(tnode.data, tnode.left.data)
    else:
        flg = False    
    if flg:
        print("(", end="")
        InOrder(tnode.left)
        print(")", end="")
    else:
        InOrder(tnode.left)
    print(tnode.data, end="")

    if tnode.right is not None:
        flg = OpHigher(tnode.data, tnode.right.data) or SubLowOp(tnode.data, tnode.right.data)
    else:
        flg = False
    if flg:
        print("(", end="")
        InOrder(tnode.right)
        print(")", end="")
    else:
        InOrder(tnode.right)

tree = None
line = input()
tree = CreateTree(tree, line)
InOrder(tree)
print()
