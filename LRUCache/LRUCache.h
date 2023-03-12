#pragma once

#include <list>
#include <mutex>
#include <unordered_map>

namespace LRUCache {

template<typename K, typename V>
class LRUCache {
public:
    explicit LRUCache(size_t capacity) : capacity_(capacity) {}

    void Set(const K& key, const V& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second.second = value;
            cache_list_.splice(cache_list_.begin(), cache_list_, it->second.first);
        } else {
            cache_list_.emplace_front(key, value);
            cache_[key] = {cache_list_.begin(), value};
        }

        if (cache_.size() > capacity_) {
            auto last = cache_list_.end();
            --last;
            cache_.erase(last->first);
            cache_list_.pop_back();
        }
    }

    bool Get(const K& key, V& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return false;
        }

        value = it->second.second;
        cache_list_.splice(cache_list_.begin(), cache_list_, it->second.first);
        return true;
    }

    void Clear() {
        std::lock_guard<std::mutex> lock(mutex_);
        cache_.clear();
        cache_list_.clear();
    }

private:
    size_t capacity_;
    std::list<std::pair<K, V>> cache_list_;
    std::unordered_map<K, std::pair<typename std::list<std::pair<K, V>>::iterator, V>> cache_;
    std::mutex mutex_;
};

}// namespace LRUCache
