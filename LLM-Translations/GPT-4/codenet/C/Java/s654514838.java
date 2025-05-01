
import java.util.Scanner;

class Node {
    int key;
    int priority;
    Node right, left;

    Node(int key, int priority) {
        this.key = key;
        this.priority = priority;
        this.right = null;
        this.left = null;
    }
}

public class s654514838 {
    public static Node NIL = null;

    public static void main(String[] args) {
        int num, x, y;
        String com;
        Node root = NIL;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();

        for (int i = 0; i < num; i++) {
            com = sc.next();
            switch (com.charAt(0)) {
                case 'i':
                    x = sc.nextInt();
                    y = sc.nextInt();
                    root = insert(root, x, y);
                    break;
                case 'd':
                    x = sc.nextInt();
                    root = delete(root, x);
                    break;
                case 'f':
                    x = sc.nextInt();
                    if (find(root, x)) System.out.println("yes");
                    else System.out.println("no");
                    break;
                case 'p':
                    print(root);
                    break;
            }
        }
        sc.close();
    }

    public static boolean find(Node p, int x) {
        while (p != NIL) {
            if (p.key == x) return true;
            else if (p.key > x) p = p.left;
            else p = p.right;
        }
        return false;
    }

    public static void inorder(Node a) {
        if (a.left != NIL) inorder(a.left);
        System.out.print(" " + a.key);
        if (a.right != NIL) inorder(a.right);
    }

    public static void preorder(Node p) {
        System.out.print(" " + p.key);
        if (p.left != NIL) preorder(p.left);
        if (p.right != NIL) preorder(p.right);
    }

    public static void print(Node p) {
        inorder(p);
        System.out.println();
        preorder(p);
        System.out.println();
    }

    public static Node rightRotate(Node p) {
        Node q = p.left;
        p.left = q.right;
        q.right = p;
        return q;
    }

    public static Node leftRotate(Node p) {
        Node q = p.right;
        p.right = q.left;
        q.left = p;
        return q;
    }

    public static Node insert(Node t, int key, int priority) {
        if (t == NIL) {
            return new Node(key, priority);
        }
        if (t.key == key) {
            return t;
        }

        if (key < t.key) {
            t.left = insert(t.left, key, priority);
            if (t.priority < t.left.priority) {
                t = rightRotate(t);
            }
        } else {
            t.right = insert(t.right, key, priority);
            if (t.priority < t.right.priority) {
                t = leftRotate(t);
            }
        }
        return t;
    }

    public static Node delete(Node t, int key) {
        if (t == NIL) {
            return NIL;
        }

        if (key < t.key) {
            t.left = delete(t.left, key);
        } else if (key > t.key) {
            t.right = delete(t.right, key);
        } else {
            if (t.left == NIL && t.right == NIL) {
                return NIL;
            } else if (t.left == NIL) {
                t = leftRotate(t);
            } else if (t.right == NIL) {
                t = rightRotate(t);
            } else {
                if (t.left.priority > t.right.priority) {
                    t = rightRotate(t);
                } else {
                    t = leftRotate(t);
                }
            }
            return delete(t, key);
        }
        return t;
    }
}


// 
