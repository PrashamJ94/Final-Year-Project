
class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def r_print(self):
        result = []
        current = self
        while current is not None:
            result.append(str(current.key))
            current = current.next
        return " ".join(result)

    def delete(self, first, last):
        if self.prev is not None and self.next is not None:
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last

        if self.next is None and self.prev is None:
            return None, None

        if self.prev is None:
            first = self.next
            self.next.prev = None

        if self.next is None:
            last = self.prev
            self.prev.next = None

        return first, last

def main():
    n = int(input())
    first, last = None, None

    for _ in range(n):
        cmd = input().split()
        if cmd[0] == "deleteFirst":
            first, last = first.delete(first, last)
        elif cmd[0] == "deleteLast":
            first, last = last.delete(first, last)
        else:
            k = int(cmd[1])
            if cmd[0] == "delete":
                current = first
                while current is not None:
                    if current.key == k:
                        first, last = current.delete(first, last)
                        break
                    current = current.next
            elif cmd[0] == "insert":
                new_node = Node(k)
                new_node.next = first
                if first is not None:
                    first.prev = new_node
                first = new_node
                if last is None:
                    last = new_node

    print(first.r_print())

if __name__ == "__main__":
    main()



