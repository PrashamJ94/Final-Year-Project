
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

def makenode(a):
    return Node(a)

def insert(head, a):
    x = makenode(a)
    x.next = head.next
    head.next.prev = x
    head.next = x
    x.prev = head

def delete(head, a):
    x = head
    while x.next != head:
        x = x.next
        if x.key == a:
            x.prev.next = x.next
            x.next.prev = x.prev
            del x
            break

def deleteFirst(head):
    x = head.next
    head.next = x.next
    x.next.prev = head
    del x

def deleteLast(head):
    x = head.prev
    head.prev = x.prev
    x.prev.next = head
    del x

def main():
    head = Node(0)
    head.next = head
    head.prev = head

    n = int(input())
    for _ in range(n):
        op = input().split()
        if op[0] == "insert":
            a = int(op[1])
            insert(head, a)
        elif op[0] == "delete":
            a = int(op[1])
            delete(head, a)
        elif op[0] == "deleteFirst":
            deleteFirst(head)
        elif op[0] == "deleteLast":
            deleteLast(head)

    x = head
    while x.next != head:
        print(x.next.key, end=" ")
        x = x.next
    print()

if __name__ == "__main__":
    main()


