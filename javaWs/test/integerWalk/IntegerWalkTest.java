package integerWalk;

import org.junit.Test;

import static org.junit.Assert.*;

public class IntegerWalkTest {

    @Test
    public void testIntegerWalk() throws Exception {
        IntegerWalk iw = new IntegerWalk();
        assertTrue(iw.integerWalk(1,10));
    }
}