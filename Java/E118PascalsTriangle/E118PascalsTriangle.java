import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * @author mayadi
 * time:O(n^2)
 * space:O(1)
 * Description: 118. Pascal's Triangle
 */
class Solution {
    /**
     * For example, given numRows = 5;
     Return
     [
         [1],
        [1,1],
       [1,2,1]
      [1,3,3,1]
     [1,4,6,4,1]
     ]
     */
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < numRows; i++){
            // 始终使用的是这个list，每次在头部加1
            list.add(0,1);
            for (int j = 1; j < list.size() - 1; j++) {
                // 使用之前的数据算出当前行的数据。
                list.set(j, list.get(j) + list.get(j+1));
            }
            res.add(new ArrayList<>(list));
        }
        return res;
    }
}

public class E118PascalsTriangle {
    public static String integerArrayListToString(List<Integer> nums, int length) {
        if (length == 0) {
            return "[]";
        }

        String result = "";
        for(int index = 0; index < length; index++) {
            Integer number = nums.get(index);
            result += Integer.toString(number) + ", ";
        }
        return "[" + result.substring(0, result.length() - 2) + "]";
    }

    public static String integerArrayListToString(List<Integer> nums) {
        return integerArrayListToString(nums, nums.size());
    }

    public static String int2dListToString(List<List<Integer>> nums) {
        StringBuilder sb = new StringBuilder("[");
        for (List<Integer> list: nums) {
            sb.append(integerArrayListToString(list));
            sb.append(",");
        }

        sb.setCharAt(sb.length() - 1, ']');
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int numRows = Integer.parseInt(line);

            List<List<Integer>> ret = new Solution().generate(numRows);

            String out = int2dListToString(ret);

            System.out.print(out);
        }
    }
}

