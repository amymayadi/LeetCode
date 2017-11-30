import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by mayadi on 17/03/2017.
 */
public class Solution {
    public int lengthOfLongestSubstring(String s){
        int n = s.length();
        int ans = 0;
        for (int i = 0; i <= n; i++)
            for (int j =i +1; j <=n; j++) {
                // 打出有变长的
                String sij = s.substring(i,j);
                if (allUnique(s, i, j) && j-i>ans)
                    System.out.println(sij);

                if (allUnique(s, i, j)) {
                    ans = Math.max(ans, j - i);
                }
            }
        return ans;
    }

    public boolean allUnique(String s, int start, int end){
        // 字符串在集合中有重复
        Set<Character> set = new HashSet<>();
        for (int i = start; i < end; i++){
            Character ch = s.charAt(i);
            if (set.contains(ch))
                return false;
            set.add(ch);
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        String st = "abcabcbb";
        String st2 = "ddddd";
        String st3 = "pwwkew";

        Solution s = new Solution();
        int a = s.lengthOfLongestSubstring(st2);
        System.out.println(a);
    }
}