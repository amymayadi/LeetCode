import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Json {
    public static String value(String str) {
          return str;
    }
}

class Solution {
    public String convert(String s, int numRows) {
        if (numRows >= s.length() || numRows < 2)
            return s;
        // sb declaration
        final StringBuilder[] sb = new StringBuilder[numRows]; // 常量用final，JVM缓存并且优化
        for (int i = 0; i < numRows; i++)
            // sb[i] initialization
            sb[i] = new StringBuilder();

        int i = 0;
        while(i < s.length())
        {
            // down
            for (int j = 0; j < numRows && i < s.length(); j++ )
            {
                sb[j].append(s.charAt(i++));
            }
            // up
            for (int j = numRows - 2; j > 0 && i < s.length(); j--)
            {
                sb[j].append(s.charAt(i++));
            }
        }
        String ret = "";
        for (int j = 0; j < numRows; j++)
            ret += sb[j];
        return ret;
    }
}

public class ZigZagConversion {
    public static String stringToString(String input) {
        if (input == null) {
            return "null";
        }
        return Json.value(input).toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            String s = stringToString(line);
            line = in.readLine();
            int numRows = Integer.parseInt(line);

            String ret = new Solution().convert(s, numRows);

            String out = (ret);

            System.out.print(out);
        }
    }
}

