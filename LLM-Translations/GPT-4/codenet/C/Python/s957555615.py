
class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.parent = None
        self.key = key


root = None
NIL = None


def tree_minimum(x):
    while x.left is not NIL:
        x = x.left
    return x


def tree_maximum(x):
    while x.right is not NIL:
        x = x.right
    return x


def tree_search(u, k):
    if u == NIL or k == u.key:
        return u

    if k < u.key:
        return tree_search(u.left, k)
    else:
        return tree_search(u.right, k)


def tree_successor(x):
    if x.right is not NIL:
        return tree_minimum(x.right)

    y = x.parent
    while y is not NIL and x == y.right:
        x = y
        y = y.parent
    return y


def tree_delete(z):
    if z.left == NIL or z.right == NIL:
        y = z
    else:
        y = tree_successor(z)

    if y.left != NIL:
        x = y.left
    else:
        x = y.right

    if x != NIL:
        x.parent = y.parent

    if y.parent == NIL:
        global root
        root = x
    elif y == y.parent.left:
        y.parent.left = x
    else:
        y.parent.right = x

    if y != z:
        z.key = y.key


def insert(k):
    global root
    y = NIL
    x = root
    z = Node(k)

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


def main():
    n = int(input())
    for _ in range(n):
        com = input().split()
        if com[0] == 'f':
            x = int(com[1])
            t = tree_search(root, x)
            if t != NIL:
                print("yes")
            else:
                print("no")
        elif com[0] == 'i':
            x = int(com[1])
            insert(x)
        elif com[0] == 'p':
            inorder(root)
            print()
            preorder(root)
            print()
        elif com[0] == 'd':
            x = int(com[1])
            tree_delete(tree_search(root, x))


if __name__ == "__main__":
    main()

#
