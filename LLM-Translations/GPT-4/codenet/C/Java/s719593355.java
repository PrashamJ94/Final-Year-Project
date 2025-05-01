
public class s719593355 {
    private Node nil;
    
    private class Node {
        int key;
        Node next;
        Node prev;
        
        public Node(int key) {
            this.key = key;
            this.next = null;
            this.prev = null;
        }
    }
    
    public DoublyLinkedList() {
        nil = new Node(-1);
        nil.next = nil;
        nil.prev = nil;
    }
    
    private Node listSearch(int key) {
        Node cur = nil.next;
        
        while (cur != nil && cur.key != key) {
            cur = cur.next;
        }
        
        return cur;
    }
    
    public void printList() {
        Node cur = nil.next;
        boolean isf = true;
        
        while (cur != nil) {
            if (!isf) {
                System.out.print(" ");
            }
            
            System.out.print(cur.key);
            cur = cur.next;
            isf = false;
        }
        
        System.out.println();
    }
    
    private void deleteNode(Node t) {
        t.prev.next = t.next;
        t.next.prev = t.prev;
    }
    
    public void deleteFirst() {
        Node t = nil.next;
        
        if (t == nil) {
            return;
        }
        
        deleteNode(t);
    }
    
    public void deleteLast() {
        Node t = nil.prev;
        
        if (t == nil) {
            return;
        }
        
        deleteNode(t);
    }
    
    public void delete(int key) {
        Node t = listSearch(key);
        
        if (t == nil) {
            return;
        }
        
        deleteNode(t);
    }
    
    public void insert(int key) {
        Node x = new Node(key);
        
        x.next = nil.next;
        nil.next.prev = x;
        nil.next = x;
        x.prev = nil;
    }
}


// 
