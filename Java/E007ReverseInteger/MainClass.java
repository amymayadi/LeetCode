import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by mayadi on 2017/11/26.
 */
class Solution {
    public int reverse(int x) {
        int ans = 0;
        int newres = 0;
        while(x!=0) {
            int left = x % 10;
            newres = 10 * ans + left;
            // If overflow exists, the new result will not equal previous one.
            if((newres-left)/10 != ans)
                return 0;
            x /= 10;
            ans = newres;
        }

        return newres;
    }
}

public class MainClass {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int x = Integer.parseInt(line);

            int ret = new Solution().reverse(x);

            String out = String.valueOf(ret);

            System.out.print(out);
        }
    }
}
