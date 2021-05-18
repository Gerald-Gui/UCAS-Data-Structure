class ListNode:
    def __init__(self, data = None):
        self.val = data
        self.nxt = None

class LinkList:
    def __init__(self):
        self.head = None
    
    def print(self):
        p = self.head
        if p is None:
            print("NULL")
        else:
            while p is not None:
                if p.nxt is not None:
                    print(p.val, end=" ")
                else:
                    print(p.val)
                p = p.nxt
    
    def delete(self, index):
        p = self.head
        if index == 0:
            self.head = self.head.nxt
            del p
        else:
            cnt = 1
            while cnt < index:
                p = p.nxt
                cnt += 1
            q = p.nxt
            p.nxt = q.nxt
            del q
    
L = LinkList()
data = list(map(int, input().split()))
p = L.head = ListNode(data[0])
for i in range(1, len(data)):
    p.nxt = ListNode(data[i])
    p = p.nxt
tar = int(input())
L.delete(tar)
L.print()
