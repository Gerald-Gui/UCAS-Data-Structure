import java.io.*;
import java.util.*;
    
class ListNode {
    String val;
    ListNode nxt;
    ListNode() {
        val = "";
        nxt = null;
    }
    ListNode(String str, ListNode ptr) {
        val = str;
        nxt = ptr;
    }
}

public class ReverseLinkList {
    static void ReverseList(ListNode head) {
        ListNode p = head.nxt;
        ListNode q = head.nxt;
        head.nxt = null;
        while (p != null) {
            q = p;
            p = p.nxt;
            q.nxt = head.nxt;
            head.nxt = q;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line, ",");
        
        ListNode head = new ListNode();
        ListNode p = head;
        while (st.hasMoreTokens()) {
            p.nxt = new ListNode(st.nextToken(), null);
            p = p.nxt;
        }

        ReverseList(head);

        for (p = head.nxt; p != null; p = p.nxt) {
            if (p.nxt != null) {
                System.out.print(p.val + ",");
            } else {
                System.out.println(p.val);
            }
        }
    }
}
