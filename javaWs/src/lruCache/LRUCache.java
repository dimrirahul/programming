package lruCache;

import java.util.*;

/**
 * Created by rdimri on 4/24/15.
 */
public class LRUCache {
    public static  int CACHE_SIZE = 3;
    private final Map<Key, CacheEntry> cacheMap = new HashMap<Key, CacheEntry>(CACHE_SIZE);
    private final TreeMap<Long, Key> timeMap = new TreeMap<Long, Key>();

    LRUCache(int sz) {
        CACHE_SIZE = sz;
    }
    LRUCache() {}
    ObjectToCache getObjectFromLowerLayer(Key k) {
        ObjectToCache obj = new ObjectToCache(k.getKey());
        return obj;
    }

    ObjectToCache getCachedObject(Key key) {
        CacheEntry retValue;
        if (cacheMap.containsKey(key)) {
            retValue = cacheMap.get(key);
            long time = retValue.getTime();
            timeMap.remove(time);
            retValue.refreshTime();
            time = retValue.getTime();
            timeMap.put(time, key);
        } else {
            if (cacheMap.size() == CACHE_SIZE) {
                //delete the oldest element.
                long oldest = timeMap.firstKey();
                Key keyToDelete = timeMap.get(oldest);
                timeMap.remove(oldest);
                cacheMap.remove(keyToDelete);
            }
            ObjectToCache obj = getObjectFromLowerLayer(key);
            CacheEntry newEntry = new CacheEntry(obj);
            long timeToAdd = newEntry.getTime();
            timeMap.put(timeToAdd, key);
            cacheMap.put(key, newEntry);
            retValue = newEntry;
        }
        return retValue.getObj();
    }
    int getCacheSize() {
        return cacheMap.size();
    }
    boolean isKeyPresent(Key k) {
        return cacheMap.containsKey(k);
    }
    public TreeMap<Long, Key> getTimeMap() {
        return timeMap;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Hashtable\n");
        for (Map.Entry<Key, CacheEntry> entry: cacheMap.entrySet()) {
            sb.append("Key: " + entry.getKey() + " " + entry.getValue() + "\n");
        }
        sb.append("TimeMap\n");
        for (Map.Entry<Long, Key> entry: timeMap.entrySet()) {
            sb.append("Time:" + entry.getKey() + " Key:" + entry.getValue() +"\n");
        }
        return sb.toString();
    }
}
