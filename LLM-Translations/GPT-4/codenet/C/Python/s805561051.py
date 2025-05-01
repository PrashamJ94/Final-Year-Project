
class BT:
    def __init__(self):
        self.parent = -1
        self.right = -1
        self.left = -1

def preorder(bt, a):
    if a == -1:
        return

    print(a, end=" ")
    preorder(bt, bt[a].left)
    preorder(bt, bt[a].right)

def inorder(bt, a):
    if a == -1:
        return

    inorder(bt, bt[a].left)
    print(a, end=" ")
    inorder(bt, bt[a].right)

def postorder(bt, a):
    if a == -1:
        return

    postorder(bt, bt[a].left)
    postorder(bt, bt[a].right)
    print(a, end=" ")

def main():
    n = int(input())
    bt = [BT() for _ in range(26)]

    for i in range(n):
        num, left, right = map(int, input().split())
        bt[num].left = left
        bt[num].right = right

        if left != -1:
            bt[left].parent = num
        if right != -1:
            bt[right].parent = num

    i = 0
    while bt[i].parent != -1:
        i += 1

    print("Preorder")
    preorder(bt, i)
    print()

    print("Inorder")
    inorder(bt, i)
    print()

    print("Postorder")
    postorder(bt, i)
    print()

if __name__ == "__main__":
    main()


#
