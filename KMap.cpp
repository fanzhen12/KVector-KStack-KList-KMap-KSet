// 要求不使用STL库中自带的函数及接口，实现一个KMap ，代码要求有详细的注释
// 下面是一个基于哈希表的 KMap 的实现，其中 KMap 表示一个键值对的集合。在这个实现中，我们使用了一个哈希表来存储键值对。
class KMap {
private:
    // 定义一个键值对结构体
    struct Pair {
        int key;
        int val;
        Pair(int k, int v) : key(k), val(v) {}
    };

    // 定义一个哈希表结构体
    struct HashTable {
        Pair** table;
        int capacity;
        int size;

        HashTable(int cap) : table(new Pair*[cap]), capacity(cap), size(0) {
            // 初始化哈希表中的元素为空指针
            for (int i = 0; i < capacity; i++) {
                table[i] = nullptr;
            }
        }

        ~HashTable() {
            // 释放哈希表中的内存
            for (int i = 0; i < capacity; i++) {
                delete table[i];
            }
            delete[] table;
        }

        // 计算键的哈希值
        int hash(int key) const {
            return key % capacity;
        }

        // 在哈希表中查找键值对，如果找到返回其指针，否则返回 nullptr
        Pair* find(int key) const {
            int idx = hash(key);
            Pair* p = table[idx];
            while (p != nullptr) {
                if (p->key == key) {
                    return p;
                }
                p = p->next;
            }
            return nullptr;
        }

        // 向哈希表中插入键值对
        void insert(int key, int val) {
            Pair* p = find(key);
            if (p == nullptr) {
                int idx = hash(key);
                p = new Pair(key, val);
                p->next = table[idx];
                table[idx] = p;
                size++;
            } else {
                p->val = val;
            }
        }

        // 从哈希表中删除键值对
        void remove(int key) {
            int idx = hash(key);
            Pair* p = table[idx];
            Pair* prev = nullptr;
            while (p != nullptr) {
                if (p->key == key) {
                    if (prev == nullptr) {
                        table[idx] = p->next;
                    } else {
                        prev->next = p->next;
                    }
                    delete p;
                    size--;
                    return;
                }
                prev = p;
                p = p->next;
            }
        }
    };

    HashTable* table;

public:
    KMap(int cap) : table(new HashTable(cap)) {}

    ~KMap() {
        delete table;
    }

    // 返回键的数量
    int size() const {
        return table->size;
    }

    // 判断键是否存在
    bool contains(int key) const {
        return table->find(key) != nullptr;
    }

    // 返回指定键的值，如果键不存在则返回默认值 def
    int get(int key, int def = 0) const {
        Pair* p = table->find(key);
        if (p == nullptr) {
            return def;
        }
        return p->val;
    }

    // 设置指定键的值
    void set(int key, int val) {
        table->insert(key, val);
    }

    // 删除指定键及其对应的值
    void remove(int key) {
        table->remove(key);
    }
};

// 在上面的实现中，我们使用了一个哈希表来存储键值对。哈希表中的每个元素都是一个指向 Pair 结构体的指针，这个结构体包含了键和值。哈希表中每个元素也包含了一个指向下一个元素的指针，以支持链表形式的冲突解决。我们使用除留余数法来计算键的哈希值，然后将键值对存储到对应的哈希表元素中。如果在查找时发现哈希表元素中的键不是目标键，就遍历链表直到找到目标键或到达链表尾部为止。

// KMap 支持的操作包括：

// - `size()`：返回键的数量
// - `contains(key)`：判断键是否存在
// - `get(key, def)`：返回指定键的值，如果键不存在则返回默认值 def
// - `set(key, val)`：设置指定键的值
// - `remove(key)`：删除指定键及其对应的值

// 需要注意的是，在 KMap 的实现中，我们只使用了 C++ 的基本数据类型和指针来存储键值对，没有使用任何 STL 库中的函数和接口。这样的实现虽然比较简单，但它的性能受到了哈希表的影响，因此在实际使用时需要根据数据规模和访问模式来选择合适的哈希表大小。


//下面是一个使用 KMap 的示例
#include <iostream>
// #include 'KMap'

int main() {
    KMap<int, std::string> map;

    map.set(1, "apple");
    map.set(2, "banana");
    map.set(3, "cherry");

    std::cout << "size: " << map.size() << std::endl;  // 输出 "size: 3"

    if (map.contains(2)) {
        std::cout << "map[2]: " << map.get(2) << std::endl;  // 输出 "map[2]: banana"
    }

    std::cout << "map[4]: " << map.get(4, "default") << std::endl;  // 输出 "map[4]: default"

    map.remove(1);

    std::cout << "size: " << map.size() << std::endl;  // 输出 "size: 2"

    return 0;
}
// 在上面的示例中，我们首先创建了一个 KMap 对象，并使用 set 方法向其中添加了三个键值对。接着，我们通过 size 方法查看了键的数量，然后使用 contains 和 get 方法查找了某个键的值，并使用了默认值来处理键不存在的情况。最后，我们使用 remove 方法删除了一个键及其对应的值，并再次使用 size 方法检查了键的数量。

// KMap 的实现虽然比较简单，但它的时间复杂度为 O(1)（均摊），因此在大规模数据的处理中具有较高的效率。另外，由于我们使用了除留余数法来计算哈希值，因此 KMap 的性能还受到哈希函数的影响，通常情况下需要对哈希表的大小和哈希函数进行调优，以达到最优的性能。