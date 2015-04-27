package nQueenProblem;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public class Nqueen {
    public static final int SZ = 100;
    int pos[] = new int[SZ];
    int boardSz = 0;

    public Nqueen(int boardSz) {
        this.boardSz = boardSz;
        initPos();
    }

    void initPos() {
        for (int i = 0; i < SZ; i++) pos[i] = -1;
    }

    void printPos() {
        for (int i = 0; i < boardSz; i++) {
            for (int j = 0; j < boardSz; j++) {
                if (pos[j] == i) {
                    System.out.print("Q");
                } else {
                    System.out.print(".");
                }
            }
            System.out.println();
        }
        System.out.println("=============");
    }

    boolean areColliding(int r1, int c1, int r2, int c2) {
        if (r1 == r2 || c1 == c2 || Math.abs(c2 - c1) == Math.abs(r2 - r1)) return true;
        return false;
    }
    boolean isPossible() { return isPossible(boardSz);}
    boolean isPossible(int nq) {
        if (nq == 0) return true;
        for (int row = 0; row < boardSz; row++) {
            boolean res = true;
            for (int col = 0; col < boardSz - nq; col++) {
                if (areColliding(row, boardSz - nq, pos[col], col)) {
                    res = false;
                    break;
                }
            }
            if (res) {
                pos[boardSz - nq] = row;
                if (isPossible(nq - 1)) {
                    if (nq == boardSz)  {
                        printPos();
                    } else {
                        return res;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Nqueen nqueen = new Nqueen(4);
        nqueen.isPossible();
    }
}
