// 要求不使用STL库中自带的函数及接口，实现一个KSet ，代码要求有详细的注释
// 下面是一个简单的 KSet 实现，它可以存储任意类型的元素，并提供了基本的集合操作
template<typename T>
class KSet {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head;

public:
    KSet() : head(nullptr) {}

    ~KSet() {
        clear();
    }

    // 向集合中添加一个元素
    void add(const T& value) {
        // 如果元素已经存在，就不再添加
        if (contains(value)) {
            return;
        }

        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    // 从集合中移除一个元素
    void remove(const T& value) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->value == value) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // 判断集合中是否包含一个元素
    bool contains(const T& value) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // 返回集合中元素的数量
    int size() const {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // 清空集合中的所有元素
    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = nullptr;
    }
};
// 在上面的实现中，我们使用一个单向链表来存储集合中的元素。链表的每个节点都包含了一个元素值和指向下一个节点的指针。在添加元素时，我们首先检查元素是否已经存在于集合中，如果存在就不再添加；否则，就创建一个新节点并将其插入到链表的头部。在移除元素时，我们遍历链表查找指定的元素，并将其从链表中删除。在判断元素是否存在时，我们同样遍历链表并逐个比较元素的值。在计算集合大小时，我们遍历链表并统计节点的数量。在清空集合时，我们遍历链表并释放每个节点的内存，最后将头指针置空。

// KSet 支持的操作包括：

// add(value)：向集合中添加一个元素
// remove(value)：从集合中移除一个元素
// contains(value)：判断集合中是否包含一个元素
// size()：返回集合中元素的数量
// clear()：清除集合中的所有元素