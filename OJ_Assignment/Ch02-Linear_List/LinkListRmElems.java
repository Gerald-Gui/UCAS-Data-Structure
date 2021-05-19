import java.io.*;
import java.util.*;

public class LinkListRmElems {
    private static class ListNode {
        int val;
        ListNode nxt;
        ListNode(int elm, ListNode ptr) {
            val = elm;
            nxt = ptr;
        }
    }

    static void BuildLinkList(ListNode head, StringTokenizer st) {
        ListNode p = head;
        while (st.hasMoreTokens()) {
            p.nxt = new ListNode(Integer.parseInt(st.nextToken()), null);
            p = p.nxt;
        }
    }

    static void DeleteElems(ListNode head, int mink, int maxk) {
        ListNode p;
        p = head;
        while (p.nxt != null) {
            if (p.nxt.val > mink && p.nxt.val < maxk) {
                p.nxt = p.nxt.nxt;
            } else {
                p = p.nxt;
            }
        }
    }

    static void PrintLinkList(ListNode head) {
        ListNode p = head.nxt;
        if (p == null) {
            System.out.println("NULL");
        } else {
            while (p != null) {
                if (p.nxt == null) {
                    System.out.println(p.val);
                } else {
                    System.out.print(p.val + " ");
                }
                p = p.nxt;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line);

        ListNode head = new ListNode(0, null);
        BuildLinkList(head, st);

        int mink, maxk;
        line = stdin.readLine();
        st = new StringTokenizer(line);
        mink = Integer.parseInt(st.nextToken());
        maxk = Integer.parseInt(st.nextToken());
        DeleteElems(head, mink, maxk);

        PrintLinkList(head);
    }
}
