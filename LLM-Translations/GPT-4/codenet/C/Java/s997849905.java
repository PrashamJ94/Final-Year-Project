import java.util.LinkedList;
import java.util.Scanner;

class DoublyLinkedList {
    private int key;
    private DoublyLinkedList next;
    private DoublyLinkedList prev;

    public DoublyLinkedList(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }

    public DoublyLinkedList() {
        this.next = this;
        this.prev = this;
    }

    public void insert(int key) {
        DoublyLinkedList newNode = new DoublyLinkedList(key);
        newNode.next = this.next;
        this.next.prev = newNode;
        this.next = newNode;
        newNode.prev = this;
    }

    public void deleteFirst() {
        this.next = this.next.next;
        this.next.prev = this;
    }

    public void deleteLast() {
        this.prev = this.prev.prev;
        this.prev.next = this;
    }

    public void delete(int key) {
        DoublyLinkedList currentNode = this.next;
        while (currentNode != this) {
            if (currentNode.key == key) {
                currentNode.prev.next = currentNode.next;
                currentNode.next.prev = currentNode.prev;
                break;
            }
            currentNode = currentNode.next;
        }
    }

    public void printList() {
        DoublyLinkedList currentNode = this.next;
        while (currentNode != this) {
            System.out.print(currentNode.key + " ");
            currentNode = currentNode.next;
        }
        System.out.println();
    }
}

public class s997849905 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList doublyLinkedList = new DoublyLinkedList();

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if ("insert".equals(command)) {
                int key = scanner.nextInt();
                doublyLinkedList.insert(key);
            } else if ("deleteFirst".equals(command)) {
                doublyLinkedList.deleteFirst();
            } else if ("deleteLast".equals(command)) {
                doublyLinkedList.deleteLast();
            } else {
                int key = scanner.nextInt();
                doublyLinkedList.delete(key);
            }
        }

        doublyLinkedList.printList();
    }
}
// 
