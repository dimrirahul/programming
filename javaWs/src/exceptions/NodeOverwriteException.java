package exceptions;

import basestructs.basestruct.interfaces.NodeIf;

/**
 * Created by rdimri on 2/15/15.
 */
public class NodeOverwriteException  extends RuntimeException{
    public NodeOverwriteException (NodeIf nodeExisting, NodeIf newNode) {
        super("Exception while adding node " + newNode.getNodeInfo() + " as node " + nodeExisting.getNodeInfo() + " already exists");
    }
}
