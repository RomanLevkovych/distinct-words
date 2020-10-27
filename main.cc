#include <iostream>
#include <string>
#include <unordered_set>

int main(int argc, char *argv[]) {
    std::string data;
    std::unordered_set<std::string> components;
    while (std::cin >> data) {
        components.insert(data);
    }
    std::cout << "Size: " << components.size() << std::endl;
    return 0;
}