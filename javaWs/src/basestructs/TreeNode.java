package basestructs;

import basestructs.basestruct.interfaces.NodeIf;
import exceptions.NodeOverwriteException;

/**
 * Created by rdimri on 2/15/15.
 */
public class TreeNode implements NodeIf{
    int v;
    TreeNode l, r;
    public TreeNode(int _v) {
        this();
        v = _v;
    }

    public TreeNode() {
        v= 0;
        l = r = null;
    }

    public void addNode(TreeNode node, boolean isLeft) {
        if (isLeft) {
            if ( l != null) {
                throw new NodeOverwriteException(node, l);
            }
            l = node;
        } else {
            if (r != null) {
                throw new NodeOverwriteException(node, r);
            }
            r = node;
        }
    }

    public String getNodeInfo() {
        StringBuilder sb =  new StringBuilder();
        sb.append("Value=" + v + " leftChild=");
        sb.append( l == null ? "null" : " Not null");
        sb.append(" rightChild=");
        sb.append( r == null ? "null": " NotNull");
        sb.append("\n");
        return sb.toString();
    }
}
