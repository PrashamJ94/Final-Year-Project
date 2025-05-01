
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
            return

        currentNode = self.root
        prevNode = None
        while currentNode is not None:
            prevNode = currentNode
            if currentNode.key < key:
                currentNode = currentNode.right
            else:
                currentNode = currentNode.left

        newNode = Node(key)
        newNode.parent = prevNode
        if prevNode.key < key:
            prevNode.right = newNode
        else:
            prevNode.left = newNode

    def print_tree(self):
        acc = []
        if self.root is None:
            print("")
            print("")
        else:
            print(" " + " ".join([str(x) for x in visit_inorder(self.root, acc)]))
            print(" " + " ".join([str(x) for x in visit_preorder(self.root, acc)]))

def visit_preorder(node, acc):
    if node is None:
        return acc
    acc.append(node.key)
    if node.left is not None:
        acc = visit_preorder(node.left, acc)
    if node.right is not None:
        acc = visit_preorder(node.right, acc)
    return acc

def visit_inorder(node, acc):
    if node is None:
        return acc
    if node.left is not None:
        acc = visit_inorder(node.left, acc)
    acc.append(node.key)
    if node.right is not None:
        acc = visit_inorder(node.right, acc)
    return acc

def main():
    n = int(input())
    tree = Tree()

    for _ in range(n):
        command = input().split()
        if command[0] == "insert":
            key = int(command[1])
            tree.insert(key)
        elif command[0] == "print":
            tree.print_tree()
        else:
            raise ValueError("unknown command: " + command[0])

if __name__ == "__main__":
    main()


