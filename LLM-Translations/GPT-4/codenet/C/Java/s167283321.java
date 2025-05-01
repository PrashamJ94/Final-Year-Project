
class Node {
    int parent, left, right;

    Node(int parent, int left, int right) {
        this.parent = parent;
        this.left = left;
        this.right = right;
    }
}

public class s167283321 {
    static final int NIL = -1;
    static Node[] R;
    static int n;

    static void preorder(int x) {
        if (x == NIL)
            return;
        System.out.print(" " + x);
        preorder(R[x].left);
        preorder(R[x].right);
    }

    static void inorder(int x) {
        if (x == NIL)
            return;
        inorder(R[x].left);
        System.out.print(" " + x);
        inorder(R[x].right);
    }

    static void postorder(int x) {
        if (x == NIL)
            return;
        postorder(R[x].left);
        postorder(R[x].right);
        System.out.print(" " + x);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int i, a, b, c, root = 0;
        n = scanner.nextInt();
        R = new Node[n];
        for (i = 0; i < n; i++)
            R[i] = new Node(NIL, NIL, NIL);
        for (i = 0; i < n; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            R[a] = new Node(a, b, c);
            if (b != NIL) R[b].parent = a;
            if (c != NIL) R[c].parent = a;
        }
        for (i = 0; i < n; i++) {
            if (R[i].parent == NIL)
                root = i;
        }
        System.out.println("Preorder");
        preorder(root);
        System.out.println("\nInorder");
        inorder(root);
        System.out.println("\nPostorder");
        postorder(root);
        System.out.println();
    }
}

// 
