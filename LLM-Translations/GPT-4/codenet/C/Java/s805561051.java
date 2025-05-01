
import java.util.Scanner;

class BinaryTree {
    int parent, right, left;

    BinaryTree() {
        parent = -1;
    }
}

public class s805561051 {
    static BinaryTree[] bt = new BinaryTree[26];
    static int n;

    static void Preorder(int a) {
        if (a == -1) return;

        System.out.print(" " + a);
        Preorder(bt[a].left);
        Preorder(bt[a].right);
    }

    static void Inorder(int a) {
        if (a == -1) return;

        Inorder(bt[a].left);
        System.out.print(" " + a);
        Inorder(bt[a].right);
    }

    static void Postorder(int a) {
        if (a == -1) return;

        Postorder(bt[a].left);
        Postorder(bt[a].right);
        System.out.print(" " + a);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, j, num, depth = 0;

        n = scanner.nextInt();

        for (i = 0; i < n; ++i) bt[i] = new BinaryTree();

        for (i = 0; i < n; i++) {
            num = scanner.nextInt();
            bt[num].left = scanner.nextInt();
            bt[num].right = scanner.nextInt();

            if (bt[num].left != -1 && bt[num].right != -1) {
                bt[bt[num].left].parent = num;
                bt[bt[num].right].parent = num;
            } else if (bt[num].left != -1) bt[bt[num].left].parent = num;
            else if (bt[num].right != -1) bt[bt[num].right].parent = num;
        }

        for (i = 0; bt[i].parent != -1; ++i);

        System.out.println("Preorder");
        Preorder(i);
        System.out.println();

        System.out.println("Inorder");
        Inorder(i);
        System.out.println();

        System.out.println("Postorder");
        Postorder(i);
        System.out.println();
    }
}

// 
