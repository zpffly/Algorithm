/**
 * 马拉车算法，寻找最长回文子串
 */


public class Manacher {


    /*字符串预处理*/
    private String preHandelString(String s){
        StringBuilder stringBuffer = new StringBuilder(s.length()*2);
        stringBuffer.append('#');
        for (int i = 0; i < s.length(); ++i){
            stringBuffer.append(s.charAt(i));
            stringBuffer.append('#');
        }
        return stringBuffer.toString();
    }

    public String LongestPalindrome(String s){

        String str = preHandelString(s);
        int strLen = str.length();
        //存储每个字符对应的回文串的一半
        int[] len = new int[strLen];
        //右边界
        int rigthIndex = 0;
        int centerIndex = 0;
        //最长的子串长度
        int ans = 0;
        //最长子串长度对应的索引值
        int index = 0;
        for (int i = 0; i < strLen; i++) {
            if (i < rigthIndex){
                // 2*i - centerIndex 是关于已知回文串中心(最右边)的对称点
                //看是否大于已知回文串的右边界，小于它则找到了该点的最长回文串
                len[i] = Math.min(len[2*centerIndex - i], rigthIndex-i);
            }else {
                len[i] = 1;
            }

            //探索右边界外的字符
            while (i - len[i] >= 0 && i + len[i] < strLen && str.charAt(i - len[i]) == str.charAt(i + len[i]))
                len[i] ++;

            //更新最右边回文串及右边界
            if (i + len[i] > rigthIndex){
                rigthIndex = i + len[i];
                centerIndex = i;
            }

            //更新最大子串
            if (ans < len[i]){
                ans = len[i];
                index = i;
            }
        }

        return str.substring(index - ans + 1, index + ans).replace("#","");

    }

    public static void main(String[] args) {
        Manacher manacher = new Manacher();
        String[] testStrArr = new String[] {
                "abcdcef",
                "adaelele",
                "cabadabae",
                "aaaabcdefgfedcbaa",
                "aaba",
                "aaaaaaaaa"
        };

        for (String str : testStrArr){
            System.out.println(String.format("原字串 : %s", str));
            System.out.println(String.format("最长回文串 : %s", manacher.LongestPalindrome(str)));
            System.out.println();
        }
    }

}
