
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

struct AbstractFileGetter {
public:
  virtual std::vector<std::string> getLines(const std::string &path) = 0;
};

struct FileGetter : public AbstractFileGetter {
public:
  std::vector<std::string> getLines(const std::string &path) {
    std::fstream fs;

    fs.open(path, std::ios::in);

    std::vector<std::string> lines = std::vector<std::string>();

    std::string temp;
    std::string line;

    while (fs >> temp) {
      getline(fs, line);
      lines.push_back(line);
    }
    std::move(lines);
    return lines;
  }
};

struct MockFileGetter : AbstractFileGetter {
public:
  std::vector<std::string> getLines(const std::string &_) {
    std::vector<std::string> ret = {"one", "two", "three"};
    std::move(ret);
    return ret;
  }
};

int countLines(AbstractFileGetter *fileGetter, const std::string &path) {
  auto lines = fileGetter->getLines(path);

  for (auto l : lines) {
    std::cout << l << std::endl;
  }
  return lines.size();
}

void test() {

  int len = countLines(new MockFileGetter(), "fake/index.html");

  if (len == 3) {
    std::cout << "yay" << std::endl;
  } else {
    std::cout << "boo" << std::endl;
  }
}

int main() {}
