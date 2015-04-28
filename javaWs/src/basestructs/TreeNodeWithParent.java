package basestructs;

import basestructs.basestruct.interfaces.NodeIf;

/**
 * Created by rdimri on 2/15/15.
 */
public class TreeNodeWithParent extends TreeNode implements NodeIf{
    TreeNodeWithParent p;
    TreeNodeWithParent(int _v) {
        super(_v);
        p = null;
    }

    TreeNodeWithParent() {
        super();
        p = null;
    }

    public void addNode(TreeNodeWithParent node, boolean isLeft) {
        super.addNode(node, isLeft);
        node.setP(this);
    }

    public TreeNodeWithParent getP() {
        return p;
    }

    public void setP(TreeNodeWithParent p) {
        this.p = p;
    }

    public String getNodeInfo() {
        String res = super.getNodeInfo();
        res = res.trim();
        String currInfo = " parentNode=" + p == null ? "null" : "Not null" + "\n";
        return res + currInfo;
    }
}
