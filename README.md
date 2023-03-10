# LRU Cache
LRUCache - это шаблонный класс, реализующий LRU-кэш (Least Recently Used cache) для хранения пар ключ-значение. Кэш имеет ограниченную ёмкость, которая задается при создании объекта класса. При добавлении нового элемента в кэш, если его размер превышает ёмкость, то удаляется элемент, который дольше всего не использовался.

## Использование:

1. Включить заголовочный файл "LRUCache.h"
2. Создать объект класса LRUCache, указав ёмкость кэша
3. Добавлять элементы в кэш методом Set()
4. Извлекать элементы из кэша методом Get()
5. Очищать кэш методом Clear()

## Пример использования:

```cpp
#include "LRUCache.h"

int main() {
    LRUCache::LRUCache<int, std::string> cache(2);
    cache.Set(1, "value1");
    cache.Set(2, "value2");
    cache.Set(3, "value3"); // вытесняется элемент 1
    std::string value;
    bool success = cache.Get(1, value); // неудача, элемент 1 был удален
    success = cache.Get(2, value); // успех, значение value равно "value2"
    return 0;
}
```

Вы можете найти подробный пример использования в [файле](example/main.cpp).
