
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    public Node(int key) {
        this.key = key;
    }
}

class Tree {
    Node root;

    public void insert(int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        Node prevNode = null;
        while (currentNode != null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right;
            } else {
                currentNode = currentNode.left;
            }
        }

        Node newNode = new Node(key);
        newNode.parent = prevNode;
        if (prevNode.key < key) {
            prevNode.right = newNode;
        } else {
            prevNode.left = newNode;
        }
    }

    public void print() {
        List<Integer> acc = new ArrayList<>();
        if (root == null) {
            System.out.println();
            System.out.println();
        } else {
            System.out.println(" " + visitInorder(root, acc));
            System.out.println(" " + visitPreorder(root, acc));
        }
    }

    private List<Integer> visitPreorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        acc.add(node.key);
        if (node.left != null) {
            acc = visitPreorder(node.left, acc);
        }
        if (node.right != null) {
            acc = visitPreorder(node.right, acc);
        }
        return acc;
    }

    private List<Integer> visitInorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        if (node.left != null) {
            acc = visitInorder(node.left, acc);
        }
        acc.add(node.key);
        if (node.right != null) {
            acc = visitInorder(node.right, acc);
        }
        return acc;
    }
}

public class s632215495 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        Tree tree = new Tree();
        for (int i = 0; i < n; i++) {
            String command = sc.next();
            switch (command) {
                case "insert":
                    int key = sc.nextInt();
                    tree.insert(key);
                    break;
                case "print":
                    tree.print();
                    break;
                default:
                    throw new IllegalArgumentException("unknown command: " + command);
            }
        }
    }
}


