public class KMP {
    public static int[] next(String p){
        int[] next = new int[p.length()];
        int k = -1;
        int j = 0;
        next[0] = -1;
        while (j < p.length() - 1){
            if (k == -1 || p.charAt(k) == p.charAt(j)){
                k++;
                j++;
                if (p.charAt(k) == p.charAt(j))
                    next[j] = next[k];
                else
                    next[j] = k;
            }
            else {
                k = next[k];
            }
        }
        return next;
    }


    public static int kmp(String s, String p){
        int sIdx = 0;
        int pIdx = 0;
        int[] next = next(p);
        while (sIdx < s.length() && pIdx < p.length()){
            if (pIdx == -1 || s.charAt(sIdx) == p.charAt(pIdx)){
                sIdx++;
                pIdx++;
            }
            else {
                pIdx = next[pIdx];
            }
        }
        return pIdx == p.length() ? sIdx - pIdx : -1;
    }

    public static void main(String[] args) {
        String s = "abacababc";
        String p = "ababc";
        System.out.println(kmp(s, p));
    }
}
