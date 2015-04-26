package splitSum;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

/**
 * Created by rdimri on 4/24/15.
 */
public class Accumulator implements Callable<String> {
    public static final int elementsToCount = 100;
    private int id;
    public static final long SLEEP_TIME = 300;
    public Accumulator(int id) {
        this.id = id;
    }

    public String call() {
        int sum = 0;
        for (int i = elementsToCount * id ; i < elementsToCount * (id +1) ; i++) {
            sum += i;
        }
        StringBuilder sb = new StringBuilder();
        sb.append("From thread id:" + id + " sum from:" + elementsToCount*id + " to:" + elementsToCount * (id + 1) + " =" + sum);
        return sb.toString();
    }

    public static void main(String args[]) {
        ExecutorService es = Executors.newFixedThreadPool(2);
        List<Future<String>> res = new ArrayList<Future<String>>();
        for (int i = 0; i < 10; i++) {
            Accumulator accumulator = new Accumulator(i);
            Future<String> future = es.submit(accumulator);
            res.add(future);
        }

        for (Future<String> f: res ) {
            try {
                System.out.println(f.get());
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
