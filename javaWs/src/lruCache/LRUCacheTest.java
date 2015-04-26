package lruCache;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class LRUCacheTest {

    LRUCache lruCache;
    @Before
    public void setUp() {
        lruCache = new LRUCache();
    }

    @Test
    public void testGetCachedObjectNoObjectRefreshed() throws Exception {
        Key k1 = new Key(1);
        Key k2 = new Key(2);
        Key k3 = new Key(3);
        lruCache.getCachedObject(k1);
        lruCache.getCachedObject(k2);
        lruCache.getCachedObject(k3);
        assertTrue(lruCache.getCacheSize() == 3);
        Key k4 = new Key(4);
        lruCache.getCachedObject(k4);
        assertTrue(lruCache.getCacheSize() == 3);
        assertFalse(lruCache.isKeyPresent(k1));
    }

    @Test
    public void testGetCachedObjectsRefreshed() throws Exception {
        Key k1 = new Key(1);
        Key k2 = new Key(2);
        Key k3 = new Key(3);
        lruCache.getCachedObject(k1);
        lruCache.getCachedObject(k2);
        lruCache.getCachedObject(k3);
        lruCache.getCachedObject(k1);
        assertTrue(lruCache.getCacheSize() == 3);
        Key k4 = new Key(4);
        lruCache.getCachedObject(k4);
        assertTrue(lruCache.getCacheSize() == 3);
        assertTrue(lruCache.isKeyPresent(k1));
        assertFalse(lruCache.isKeyPresent(k2));
    }
    @Test
    public void testGetCachedObjectsRefreshed2() throws Exception {
        Key k1 = new Key(1);
        Key k2 = new Key(2);
        Key k3 = new Key(3);
        lruCache.getCachedObject(k1);
        lruCache.getCachedObject(k2);
        lruCache.getCachedObject(k3);
        lruCache.getCachedObject(k1);
        lruCache.getCachedObject(k2);
        assertTrue(lruCache.getCacheSize() == 3);
        Key k4 = new Key(4);
        lruCache.getCachedObject(k4);
        assertTrue(lruCache.getCacheSize() == 3);
        assertTrue(lruCache.isKeyPresent(k1));
        assertFalse(lruCache.isKeyPresent(k3));
        System.out.println(lruCache);
    }
}