package optimalTree;

/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public class Node {
    public int v;
    public Node l, r;

    public Node(int v) {
        this.v = v;
        l = r = null;
    }

    public void printTree(int h) {
        System.out.println("Value = " + v + " Height = " + h);
        if (l != null) {
            l.printTree(h+1);
        }
        if (r != null) {
            r.printTree(h+1);
        }
    }

    public boolean isSingle() {
        return r == null && l == null;
    }
}
