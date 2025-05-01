
class Node:
    def __init__(self, key=None):
        self.key = key
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.nil = Node()
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def list_search(self, key):
        cur = self.nil.next
        while cur != self.nil and cur.key != key:
            cur = cur.next
        return cur

    def print_list(self):
        cur = self.nil.next
        is_first = True
        while cur != self.nil:
            if not is_first:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            is_first = False
        print()

    def delete_node(self, t):
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def delete_first(self):
        t = self.nil.next
        if t == self.nil:
            return
        self.delete_node(t)

    def delete_last(self):
        t = self.nil.prev
        if t == self.nil:
            return
        self.delete_node(t)

    def delete(self, key):
        t = self.list_search(key)
        if t == self.nil:
            return
        self.delete_node(t)

    def insert(self, key):
        x = Node(key)
        x.next = self.nil.next
        self.nil.next.prev = x
        self.nil.next = x
        x.prev = self.nil


def main():
    n = int(input())
    dll = DoublyLinkedList()

    for _ in range(n):
        command, *args = input().split()
        key = int(args[0]) if args else None

        if command == 'insert':
            dll.insert(key)
        elif command == 'delete':
            dll.delete(key)
        elif command == 'deleteFirst':
            dll.delete_first()
        elif command == 'deleteLast':
            dll.delete_last()

    dll.print_list()


if __name__ == '__main__':
    main()

#
