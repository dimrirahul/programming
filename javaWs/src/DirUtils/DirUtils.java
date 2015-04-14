package DirUtils;


import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


/**
 * Copyright (c) 2015 by Cisco Systems, Inc.
 * All rights reserved.
 *
 * @author rdimri.
 */
public class DirUtils {
    public static boolean isDirPresent(String dirName) {
        Path path = Paths.get(dirName);
        return Files.exists(path);
    }

    public static void createIfNotPresent(String dirName) {
        if (!isDirPresent(dirName)) {
            File dir = new File(dirName);
            dir.mkdir();
        }
    }

    public static void cleanDirectory(String dirName) {
        createIfNotPresent(dirName);
    }

    public static void main(String[] args) {
        System.out.println(isDirPresent("/Users/rdimri"));
        createIfNotPresent("/Users/rdimri/blah");
        System.out.println(isDirPresent("/Users/rdimri/blah"));
    }
}
