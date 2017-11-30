import java.util.HashMap;
import java.util.Map;

/**
 * Created by mayadi on 19/03/2017.
 */
public class SolutionSlidingWindowOptimized {
    public int lengthOfLongestSubstring(String s){
        int ans=0;
        int len=s.length();
        // current index of character
        Map<Character, Integer> map1 = new HashMap<>();
        for(int i=0,j=0; j<len; j++) {
            // 已包含，让i指向包含字母最尾所在位置的下一个位置
            if (map1.containsKey(s.charAt(j))) {
                i = Math.max(map1.get(s.charAt(j)),i);
            }
            // 计算两个相同字母之间的大小
            ans = Math.max(ans, j - i + 1);
            // 将字母最尾的位置记录下来
            map1.put(s.charAt(j), j+1);
        }
        return ans;
    }

    public static void main(String args[]){
        String str = "abcabcbb";
        String str2 = "pwwekw";
        String str3 = "ddddd";
        String str4 = "dvdf";
        String str5 = "tmmzuxt";
        SolutionSlidingWindowOptimized s = new SolutionSlidingWindowOptimized();
        int a = s.lengthOfLongestSubstring(str5);
        System.out.println(a);
    }
}
