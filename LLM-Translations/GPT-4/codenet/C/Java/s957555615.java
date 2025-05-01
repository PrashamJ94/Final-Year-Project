
class Node {
    Node left, right, parent;
    int key;

    public Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}

class BinaryTree {
    Node root = null;

    Node treeMinimum(Node x) {
        while (x.left != null) x = x.left;
        return x;
    }

    Node treeMaximum(Node x) {
        while (x.right != null) x = x.right;
        return x;
    }

    Node treeSearch(Node u, int k) {
        if (u == null || k == u.key) return u;

        if (k < u.key) return treeSearch(u.left, k);
        else return treeSearch(u.right, k);
    }

    Node treeSuccessor(Node x) {
        Node y;
        if (x.right != null) return treeMinimum(x.right);

        y = x.parent;
        while (y != null && x == y.right) {
            x = y;
            y = y.parent;
        }
        return y;
    }

    void treeDelete(Node z) {
        Node y; // node to be deleted
        Node x; // child of y

        if (z.left == null || z.right == null) y = z;
        else y = treeSuccessor(z);

        if (y.left != null) x = y.left;
        else x = y.right;

        if (x != null) x.parent = y.parent;

        if (y.parent == null) root = x;
        else if (y == y.parent.left) y.parent.left = x;
        else y.parent.right = x;

        if (y != z) z.key = y.key;
    }

    void insert(int k) {
        Node y = null;
        Node x = root;
        Node z;

        z = new Node(k);

        while (x != null) {
            y = x;
            if (z.key < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }
        z.parent = y;
        if (y == null) root = z;
        else if (z.key < y.key) y.left = z;
        else y.right = z;
    }

    void inorder(Node u) {
        if (u == null) return;
        inorder(u.left);
        System.out.print(" " + u.key);
        inorder(u.right);
    }

    void preorder(Node u) {
        if (u == null) return;
        System.out.print(" " + u.key);
        preorder(u.left);
        preorder(u.right);
    }
}

public class s957555615 {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();

        // Test the BinaryTree class with the same operations as in the C code
        // For example:
        // bt.insert(10);
        // bt.insert(5);
        // bt.insert(15);
        // bt.inorder(bt.root); // Should print " 5 10 15"
        // bt.preorder(bt.root); // Should print " 10 5 15"
    }
}

// 
