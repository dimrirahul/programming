package rmq;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by rdimri on 2/22/15.
 */
public class RMQ {
    List<Integer> input;
    int table[][];

    private int getLog(int sz) {
        int res = 0;
        while (sz > 1) {
            sz /= 2;
            res++;
        }
        return res;
    }

    public RMQ(List<Integer> input) {
        this.input = input;
    }

    public void buildQueryTable() {
        table = new int [input.size()][getLog(input.size()) + 1];
        for (int i = 0; i < input.size(); i++) {
            int logLen = 0;
            while ( i + (1 << logLen) <= input.size()) {
                if (logLen == 0) {
                    table[i][0] = input.get(i);
                } else {
                    int start = (1 << (logLen - 1));
                    int end = (1 << logLen);
                    for (int k = start; k < end; k++) {
                        table[i][logLen] = Math.max(Math.max(table[i][logLen], table[i][logLen -1]), input.get(k + i));
                    }
                }
                logLen++;
            }
        }
    }
    public void printTable() {
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < getLog(input.size()) + 1; j++) {
                System.out.print(table[i][j] + " ");
            }
            System.out.println();
        }
    }
    public int query(int start, int end) {
        int l = getLog(end - start);
//        System.out.println(table[start][l]);
//        System.out.println(table[end - (1 << l)][l]);
//        printTable();
        return Math.max(table[start][l], table[end - (1 << l)][l]);
    }
}
