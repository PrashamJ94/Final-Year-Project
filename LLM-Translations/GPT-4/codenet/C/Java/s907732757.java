
import java.util.Scanner;

public class s907732757 {
    static class Node {
        int key;
        Node next;
        Node prev;

        public Node(int key) {
            this.key = key;
        }
    }

    static Node head;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        head = new Node(0);
        head.next = head;
        head.prev = head;

        for (int i = 0; i < n; i++) {
            String op = sc.next();
            if (op.equals("insert")) {
                int a = sc.nextInt();
                insert(a);
            } else if (op.equals("delete")) {
                int a = sc.nextInt();
                delete(a);
            } else if (op.equals("deleteFirst")) {
                deleteFirst();
            } else if (op.equals("deleteLast")) {
                deleteLast();
            }
        }

        Node x = head;
        while (x.next != head) {
            System.out.print(x.next.key);
            x = x.next;
            if (x.next != head) {
                System.out.print(" ");
            }
        }
        System.out.println();

        sc.close();
    }

    public static void insert(int a) {
        Node x = new Node(a);
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }

    public static void delete(int a) {
        Node x = head;

        while (x.next != head) {
            x = x.next;
            if (x.key == a) {
                x.prev.next = x.next;
                x.next.prev = x.prev;
                break;
            }
        }
    }

    public static void deleteFirst() {
        Node x = head.next;
        head.next = x.next;
        x.next.prev = head;
    }

    public static void deleteLast() {
        Node x = head.prev;
        head.prev = x.prev;
        x.prev.next = head;
    }
}

// 
