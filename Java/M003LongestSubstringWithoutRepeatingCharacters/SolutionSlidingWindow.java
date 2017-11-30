import java.util.HashSet;
import java.util.Set;

/**
 * Created by mayadi on 18/03/2017.
 */
public class SolutionSlidingWindow {
    public int lengthOfLongestSubstring(String s){
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans=0; int i=0,j=0;
        while(i<n && j<n){
                Character y = s.charAt(i);
                Character d = s.charAt(j);
                if (!set.contains(s.charAt(j))){
                    set.add(s.charAt(j++));
                    ans = Math.max(ans, j-i);
                }else {
                    // 最前的出set，外循环前移
                    set.remove(s.charAt(i++));
                }
        }
        return ans;
    }

    public static void main(String[] args){
        String str="abcabcbb";
        String str2="pwwkew";
        SolutionSlidingWindow s = new SolutionSlidingWindow();
        int a = s.lengthOfLongestSubstring(str2);
        System.out.println(a);
        return;
    }
}
