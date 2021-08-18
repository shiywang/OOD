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
	void findWithFilters(const File* directory, const vector<Filter*> &filters, vector<File*> &output) {
	  if(directory->children.empty()) {
	    return;
	  }
	  for(const auto &file : directory->children) {
	    if(file->isDirectory) {
		  findWithFilters(file, filters, output);
	    } else {
	      bool selectFile = false;
	      for(const auto &f : filters) {
	        if(f->apply(file)) {
	          selectFile = true;
	          break;
	        }
	      }
	      if(selectFile) {
	        output.push_back(file);
	      }
	    }
	  }
	}
 public:
  vector<File*> findWithFilters(const File* directory, const vector<Filter*> &filters) {
	if (!directory->isDirectory) {
	  cout<<"Exception"<<endl;
	  return {};
	}
	vector<File*> output;
	findWithFilters(directory, filters, output);
	return output;
  }
};
int main() {
  FindCommand fc;
  File f1("1", 100, 1, false);
  File f2("2", 1, 2, false);
  File f3("3", 200, 1, false);
  File f4("4", 2, 100, false);
  File f("5", 0, 0, true);
  f.addChildren({&f1,&f2, &f3, &f4});

  MinSizeFilter filter1(99);
  TypeFilter filter2(2);
  for(auto fff : fc.findWithFilters(&f, {&filter1, &filter2})) {
    cout << fff->name << endl;
  }
  return 0;
}
