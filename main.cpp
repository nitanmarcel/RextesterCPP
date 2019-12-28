#include <iostream>
#include "rextester.h"
#include <vector>

int main() {
    client::Client client_;

    // std::vector<std::string> res = Result / Errors / Files / Stats
    std::vector<std::string> res = client_.rexec("python 3", "print(input())", "Hello World");
    std::cout << "Result: " << res[0] << std::endl;
    std::cout << "Errors: " << res[1] << std::endl;
    std::cout << "Files: " << res[2] << std::endl;
    std::cout << "Stats: " << res[3] << std::endl;
}
