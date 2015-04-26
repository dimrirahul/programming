package print100;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by rdimri on 4/24/15.
 */
public class Print100 implements Runnable {
    private static int res = 0;
    public void run() {
        synchronized (Print100.class) {
            if (res < 100) {
                res++;
            }
        }

    }
}
