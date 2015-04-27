package lruCache;

/**
 * Created by rdimri on 4/24/15.
 */
public class Key {
    private int key;
    public Key(int key) {
        this.key = key;
    }

    int getKey() {
        return key;
    }

    public String toString() {
        return String.valueOf(key);
    }
}
