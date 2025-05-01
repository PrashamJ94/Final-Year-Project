import java.util.*;

class Node {
    int val;
    Boolean color;
    List<Pair> a = new ArrayList<>();

    Node(int val) {
        this.val = val;
    }
}

class Pair {
    Node node;
    int weight;

    Pair(Node node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

public class atcoder_ABC126_D {
    private static Node root;
    private static Set<Node> nodeSet = new HashSet<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            Node node1 = nodes[u - 1];
            Node node2 = nodes[v - 1];
            node1.a.add(new Pair(node2, w));
            node2.a.add(new Pair(node1, w));
        }
        root = nodes[0];
        root.color = true;
        traverse(root, 0);
        for (Node node : nodes) {
            System.out.println(node.color ? 1 : 0);
        }
    }

    private static void traverse(Node node, int distance) {
        if (nodeSet.contains(node)) {
            return;
        }
        nodeSet.add(node);
        for (Pair pair : node.a) {
            Node adjNode = pair.node;
            int dis = pair.weight;
            if ((distance + dis) % 2 == 0) {
                adjNode.color = root.color;
            } else {
                adjNode.color = !root.color;
            }
            traverse(adjNode, distance + dis);
        }
    }
}

// End of Code.
