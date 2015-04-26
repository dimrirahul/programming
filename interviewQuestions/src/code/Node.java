package code;

/**
 * Created by rdimri on 4/7/15.
 */
public class Node {
    public int key, w, pid, rid, lid, id;
    Node(int _id, int _w, int _key) {
        w = _w;
        key = _key;
        id = _id;
        pid = rid = lid = -1;
    }
}
