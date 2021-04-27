import java.io.*;
import java.util.*;

class ListNode {
    String      val;
    ListNode    nxt;
    ListNode() {
        val = "";   nxt = null;
    }
    ListNode(String str) {
        val = str;  nxt = null;
    }
}

class Queue {
    ListNode tail;

    Queue() {
        tail = new ListNode();
        tail.nxt = tail;
    }
    boolean IsEmpty() {
        return tail.nxt == tail;
    }
    void EnQueue(String str) {
        ListNode p = new ListNode(str);
        p.nxt = tail.nxt;
        tail.nxt = p;
        tail = tail.nxt;
    }
    String DeQueue() {
        tail.nxt = tail.nxt.nxt;
        return tail.nxt.val;
    }

}

public class MyQueue {    
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int n = Integer.parseInt(line);
        line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line, ",");

        Queue Q = new Queue();
        while (st.hasMoreTokens()) {
            Q.EnQueue(st.nextToken());
        }

        int i;
        for (i = 0; i < n - 1; i++) {
            System.out.print(Q.DeQueue() + ",");
        }
        System.out.println(Q.DeQueue());
    }
}