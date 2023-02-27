// 要求不使用STL库中自带的函数及接口，实现一个KDqueue ，代码要求有详细的注释


// 下面是一个基于双向链表的 KDqueue 的实现，其中 KDqueue 代表双端队列。在这个实现中，我们定义了一个节点结构体 Node ，包含 value 和指向前一个和后一个节点的指针
struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};
// 然后我们定义了 KDqueue 类，包含指向队列头尾节点的指针，以及队列中元素的数量。
class KDqueue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    KDqueue() : head(nullptr), tail(nullptr), size(0) {}

    ~KDqueue() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    // 在队头添加元素
    void push_front(int val) {
        Node* new_node = new Node(val);
        if (size == 0) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    // 在队尾添加元素
    void push_back(int val) {
        Node* new_node = new Node(val);
        if (size == 0) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }

    // 在队头删除元素
    void pop_front() {
        if (size == 0) {
            return;
        } else if (size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
        size--;
    }

    // 在队尾删除元素
    void pop_back() {
        if (size == 0) {
            return;
        } else if (size == 1) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
        }
        size--;
    }

    // 返回队头元素的值
    int front() const {
        return head->value;
    }

    // 返回队尾元素的值
    int back() const {
        return tail->value;
    }

    // 返回队列中元素的数量
    int length() const {
        return size;
    }

    // 判断队列是否为空
    bool empty() const {
        return size == 0;
    }
};
// 在这个实现中，我们使用了动态内存分配来创建新节点，因此需要在析构函数中释放这些内存。此外，为了方便起见，我们还实现了一些基本的队列操作，如添加元素、删除元素、返回队列头部和尾部元素、返回队列长度以及判断队列是否为空
// 请注意，这个实现并没有使用 STL 库中自带的函数和接口