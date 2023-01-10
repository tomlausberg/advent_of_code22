#include "filesystem.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

Directory::Directory(Directory* parent, std::string name)
    : parent(parent), name(name) {
    subdirs = std::vector<std::shared_ptr<Directory>>();
    files = std::unordered_map<std::string, int>();
}

Directory::Directory() : Directory(nullptr, "/") {} // root

Directory::~Directory() {}

int Directory::size() {
    int size = 0;
    for(auto& subdir : subdirs) {
        size += subdir->size();
    }
    for(auto& file : files) {
        size += file.second;
    }
    return size;
}

int Directory::sizeOfSmallDirs(){
    int maxSize = 100000;
    int totalSize = 0;
    if (size() <= maxSize){
        totalSize += size();
    }
    for(auto& subdir : subdirs){
        totalSize += subdir->sizeOfSmallDirs();
    }
    return totalSize;
}

int Directory::smallestDir(int size){
    // return size of smallest dir bigger than "size"
    int smallest =  this->size();
    if (smallest > size){
        std::cout << name << " is " << smallest << std::endl;
    } else { // dir not big enough
        std::cout << name << " is too small" << std::endl;
        return INT32_MAX;
    }

    std::cout << "looping over " << name << std::endl;
    for(auto& subdir : subdirs){
        int smallestSubdir = subdir->smallestDir(size);
        if (smallestSubdir < smallest){
            std::cout << "new smallest=" << smallestSubdir << std::endl;
            smallest = smallestSubdir;
        }
    }
    std::cout << "smallest dir in " << name << " is " << smallest << std::endl;
    std::cout << "smallest " << smallest << std::endl;
    return smallest;
}

FileSystem::FileSystem() {
    root = std::make_shared<Directory>();
    current = root.get();
}

FileSystem::~FileSystem() {}

void FileSystem::ls() {
    std::cout << "ls" << std::endl;
    for(auto& subdir : current->subdirs) {
        std::cout << "\tdir " << subdir->name << std::endl;
    }
    for(auto& file : current->files) {
        std::cout << "\t" << file.second << " " << file.first << std::endl;
    }
}

void FileSystem::cd(std::string path) {
    std::cout << "cd " << path << std::endl;
    if(path == "/") {
        current = root.get();
        return;
    }
    if(path == "..") {
        current = current->parent;
        return;
    }
    for(auto& subdir : current->subdirs) {
        if(subdir->name == path) {
            current = subdir.get();
            return;
        }
    }

    //if path not found, create new directory
    auto dir =  mkdir(path);
    current = dir.get();
}

std::shared_ptr<Directory> FileSystem::mkdir(std::string path) {
    std::cout << "mkdir " << path << std::endl;
    auto dir = std::make_shared<Directory>(current, path);
    current->subdirs.push_back(dir);
    return dir;
}

void FileSystem::touch(std::string path, int size) {
    std::cout << "touch " << size << " " << path << std::endl;
    current->files[path] = size;
}

int FileSystem::sizeOfSmallDirs(){
    return root->sizeOfSmallDirs(); 
}

int FileSystem::sizeOfDirs(){
    return root->size(); 
}

int FileSystem::smallestDir(int size){
    return root->smallestDir(size);
}