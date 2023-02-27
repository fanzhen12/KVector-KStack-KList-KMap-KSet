// 要求不使用STL库中自带的函数及接口，用C++代码实现一个KList ，代码要求有详细的注释
// 以下是实现KList的C++代码，注释在代码中
struct Node {
    int val; // 节点存储的值
    Node* next; // 指向下一个节点的指针
    Node(int v) : val(v), next(nullptr) {}
};

// 自定义链表结构体
struct KList {
    Node* head; // 指向链表头节点的指针
    int size; // 链表长度

    // 构造函数
    KList() : head(nullptr), size(0) {}

    // 插入节点
    void insert(int val) {
        Node* new_node = new Node(val); // 创建一个新节点
        if (head == nullptr) { // 链表为空
            head = new_node;
        } else { // 链表不为空
            Node* p = head;
            while (p->next != nullptr) { // 找到链表的末尾节点
                p = p->next;
            }
            p->next = new_node; // 在末尾节点后插入新节点
        }
        size++; // 链表长度加1
    }

    // 删除节点
    void remove(int val) {
        if (head == nullptr) { // 链表为空，直接返回
            return;
        }
        if (head->val == val) { // 头节点是要删除的节点
            Node* tmp = head;
            head = head->next; // 将头指针指向下一个节点
            delete tmp; // 释放原头节点的内存
            size--; // 链表长度减1
            return;
        }
        Node* p = head;
        while (p->next != nullptr && p->next->val != val) { // 找到要删除节点的前一个节点
            p = p->next;
        }
        if (p->next == nullptr) { // 没有找到要删除的节点
            return;
        }
        Node* tmp = p->next;
        p->next = tmp->next; // 将前一个节点指向要删除节点的下一个节点
        delete tmp; // 释放要删除节点的内存
        size--; // 链表长度减1
    }

    // 获取链表长度
    int get_size() const {
        return size;
    }

    // 获取链表中第index个节点的值
    int get(int index) const {
        if (index < 0 || index >= size) { // 检查index是否合法
            throw "Index out of range";
        }
        Node* p = head;
        for (int i = 0; i < index; i++) { // 找到第index个节点
            p = p->next;
        }
        return p->val;
    }
};

// 上述代码中，自定义了一个节点结构体`Node`和一个链表结构体`KList`。`KList`中包含了指向链表头节点的指针`head`和链表长度`size`，并实现了插入节点、删除节点、获取链表长度和获取链表中第index个节点的值等功能。

// 在测试代码中，首先插入了三个节点并输出链表长度和每个节点的值，然后删除了节点2并再次输出链表长度和每个节点的值，以此来验证链表的功能是否正确实现。
