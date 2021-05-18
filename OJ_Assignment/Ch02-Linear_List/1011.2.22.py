class ListNode:
    def __init__(self, data, next = None):
        self.val = data
        self.nxt = next
class LinkList:
    def __init__(self, headval):
        self.head = ListNode(headval)
    def reverse(self):
        p = self.head.nxt
        self.head.nxt = None
        while p is not None:
            q = p
            p = p.nxt
            q.nxt = self.head.nxt
            self.head.nxt = q
    def print(self):
        p = self.head.nxt
        while p is not None:
            if p.nxt is None:
                print(p.val)
            else:
                print(p.val, end=",")
            p = p.nxt

dataList = input().split(",")
L = LinkList("")
p = L.head
for i in dataList:
    p.nxt = ListNode(i)
    p = p.nxt
L.reverse()
L.print()
