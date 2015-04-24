package googleIv.opfilter;

/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public interface Filter<T1, T2> {
    boolean filter(T1 t1, T2 t2);
}
