#include <cstdlib>
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> map;
    std::pair<int, std::string> pair1 (2, "Tere");
    std::pair<int, std::string> pair2 (3, "Taas");
    
    map.insert(pair1);
    map.insert(pair2);

    auto it = map.upper_bound(2);
    std::cout << it->second << "\n";

    for (std::pair<int, std::string> element : map) {
        std::cout << element.first << " : " << element.second << "\n";
    }

    std::multimap<int, std::string> mmap;
    mmap.insert(std::pair<int, std::string> (1, "Tere"));
    mmap.insert(std::pair<int, std::string> (1, "Tere"));
    mmap.insert(std::pair<int, std::string> (3, "Taas"));

    for (auto itm = mmap.begin(); itm != mmap.end(); ++itm) {
        std::cout << "Key : " << itm->first << " , value : " << itm->second << ".\n";
    }

    std::cout << "Size is " << mmap.size() << "\n";

    auto it4 = mmap.find(1);
    std::cout << it4->second << "\n";
    ++it4;
    std::cout << it4->second << "\n";
    ++it4;
    std::cout << it4->second << "\n";

    return 0;
}