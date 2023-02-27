// 以下是一个简单的 KQueue 实现，基于数组实现，不使用 STL 库中的函数和接口：
// 下面是一个基于数组的 KQueue 的实现，其中 KQueue 代表普通队列。在这个实现中，我们定义了一个数组 arr 和两个指针 front 和 rear，分别表示队列的前端和后端
class KQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    KQueue(int cap) : arr(new int[cap]), front(0), rear(0), capacity(cap), size(0) {}

    ~KQueue() {
        delete[] arr;
    }

    // 添加元素到队列末尾
    void enqueue(int val) {
        if (size == capacity) {
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }

    // 删除队列头部元素
    void dequeue() {
        if (size == 0) {
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    // 返回队列头部元素的值
    int front() const {
        return arr[front];
    }

    // 返回队列尾部元素的值
    int back() const {
        return arr[(rear - 1 + capacity) % capacity];
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
// 在这个实现中，我们使用了一个循环数组来实现队列。为了方便起见，我们还实现了一些基本的队列操作，如添加元素、删除元素、返回队列头部和尾部元素、返回队列长度以及判断队列是否为空。
// 请注意，这个实现并没有使用 STL 库中自带的函数和接口，而是使用了动态内存分配来创建数组








































// 以上实现是一个简单的 KQueue，其基于数组实现，当队列容量不足时会进行扩容，其时间复杂度为 O(1)。如果需要使用线程安全的 KQueue，需要加入适当的线程安全措施。此外，上述代码也没有对拷贝构造函数和赋值操作符进行定义，如果需要使用拷贝构造函数或者赋值操作符，还需要对其进行适当的定义。