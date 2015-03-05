package rmq;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class RMQTest {

    @Test
    public void testBuildQueryTable() throws Exception {
        List<Integer> arrList = new ArrayList<Integer>();
        for (int i = 1;i <= 90; i++) {
            arrList.add(i);
        }
        RMQ rmq = new RMQ(arrList);
        rmq.buildQueryTable();

        assertEquals(90, rmq.query(0, 90));


    }
}