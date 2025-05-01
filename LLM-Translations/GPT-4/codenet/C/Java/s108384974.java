
class Node {
    int key;
    Node parent;
    Node left;
    Node right;
}

public class s108384974 {
    Node root = null;

    Node find(Node x, int k) {
        while (x != null && k != x.key) {
            if (k < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }
        return x;
    }

    void insert(int k) {
        Node y = null;
        Node x = root;

        Node z = new Node();
        z.key = k;
        z.left = null;
        z.right = null;

        while (x != null) {
            y = x;
            if (z.key < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }
        z.parent = y;

        if (y == null) {
            root = z;
        } else if (z.key < y.key) {
            y.left = z;
        } else {
            y.right = z;
        }
    }

    void inorder(Node u) {
        if (u == null) {
            return;
        }
        inorder(u.left);
        System.out.printf(" %d", u.key);
        inorder(u.right);
    }

    void preorder(Node u) {
        if (u == null) {
            return;
        }
        System.out.printf(" %d", u.key);
        preorder(u.left);
        preorder(u.right);
    }

    void print() {
        inorder(root);
        System.out.println("");
        preorder(root);
        System.out.println("");
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        int n = 10;
        int[] values = new int[] {1, 5, 10, 12, 15, 20, 25, 30, 35, 40};

        for (int i = 0; i < n; i++) {
            tree.insert(values[i]);
        }

        tree.print();
    }
}

// 
