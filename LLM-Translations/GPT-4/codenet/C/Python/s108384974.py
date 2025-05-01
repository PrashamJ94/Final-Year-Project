
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

root = None
NIL = None

def find(x, k):
    while x != NIL and k != x.key:
        if k < x.key:
            x = x.left
        else:
            x = x.right
    return x

def insert(k):
    global root
    y = NIL
    x = root

    z = Node(k)
    z.left = NIL
    z.right = NIL

    while x != NIL:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right
    z.parent = y

    if y == NIL:
        root = z
    elif z.key < y.key:
        y.left = z
    else:
        y.right = z

def inorder(u):
    if u == NIL:
        return
    inorder(u.left)
    print(" %d" % u.key, end="")
    inorder(u.right)

def preorder(u):
    if u == NIL:
        return
    print(" %d" % u.key, end="")
    preorder(u.left)
    preorder(u.right)

def print_tree():
    inorder(root)
    print()
    preorder(root)
    print()

def main():
    n = int(input())
    
    for i in range(n):
        command = input().split()
        
        if command[0] == 'f':
            x = int(command[1])
            node = find(root, x)
            if node == NIL:
                print("no")
            else:
                print("yes")
        elif command[0] == 'i':
            z = int(command[1])
            insert(z)
        else:
            print_tree()

if __name__ == "__main__":
    main()

#
