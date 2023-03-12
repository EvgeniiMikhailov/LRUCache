#include <iostream>
#include "LRUCache.h"

int main()
{
    LRUCache::LRUCache<int, std::string> cache(3);

    cache.Set(1, "one");
    cache.Set(2, "two");
    cache.Set(3, "three");

    std::string result1;
    bool do_get1 = cache.Get(1, result1);
    if (do_get1) {
        std::cout << "Value of key '1': " << result1 << std::endl;
    }else {
        std::cout << "Key '1' was not found in cache" << std::endl;
    }

    cache.Set(4, "four");

    std::string result2;
    bool do_get2 = cache.Get(2, result2);
    if (do_get2) {
        std::cout << "Value of key '2': " << result2 << std::endl;
    } else {
        std::cout << "Key '2' was not found in cache" << std::endl;
    }

    cache.Clear();

    std::string result3;
    bool do_get3 = cache.Get(1, result3);
    if (do_get3) {
        std::cout << "Value of key '1': " << result3 << std::endl;
    }else {
        std::cout << "Key '1' was not found in cache" << std::endl;
    }

    return 0;
}
