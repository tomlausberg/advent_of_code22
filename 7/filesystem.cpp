#include "filesystem.hpp"

FileSystem::FileSystem() {
    root = Dir();
    current_dir = root;
}

void Filesystem::cd(std::string path) {
    if (path == "/") {
        current_dir = root;
    } else {
       if (find(dirs.begin(), dirs.end(), path) != dirs.end()) {
           current_dir = path;
       } else {
           std::cout << "No such directory" << std::endl;
       }
    }

}

void Filesystem::ls(std::string path) {
    if (path == "/") {
        for (int i = 0; i < root.dirs.size(); i++) {
            std::cout << root.dirs[i] << std::endl;
        }
    } else {
        if (find(dirs.begin(), dirs.end(), path) != dirs.end()) {
            for (int i = 0; i < path.dirs.size(); i++) {
                std::cout << path.dirs[i] << std::endl;
            }
        } else {
            std::cout << "No such directory" << std::endl;
        }
    }
}

Dir::Dir() {
    files = std::vector<int>();
    dirs = std::vector<Dir>();
}

Dir::~Dir() {}
* args */