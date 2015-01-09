#!/usr/bin/python

import os
import shutil
import sys

class CFInitializer:
    """
    Code to initialize templates for codeforces.
    """

    templateDir = "/home/rdimri/Dropbox/programming/templates/"
    dest = "/home/rdimri/programming/codeforces/"
    classTemplate = "ClassTemplate.cc"
    makefile = "makefile"


    def initializeFileList(self):
        self.fileNames = [CFInitializer.classTemplate, CFInitializer.makefile];

    def initializeCode(self):
        self.createDestinationDirectory()
        self.copyFilesOver()
        self.substituteClassName()
        self.renameClassFile()

    def renameClassFile(self):
        os.rename(CFInitializer.dest + self.className + "/" + CFInitializer.classTemplate, CFInitializer.dest + self.className + "/" + self.className + ".cc")

    def createDestinationDirectory(self):
        if not os.path.isdir(self.destDir + self.className):
            os.makedirs(self.destDir + self.className)

    def copyFilesOver(self):
        for filename in self.fileNames:
            shutil.copy(CFInitializer.templateDir + filename, self.destDir + self.className + "/")

    def inplace_change(self, filename, old_string, new_string):
        s=open(filename).read()
        if old_string in s:
            print 'Changing "{old_string}" to "{new_string}"'.format(**locals())
            s=s.replace(old_string, new_string)
            f=open(filename, 'w')
            f.write(s)
            f.flush()
            f.close()
        else:
            print 'No occurances of "{old_string}" found.'.format(**locals())

    def substituteClassName(self):
        for filename in self.fileNames:
            self.inplace_change(self.destDir + self.className + "/" + filename, "CLASSNAME", self.className)

    def __init__ (self, className, destDir):
        self.className = className
        self.destDir = destDir
        self.initializeFileList()

    def __init__ (self, className):
        self.className = className
        self.destDir = CFInitializer.dest
        self.initializeFileList()

def main(argv):
    if len(argv) == 2:
        t = CFInitializer(argv[1])
        t.initializeCode()
    elif len(argv) == 3:
        t = CFInitializer(argv[1], argv[2])
        t.initializeCode()
    else:
        print "This script only accepts two or three args"


if  __name__ == "__main__":
    main(sys.argv)
