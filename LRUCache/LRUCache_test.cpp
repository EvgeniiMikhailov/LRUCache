#include "LRUCache.h"
#include <gtest/gtest.h>

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
