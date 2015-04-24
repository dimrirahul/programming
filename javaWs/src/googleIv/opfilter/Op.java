package googleIv.opfilter;

/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public interface Op <T> {
     boolean hasNext();
    T getNext();
}
