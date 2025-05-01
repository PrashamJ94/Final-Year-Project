
class Node:
    def __init__(self, key=None, next=None, prev=None):
        self.key = key
        self.next = next
        self.prev = prev

class DoublyLinkedList:
    def __init__(self):
        self.N = Node()
        self.N.next = self.N
        self.N.prev = self.N

    def print_list(self):
        cur = self.N.next
        snl = 1
        while cur != self.N:
            if snl == 0:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            snl = 0
        print()

    def delete_first(self):
        t = self.N.next
        self.N.next = t.next
        t.next.prev = self.N

    def delete_last(self):
        delnode = self.N.prev
        self.N.prev = delnode.prev
        delnode.prev.next = self.N

    def delete(self, skey):
        judge = 0
        for n in self.iter_nodes():
            if n.key == skey:
                judge = 1

        if judge == 1:
            n = self.N.next
            while n != self.N:
                if n.key == skey:
                    break
                n = n.next
            t = n.prev
            t.next = n.next
            t.next.prev = t

    def insert(self, skey):
        new = Node(skey)
        new.next = self.N.next
        self.N.next.prev = new
        self.N.next = new
        new.prev = self.N

    def iter_nodes(self):
        cur = self.N.next
        while cur != self.N:
            yield cur
            cur = cur.next

def main():
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        command = input().split()
        if command[0] == "insert":
            dll.insert(int(command[1]))
        elif command[0] == "deleteFirst":
            dll.delete_first()
        elif command[0] == "deleteLast":
            dll.delete_last()
        else:
            dll.delete(int(command[1]))
    dll.print_list()

if __name__ == "__main__":
    main()


