
class Node {
    int l, r, par;

    public Node(int l, int r, int par) {
        this.l = l;
        this.r = r;
        this.par = par;
    }
}

public class s120278714 {
    static final int MAX = 25;
    static Node[] N = new Node[MAX];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, i, id, l, r, p = -1;

        n = sc.nextInt();
        init(n);

        for (i = 0; i < n; i++) {
            id = sc.nextInt();
            l = sc.nextInt();
            r = sc.nextInt();

            if (l != -1) {
                N[id].l = l;
                N[l].par = id;
            }
            if (r != -1) {
                N[id].r = r;
                N[r].par = id;
            }
        }

        for (i = 0; i < n; i++) {
            if (N[i].par == -1) {
                p = i;
                break;
            }
        }

        System.out.println("Preorder");
        Preorder(p);
        System.out.println();

        System.out.println("Inorder");
        Inorder(p);
        System.out.println();

        System.out.println("Postorder");
        Postorder(p);
        System.out.println();
    }

    static void init(int n) {
        for (int i = 0; i < n; i++) {
            N[i] = new Node(-1, -1, -1);
        }
    }

    static void Preorder(int p) {
        if (p != -1) {
            System.out.print(" " + p);
            Preorder(N[p].l);
            Preorder(N[p].r);
        }
    }

    static void Inorder(int p) {
        if (p != -1) {
            Inorder(N[p].l);
            System.out.print(" " + p);
            Inorder(N[p].r);
        }
    }

    static void Postorder(int p) {
        if (p != -1) {
            Postorder(N[p].l);
            Postorder(N[p].r);
            System.out.print(" " + p);
        }
    }
}

// 
