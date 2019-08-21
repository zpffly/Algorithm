import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

/**
 * https://juejin.im/post/5c733670e51d4568b3326aac
 * https://blog.csdn.net/tham_/article/details/48718587
 * https://songlee24.github.io/2014/11/29/print-all-LCS/
 */
public class LCS {

    private String x;
    private String y;
    private int table[][]; //记录最长公共子序列
    private ArrayList<String> totalRes = new ArrayList<>();

    public LCS(String x, String y){
        this.x = x;
        this.y = y;
        table = new int[x.length()+1][y.length()+1];
    }

    //得到x, y 的最长公共子序列
    public void getLCS() {

        int xLength = x.length();
        int yLength = y.length();

        for (int i = 0; i < xLength; i++) {
            table[i][0] = 0;
        }

        for (int i = 1; i < yLength; i++) {
            table[0][i] = 0;
        }

        for (int i = 1; i <= xLength; i++) {
            for (int j = 1; j <= yLength; j++) {
                //x[i] = y[j], 字符串跟表table的索引起点不同， 所以要减一
                if (x.charAt(i-1) == y.charAt(j-1)){
                    table[i][j] = table[i-1][j-1] + 1;
                }else { //x[i] != y[j]
                    table[i][j] = Math.max(table[i-1][j], table[i][j-1]);
                }
            }
        }

//        System.out.println(table[xLength][yLength]);
    }
    /**
     * 功能：字符串逆序
     */
    private String reverse(String str) {
        StringBuffer strBuf = new StringBuffer(str).reverse();
        return strBuf.toString();
    }


    //回溯求出所有最长公共子序和
    private void traceBack(int xIndex, int yIndex, String res){
        while (xIndex > 0 && yIndex > 0){
            if (x.charAt(xIndex-1) == y.charAt(yIndex-1)){
                res += x.charAt(xIndex-1);
                -- xIndex;
                -- yIndex;
            }else {

                if (table[xIndex-1][yIndex] > table[xIndex][yIndex-1])
                    -- xIndex;
                else if (table[xIndex-1][yIndex] < table[xIndex][yIndex-1])
                    -- yIndex;
                else { //左边等于上边
                    traceBack(xIndex-1, yIndex, res);
                    traceBack(xIndex, yIndex-1, res);
                    return;
                }
            }
        }
        totalRes.add(reverse(res));
    }

    public void printRes(){
        String s = "";
        traceBack(x.length(), y.length(), s);
        Iterator<String> iterator = totalRes.iterator();
        while (iterator.hasNext()){
            System.out.println(iterator.next());
        }
    }


    public static void main(String[] args) {
        String x = "ABCBDAB";
        String y = "BDCABA";

        LCS lcs = new LCS(x, y);
        lcs.getLCS();
        lcs.printRes();

    }


}
