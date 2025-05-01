
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def list_search(self, key):
        cur = self.nil.next
        while cur != self.nil:
            if cur.key == key:
                break
            cur = cur.next
        return cur

    def print_list(self):
        cur = self.nil.next
        is_first_element = True
        output = []
        while cur != self.nil:
            if not is_first_element:
                output.append(" ")
            output.append(str(cur.key))
            cur = cur.next
            is_first_element = False
        print("".join(output))

    def delete_node(self, t):
        if t == self.nil:
            return
        t.prev.next = t.next
        t.next.prev = t.prev

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

    def delete_key(self, key):
        t = self.list_search(key)
        if t != self.nil:
            self.delete_node(t)

    def insert(self, key):
        x = Node(key)
        x.prev = self.nil
        x.next = self.nil.next
        x.next.prev = x
        self.nil.next = x

def main():
    n = int(input())
    d_list = DoublyLinkedList()
    for _ in range(n):
        command, *params = input().split()
        if command == 'insert':
            key = int(params[0])
            d_list.insert(key)
        elif command == 'delete':
            key = int(params[0])
            d_list.delete_key(key)
        elif command == 'deleteFirst':
            d_list.delete_first()
        elif command == 'deleteLast':
            d_list.delete_last()
    d_list.print_list()

if __name__ == "__main__":
    main()


