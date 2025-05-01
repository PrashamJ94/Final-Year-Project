
class Node:
    def __init__(self, key):
        self.parent = None
        self.left = None
        self.right = None
        self.key = key


def insert(root, key):
    insert_node = Node(key)
    parent_node = None
    index_node = root

    while index_node is not None:
        parent_node = index_node
        if insert_node.key < index_node.key:
            index_node = index_node.left
        else:
            index_node = index_node.right

    insert_node.parent = parent_node

    if parent_node is None:
        root = insert_node
    elif key < parent_node.key:
        parent_node.left = insert_node
    else:
        parent_node.right = insert_node

    return root


def print_pre_order(node):
    if node is None:
        return

    print(f" {node.key}", end="")
    print_pre_order(node.left)
    print_pre_order(node.right)


def print_in_order(node):
    if node is None:
        return

    print_in_order(node.left)
    print(f" {node.key}", end="")
    print_in_order(node.right)


def main():
    root = None
    num_commands = int(input())

    for _ in range(num_commands):
        command = input().split()

        if command[0] == "insert":
            key = int(command[1])
            root = insert(root, key)
        elif command[0] == "print":
            print_in_order(root)
            print()
            print_pre_order(root)
            print()

if __name__ == "__main__":
    main()


