import java.util.*;

public class s323794848 {
    static class Deque {
        LinkedList<Character> front, back;

        Deque() {
            front = new LinkedList<>();
            back = new LinkedList<>();
        }

        boolean isEmptyFront() {
            return front.isEmpty();
        }

        boolean isEmptyBack() {
            return back.isEmpty();
        }

        void pushBack(char v) {
            back.addLast(v);
        }

        void pushFront(char v) {
            front.addLast(v);
        }

        boolean popBack(Character v) {
            boolean r = true;
            if (!isEmptyBack()) {
                v = back.removeLast();
            } else if (!isEmptyFront()) {
                v = front.removeFirst();
            } else {
                r = false;
            }
            return r;
        }

        boolean popFront(Character v) {
            boolean r = true;
            if (!isEmptyFront()) {
                v = front.removeLast();
            } else if (!isEmptyBack()) {
                v = back.removeFirst();
            } else {
                r = false;
            }
            return r;
        }

        char get(int idx) {
            int tot = front.size() + back.size();
            char v = 0;
            if (idx < tot) {
                if (idx < front.size()) {
                    v = front.get(front.size() - 1 - idx);
                } else {
                    v = back.get(idx - front.size());
                }
            }
            return v;
        }
    }

    static class Operation {
        boolean rev, front;
        char c;

        Operation(boolean rev, boolean front, char c) {
            this.rev = rev;
            this.front = front;
            this.c = c;
        }
    }

    static String reverse(String s) {
        StringBuilder r = new StringBuilder(s);
        return r.reverse().toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        int Q = in.nextInt();
        Operation[] ops = new Operation[Q];
        for (int i = 0; i < Q; i++) {
            int q = in.nextInt();
            if (q == 1) {
                ops[i] = new Operation(true, false, ' ');
            } else {
                int f = in.nextInt();
                char c = in.next().charAt(0);
                ops[i] = new Operation(false, f == 1, c);
            }
        }
        int[] sum = new int[Q + 1];
        for (int i = Q - 1; i >= 1; i--) {
            if (ops[i].rev) {
                sum[i - 1] = sum[i] + 1;
            } else {
                sum[i - 1] = sum[i];
            }
        }
        if (sum[0] % 2 == 1) {
            S = reverse(S);
        }
        Deque deq = new Deque();
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) {
                if (ops[i].front) {
                    if (sum[i] % 2 == 1) {
                        deq.pushBack(ops[i].c);
                    } else {
                        deq.pushFront(ops[i].c);
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.pushFront(ops[i].c);
                    } else {
                        deq.pushBack(ops[i].c);
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            sb.append(deq.front.get(i));
        }
        sb.append(S);
        for (int i = 0; i < deq.back.size(); i++) {
            sb.append(deq.back.get(i));
        }
        System.out.println(sb.toString());
    }
}
// 
