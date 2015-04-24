package googleIv.opfilter;

/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public class MutalOp implements Op {
    Op left, right;
    Filter<Op, Op> filter;
    Op nextElement = null;
    int leftIter = 0, rightIter = 0;
    public MutalOp(Op left, Op right, Filter<Op, Op> filter ) {
        this.left = left;
        this.right = right;
    }
    public boolean hasNext() {
        moveRefs();
        nextElement = null;
        Op leftElement = null, rightElement = null;
        while (left.hasNext() && nextElement == null) {
            leftElement = (Op) left.getNext();
            while (right.hasNext() && nextElement == null) {
                rightElement = (Op) right.getNext();
                if (filter.filter(leftElement, rightElement)) {
                    nextElement = leftElement;
                }
                rightIter++;
            }
            rightIter = 0;
            leftIter++;
        }
        return (nextElement != null) ? true: false;
    }
    public Op getNext() {
        return nextElement;
    }
    private void moveRefs() {
        int lPos = 0, rPos = 0;
        while (lPos < leftIter) {
            lPos++;
            left.getNext();
        }
        while (rPos < rightIter) {
            rPos++;
            right.getNext();
        }
    }
    public static void main(String[] args) {
        MutalOp mutalOp = new MutalOp(null, null, null);
    }
}
