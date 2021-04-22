import java.util.*;

public class StrReverse {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        StringBuilder str = new StringBuilder(cin.nextLine());
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
            char tmp = str.charAt(j);
            str.setCharAt(j, str.charAt(i));
            str.setCharAt(i, tmp);
        }
        System.out.println(str);
    }
}