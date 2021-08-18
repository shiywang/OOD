#include <iostream>
#include <string>
#include <vector>
using namespace std;
class File {
 public:
  string name;
  int size;
  int type;
  bool isDirectory;
  vector<File*> children;

  File(const string&name, int size, int type, bool isDirectory=false) {
	this->name = name;
	this->size = size;
	this->type = type;
	this->isDirectory = isDirectory;
  }
  void addChildren(const vector<File*>& children) {
	this->children = children;
  }
};

class Filter {
 public:
  virtual bool apply(const File* file) const = 0;
};

class MinSizeFilter : public Filter {
  int minSize;
 public:
  MinSizeFilter(int minSize) {
	this->minSize = minSize;
  }
  bool apply(const File* file) const {
	return file->size > minSize;
  }
};

class TypeFilter : public Filter {
  int fileType;
 public:
  TypeFilter(int type) {
	this->fileType = type;
  }
  bool apply(const File* file) const {
	return file->type == fileType;
  }
};

class FindCommand {

};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
