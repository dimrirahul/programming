package lruCache;

/**
 * Created by rdimri on 4/24/15.
 */
public class ObjectToCache {
    int value;
    public ObjectToCache(int value) {
        this.value = value;
    }

    public String toString() {
        return String.valueOf(value);
    }
}
