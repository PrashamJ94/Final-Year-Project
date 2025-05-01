
public class s701716787 {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        // TODO: Implement command reading and execution logic

        tree.insert(10);
        tree.insert(5);
        tree.insert(15);

        tree.printInOrder();
        System.out.println();
        tree.printPreOrder();
        System.out.println();
    }
}

class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    public Node(int key) {
        this.key = key;
        this.parent = null;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    Node root;

    public BinaryTree() {
        root = null;
    }

    public void insert(int key) {
        Node newNode = new Node(key);

        if (root == null) {
            root = newNode;
        } else {
            Node parentNode = null;
            Node indexNode = root;

            while (indexNode != null) {
                parentNode = indexNode;

                if (newNode.key < indexNode.key) {
                    indexNode = indexNode.left;
                } else {
                    indexNode = indexNode.right;
                }
            }

            newNode.parent = parentNode;

            if (key < parentNode.key) {
                parentNode.left = newNode;
            } else {
                parentNode.right = newNode;
            }
        }
    }

    public void printInOrder() {
        printInOrderHelper(root);
    }

    private void printInOrderHelper(Node node) {
        if (node == null) {
            return;
        }

        printInOrderHelper(node.left);
        System.out.print(" " + node.key);
        printInOrderHelper(node.right);
    }

    public void printPreOrder() {
        printPreOrderHelper(root);
    }

    private void printPreOrderHelper(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(" " + node.key);
        printPreOrderHelper(node.left);
        printPreOrderHelper(node.right);
    }
}



