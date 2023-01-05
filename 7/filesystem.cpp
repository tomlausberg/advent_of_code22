#include "filesystem.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

FileSystem::FileSystem() {
    root = Dir();
    current_dir = root;
}

std::vector<Dir>::iterator FileSystem::findDir(std::string path) {
    auto d = find(current_dir.dirs.begin(), current_dir.dirs.end(), path);
    if (d != current_dir.dirs.end()) {
        return d;
    } else {
        mkdir(path);
        return d;
    }
}

void FileSystem::cd(std::string path) {
    if (path == "/") {
        current_dir = root;
    } else if (path == "..") {
        current_dir = *current_dir.parent;
    } else {
        current_dir = *findDir(path);
    }
}

void FileSystem::ls() {
    for (auto d : current_dir.dirs) {
        std::cout << "dir " << d.name << std::endl;
    }
    for (auto f : current_dir.files) {
        std::cout << f << std::endl;
    }
}

void FileSystem::mkdir(std::string path) {
    Dir new_dir = Dir(path, &current_dir);
    current_dir.dirs.push_back(new_dir);
}

void FileSystem::mkfil(std::string name, int size) {
    File new_file = File(name, size);
    current_dir.files.push_back(new_file);
}

Dir::Dir(std::string name, Dir* parent) {
    this->name = name;
    this->parent = parent;
    files = std::vector<File>();
    dirs = std::vector<Dir>();
}

Dir::Dir() {
    // an empty root directory
    this->name = "/";
    this->parent = this;
    files = std::vector<File>();
    dirs = std::vector<Dir>();
}

Dir::~Dir() {
    // TODO: recursively delete all dirs and files
}

bool Dir::operator==(const std::string& other) { return this->name == other; }