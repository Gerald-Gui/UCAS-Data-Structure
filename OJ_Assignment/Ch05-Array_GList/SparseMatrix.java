import java.io.*;
import java.util.*;

public class SparseMatrix {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line);

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        ArrayList<Integer> v1 = new ArrayList<Integer>();
        line = stdin.readLine();
        st = new StringTokenizer(line);
        while (st.hasMoreTokens()) {
            v1.add(Integer.parseInt(st.nextToken()));
        }

        int[][] b1 = new int[m][n];
        for (int i = 0; i < m; i++) {
            line = stdin.readLine();
            st = new StringTokenizer(line);
            for (int j = 0; j < n; j++) {
                b1[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        ArrayList<Integer> v2 = new ArrayList<Integer>();
        line = stdin.readLine();
        st = new StringTokenizer(line);
        while (st.hasMoreTokens()) {
            v2.add(Integer.parseInt(st.nextToken()));
        }

        int[][] b2 = new int[m][n];
        for (int i = 0; i < m; i++) {
            line = stdin.readLine();
            st = new StringTokenizer(line);
            for (int j = 0; j < n; j++) {
                b2[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        ArrayList<Integer> res_v = new ArrayList<Integer>();
        int[][] res_b = new int[m][n];
        Iterator<Integer> it1 = v1.iterator();
        Iterator<Integer> it2 = v2.iterator();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b1[i][j] == 1 && b2[i][j] == 1) {
                    int tmp = it1.next() + it2.next();
                    if (tmp != 0) {
                        res_v.add(tmp);
                        res_b[i][j] = 1;
                    } else {
                        res_b[i][j] = 0;
                    }
                } else if (b1[i][j] == 1 && b2[i][j] == 0) {
                    res_v.add(it1.next());
                    res_b[i][j] = 1;
                } else if (b1[i][j] == 0 && b2[i][j] == 1) {
                    res_v.add(it2.next());
                    res_b[i][j] = 1;
                } else {
                    res_b[i][j] = 0;
                }
            }
        }

        if (res_v.size() == 0) {
            System.out.println();
        } else {
            for (int i = 0; i < res_v.size(); i++) {
                if (i == res_v.size() - 1) {
                    System.out.println(res_v.get(i));
                } else {
                    System.out.print(res_v.get(i) + " ");
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == n - 1) {
                    System.out.println(res_b[i][j]);
                } else {
                    System.out.print(res_b[i][j] + " ");
                }
            }
        }
    }
}