
from typing import Optional

class Node:
    def __init__(self, key: int, priority: int):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

def find(node: Optional[Node], x: int) -> bool:
    while node:
        if node.key == x:
            return True
        elif node.key > x:
            node = node.left
        else:
            node = node.right
    return False

def inorder(node: Optional[Node]):
    if node:
        inorder(node.left)
        print(node.key, end=" ")
        inorder(node.right)

def preorder(node: Optional[Node]):
    if node:
        print(node.key, end=" ")
        preorder(node.left)
        preorder(node.right)

def print_tree(node: Optional[Node]):
    inorder(node)
    print()
    preorder(node)
    print()

def make_node(x: int, y: int) -> Node:
    return Node(x, y)

def right_rotate(node: Node) -> Node:
    q = node.left
    node.left = q.right
    q.right = node
    return q

def left_rotate(node: Node) -> Node:
    q = node.right
    node.right = q.left
    q.left = node
    return q

def insert(node: Optional[Node], key: int, priority: int) -> Node:
    if not node:
        return make_node(key, priority)
    if node.key == key:
        return node

    if key < node.key:
        node.left = insert(node.left, key, priority)
        if node.priority < node.left.priority:
            node = right_rotate(node)
    else:
        node.right = insert(node.right, key, priority)
        if node.priority < node.right.priority:
            node = left_rotate(node)
    return node

def delete_node(node: Optional[Node], key: int) -> Optional[Node]:
    if not node:
        return None

    if key < node.key:
        node.left = delete_node(node.left, key)
    elif key > node.key:
        node.right = delete_node(node.right, key)
    else:
        if not node.left and not node.right:
            return None
        elif not node.left:
            node = left_rotate(node)
        elif not node.right:
            node = right_rotate(node)
        else:
            if node.left.priority > node.right.priority:
                node = right_rotate(node)
            else:
                node = left_rotate(node)
        node = delete_node(node, key)
    return node

def main():
    num = int(input())
    root = None

    for _ in range(num):
        command = input().split()
        if command[0] == 'i':
            x, y = int(command[1]), int(command[2])
            root = insert(root, x, y)
        elif command[0] == 'd':
            x = int(command[1])
            root = delete_node(root, x)
        elif command[0] == 'f':
            x = int(command[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif command[0] == 'p':
            print_tree(root)

if __name__ == "__main__":
    main()


