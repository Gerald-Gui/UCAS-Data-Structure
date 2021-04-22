import java.io.*;
import java.util.*;

public class SortThreeInts {
    public static void main(String[] args) throws IOException{
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line);
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int z = Integer.parseInt(st.nextToken());

        int tmp;
        if(x < y){
            tmp = x;
            x = y;
            y = tmp;
        }
        if(z < y)
            System.out.println(x + " " + y + " " + z);
        else if(z > x)
            System.out.println(z + " " + x + " " + y);
        else
            System.out.println(x + " " + z + " " + y);
    }
}