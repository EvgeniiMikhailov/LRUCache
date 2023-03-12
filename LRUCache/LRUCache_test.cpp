#include "LRUCache.h"
#include <gtest/gtest.h>
#include <thread>

TEST(LRUCacheTest, SetAndGet) {
    LRUCache::LRUCache<int, std::string> cache(2);
    cache.Set(1, "one");
    cache.Set(2, "two");
    std::string value;
    EXPECT_TRUE(cache.Get(1, value));
    EXPECT_EQ(value, "one");
    EXPECT_TRUE(cache.Get(2, value));
    EXPECT_EQ(value, "two");
}

TEST(LRUCacheTest, SetWithEviction) {
    LRUCache::LRUCache<int, std::string> cache(2);
    cache.Set(1, "one");
    cache.Set(2, "two");
    cache.Set(3, "three");
    std::string value;
    EXPECT_FALSE(cache.Get(1, value));
    EXPECT_TRUE(cache.Get(2, value));
    EXPECT_EQ(value, "two");
    EXPECT_TRUE(cache.Get(3, value));
    EXPECT_EQ(value, "three");
}

TEST(LRUCacheTest, GetNonexistentKey) {
    LRUCache::LRUCache<int, std::string> cache(2);
    std::string value;
    EXPECT_FALSE(cache.Get(1, value));
}

TEST(LRUCacheTest, Clear) {
    LRUCache::LRUCache<int, std::string> cache(2);
    cache.Set(1, "one");
    cache.Set(2, "two");
    cache.Clear();
    std::string value;
    EXPECT_FALSE(cache.Get(1, value));
    EXPECT_FALSE(cache.Get(2, value));
}

TEST(LRUCacheTest, ThreadSafetyTest) {
    const int THREAD_COUNT = 10;
    const int OPERATIONS_PER_THREAD = 100000;

    LRUCache::LRUCache<int, int> cache(100);

    std::vector<std::thread> threads;

    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back([&]() {
            for (int j = 0; j < OPERATIONS_PER_THREAD; ++j) {
                int key = rand() % 1000;
                if (rand() % 2 == 0) {
                    int value = rand();
                    cache.Set(key, value);
                } else {
                    int value;
                    cache.Get(key, value);
                }
            }
        });
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i].join();
    }

    int item_count = 0;
    int value;
    for (int i = 0; i < 1000; ++i) {
        if (cache.Get(i, value)) {
            item_count++;
        }
    }
    EXPECT_LE(item_count, 100);
}
