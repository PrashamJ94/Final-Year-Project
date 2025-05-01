
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node {
    int key;
    Node prev;
    Node next;

    Node(int key) {
        this.key = key;
    }

    void rPrint(StringBuilder buf) {
        buf.append(key);
        if (next != null) {
            buf.append(" ");
            next.rPrint(buf);
        }
    }

    Node[] delete(Node first, Node last) {
        if (prev != null && next != null) {
            prev.next = next;
            next.prev = prev;
            return new Node[]{first, last};
        }

        if (next == null && prev == null) {
            return new Node[]{null, null};
        }

        if (prev == null) {
            first = next;
            next.prev = null;
        }

        if (next == null) {
            last = prev;
            prev.next = null;
        }

        return new Node[]{first, last};
    }
}

public class s269502139 {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        Node first = null, last = null;
        stdin.readLine();

        String cmd;
        while ((cmd = stdin.readLine()) != null) {
            String[] xcmd = cmd.split(" ");
            switch (xcmd[0]) {
                case "deleteFirst":
                    Node[] firstDelete = first.delete(first, last);
                    first = firstDelete[0];
                    last = firstDelete[1];
                    break;
                case "deleteLast":
                    Node[] lastDelete = last.delete(first, last);
                    first = lastDelete[0];
                    last = lastDelete[1];
                    break;
                default:
                    int k = Integer.parseInt(xcmd[1]);
                    switch (xcmd[0]) {
                        case "delete":
                            for (Node a = first; a != null; a = a.next) {
                                if (a.key == k) {
                                    Node[] deleteNode = a.delete(first, last);
                                    first = deleteNode[0];
                                    last = deleteNode[1];
                                    break;
                                }
                            }
                            break;
                        case "insert":
                            Node n = new Node(k);
                            n.next = first;
                            if (first != null) {
                                first.prev = n;
                            }

                            first = n;
                            if (last == null) {
                                last = n;
                            }
                            break;
                    }
                    break;
            }
        }
        StringBuilder buf = new StringBuilder();
        first.rPrint(buf);
        System.out.println(buf.toString());
    }
}

// 
