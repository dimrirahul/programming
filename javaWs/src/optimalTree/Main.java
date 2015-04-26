package optimalTree;


/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */

public class Main {
     Node balanceTree(Node head, int start, int end) {
         System.out.println("Start=" + start + " End=" + end);
        if (end - start == 1) return head;
        if (end - start == 2) {
            Node root = head.r;
            root.l = head;
            head.r = head.l = null;
            return root;
        }
        int mid = (start + end) / 2;
        Node root = head;
        Node prev = null;
        for (int i = start; i < mid; i++) {
            prev = root;
            root = root.r;
        }
        prev.r = null;
        Node leftSubtree = balanceTree(head, start, mid);
        Node rightSubtree = balanceTree(root.r, mid + 1, end);
        root.l = leftSubtree;
        root.r = rightSubtree;
        return root;
    }
    public void convertTree() {
        final int maxNodeId = 3;
        Node curr = null;
        Node head = null;
        int start = 1, end = 1;
        for (int i = 1; i < maxNodeId+1; i++) {
            Node n = new Node(i);
            if (curr != null) curr.r = n;
            curr = n;
            if (head == null) head = n;
            end++;
        }
        Node root = balanceTree(head, start, end);
        System.out.println("OUTPUT");
        root.printTree(1);
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.convertTree();
    }
}
