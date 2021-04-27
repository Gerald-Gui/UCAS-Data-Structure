import java.io.*;
import java.util.*;

public class SwapBinaryTreeChildren {
    static void BuildArrayList(ArrayList<Integer> arr, String line) {
        StringTokenizer st = new StringTokenizer(line);
        while (st.hasMoreTokens()) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
    }

    static void SwapChildren(int index,
                             ArrayList<Integer> left, ArrayList<Integer> right) {
        int tmp = left.get(index);
        left.set(index, right.get(index));
        right.set(index, tmp);
        if (left.get(index) != 0) {
            SwapChildren(left.get(index), left, right);
        }
        if (right.get(index) != 0) {
            SwapChildren(right.get(index), left, right);
        }
    }

    static void DisplayArrayList(ArrayList<Integer> arr) {
        int i;
        for (i = 0; i < arr.size() - 1; i++) {
            System.out.print(arr.get(i) + " ");
        }
        System.out.println(arr.get(i));
    }

    public static void main(String[] args) throws IOException {
        ArrayList<Integer> left  = new ArrayList<Integer>();
        ArrayList<Integer> right = new ArrayList<Integer>();
        String line;

        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        line = stdin.readLine();
        BuildArrayList(left, line);
        line = stdin.readLine();
        BuildArrayList(right, line);

        SwapChildren(1, left, right);

        DisplayArrayList(left);
        DisplayArrayList(right);
    }
}