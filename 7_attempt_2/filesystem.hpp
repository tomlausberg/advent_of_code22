#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

struct Directory {
    Directory* parent;
    std::string name;
    std::vector<std::shared_ptr<Directory>> subdirs;
    std::unordered_map<std::string, int> files;
    int size();
    int sizeOfSmallDirs();
    int smallestDir(int size);
    Directory(Directory* parent, std::string name);
    Directory();
    ~Directory();
};

class FileSystem {
   public:
    FileSystem();
    ~FileSystem();

    void ls();
    void cd(std::string path);
    std::shared_ptr<Directory> mkdir(std::string path);
    void touch(std::string path, int size);
    int sizeOfSmallDirs();
    int sizeOfDirs();
    int smallestDir(int size);


   private:
    std::shared_ptr<Directory> root;
    Directory* current;
};

#endif