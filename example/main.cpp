#include <iostream>
#include "LRUCache.h"

int main()
{
    LRUCache::LRUCache<std::string, int> cache(3);

    cache.Set("one", 1);
    cache.Set("two", 2);
    cache.Set("three", 3);

    int result1;
    bool do_get1 = cache.Get("one", result1);
    if (do_get1) {
        std::cout << "Value of key 'one': " << result1 << std::endl;
    }else {
        std::cout << "Key 'one' was not found in cache" << std::endl;
    }

    cache.Set("four", 4);

    int result2;
    bool do_get2 = cache.Get("two", result2);
    if (do_get2) {
        std::cout << "Value of key 'two': " << result2 << std::endl;
    } else {
        std::cout << "Key 'two' was not found in cache" << std::endl;
    }

    cache.Clear();

    int result3;
    bool do_get3 = cache.Get("one", result3);
    if (do_get3) {
        std::cout << "Value of key 'one': " << result3 << std::endl;
    }else {
        std::cout << "Key 'one' was not found in cache" << std::endl;
    }

    return 0;
}
