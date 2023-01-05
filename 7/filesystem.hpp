#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <vector>
#include <string>

#include "filesystem.cpp"

class Dir {
   private:
    std::vector<int> files;
    std::vector<Dir> dirs;

   public:
    Dir();
    ~Dir();
};

class FileSystem {
   private:
    Dir current_dir;    
    Dir root;

   public:
    FileSystem();
    ~FileSystem();
    cd(std::string path);
    ls(std::string path);
};

#endif