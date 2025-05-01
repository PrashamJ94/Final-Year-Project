def preorder(x, R):
    if x == -1:
        return
    print(" {}".format(x), end="")
    preorder(R[x]['left'], R)
    preorder(R[x]['right'], R)

def inorder(x, R):
    if x == -1:
        return
    inorder(R[x]['left'], R)
    print(" {}".format(x), end="")
    inorder(R[x]['right'], R)

def postorder(x, R):
    if x == -1:
        return
    postorder(R[x]['left'], R)
    postorder(R[x]['right'], R)
    print(" {}".format(x), end="")

def main():
    n = int(input())
    R = [{} for _ in range(10000)]

    for i in range(n):
        a, b, c = map(int, input().split())
        R[a]['left'] = b
        R[a]['right'] = c
        if b != -1:
            R[b]['parent'] = a
        if c != -1:
            R[c]['parent'] = a

    root = -1
    for i in range(n):
        if 'parent' not in R[i]:
            root = i
            break

    print("Preorder")
    preorder(root, R)
    print("\nInorder")
    inorder(root, R)
    print("\nPostorder")
    postorder(root, R)
    print()

if __name__ == "__main__":
    main()


