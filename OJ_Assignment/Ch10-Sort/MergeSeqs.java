import java.io.*;
import java.util.*;

public class MergeSeqs {
    static void BuildArrayList(ArrayList<Integer> arr, String line) {
        StringTokenizer st = new StringTokenizer(line);
        while (st.hasMoreTokens()) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arr1 = new ArrayList<Integer>();
        ArrayList<Integer> arr2 = new ArrayList<Integer>();

        BuildArrayList(arr1, stdin.readLine());
        BuildArrayList(arr2, stdin.readLine());

        int len1, len2;
        len1 = arr1.size();
        len2 = arr2.size();
        int i, j;
        i = j = 0;
        while (i < len1 || j < len2) {
            if (i == len1) {
                System.out.print(arr2.get(j++));
                System.out.print(j == len2 ? "\n" : " ");
            } else if (j == len2) {
                System.out.print(arr1.get(i++));
                System.out.print(i == len1 ? "\n" : " ");
            } else if (arr1.get(i) < arr2.get(j)) {
                System.out.print(arr1.get(i++) + " ");
            } else {
                System.out.print(arr2.get(j++) + " ");
            }
        }
    }
}
