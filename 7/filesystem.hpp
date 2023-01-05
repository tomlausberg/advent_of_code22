#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <memory>
#include <string>
#include <vector>

class File {
   public:
    std::string name;
    int size;
    File(std::string name, int size) {
        this->name = name;
        this->size = size;
    }
    friend std::ostream& operator<<(std::ostream& os, const File& f) {
        os << f.size << " " << f.name;
        return os;
    }
};

class Dir {
   public:
    std::string name;
    Dir* parent;
    std::vector<File> files;
    std::vector<Dir> dirs;
    Dir(std::string name, Dir* parent);
    Dir();
    ~Dir();
    bool operator==(const std::string& other);
};

class FileSystem {
   private:
    Dir root;
    Dir& current_dir = root;

   public:
    FileSystem();
    // ~FileSystem();
    std::vector<Dir>::iterator findDir(std::string path);
    void cd(std::string path);
    void ls();
    void mkdir(std::string path);
    void mkfil(std::string name, int size);
};

#endif