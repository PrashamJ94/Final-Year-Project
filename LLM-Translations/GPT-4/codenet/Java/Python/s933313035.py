
class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def insert(self, new_value):
        if new_value < self.value:
            if self.left is None:
                self.left = Node(new_value)
            else:
                self.left.insert(new_value)
        else:
            if self.right is None:
                self.right = Node(new_value)
            else:
                self.right.insert(new_value)

    def print_inorder(self):
        if self.left:
            self.left.print_inorder()
        print(" ", self.value, end="")
        if self.right:
            self.right.print_inorder()

    def print_preorder(self):
        print(" ", self.value, end="")
        if self.left:
            self.left.print_preorder()
        if self.right:
            self.right.print_preorder()


def main():
    m = int(input())

    tree = None
    for _ in range(m):
        command = input().split()

        if command[0] == "insert":
            key = int(command[1])
            if tree is None:
                tree = Node(key)
            else:
                tree.insert(key)
        else:
            if tree:
                tree.print_inorder()
                print()
                tree.print_preorder()
                print()


if __name__ == "__main__":
    main()



