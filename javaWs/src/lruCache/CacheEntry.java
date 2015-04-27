package lruCache;

/**
 * Created by rdimri on 4/24/15.
 */
public class CacheEntry {
    private final ObjectToCache obj;
    private long time;
    public CacheEntry(ObjectToCache obj) {
        this.obj = obj;
        refreshTime();
    }
    void refreshTime() {
        time = System.nanoTime();
    }

    long getTime() {
        return time;
    }

    ObjectToCache getObj() {
        return obj;
    }

    public String toString() {
        return  obj.toString() + " Time:" + time;
    }
}
