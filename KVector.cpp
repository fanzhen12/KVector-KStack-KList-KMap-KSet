// 以下是一个简单的 KVector 实现，基于数组实现，不使用 STL 库中的函数和接口：
// 下面是一个基于数组的 KVector 的实现，其中 KVector 代表一个可变长度的数组。在这个实现中，我们定义了一个数组 arr、一个整数 capacity 和一个整数 size，分别表示向量的元素、容量和当前大小
class KVector {
private:
    int* arr;
    int capacity;
    int size;

public:
    KVector(int cap) : arr(new int[cap]), capacity(cap), size(0) {}

    ~KVector() {
        delete[] arr;
    }

    // 在向量末尾添加一个元素
    void push_back(int val) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = val;
    }

    // 删除向量末尾的一个元素
    void pop_back() {
        if (size == 0) {
            return;
        }
        size--;
    }

    // 返回向量中指定位置的元素
    int& operator[](int index) {
        return arr[index];
    }

    // 返回向量中指定位置的元素的常引用
    const int& operator[](int index) const {
        return arr[index];
    }

    // 返回向量中元素的数量
    int length() const {
        return size;
    }

    // 返回向量的容量
    int get_capacity() const {
        return capacity;
    }

    // 判断向量是否为空
    bool empty() const {
        return size == 0;
    }

    // 重新调整向量的容量
    void resize(int new_cap) {
        int* new_arr = new int[new_cap];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_cap;
    }
};
// 在这个实现中，我们使用了一个动态分配的数组来存储向量。为了方便起见，我们还实现了一些基本的向量操作，如在向量末尾添加一个元素、删除向量末尾的一个元素、返回向量中指定位置的元素、返回向量中元素的数量和容量以及判断向量是否为空。我们还实现了一个 resize 函数，用于重新调整向量的容量。

// 请注意，这个实现并没有使用 STL 库中自带的函数和接口，而是使用了动态内存分配来创建数组。
// 以上实现是一个简单的 KVector，其基于数组实现，容量不足时会进行扩容，其时间复杂度为 O(1)。如果需要使用线程安全的 KVector，需要加入适当的线程安全措施。此外，上述代码也没有对拷贝构造函数和赋值操作符进行定义，如果需要使用拷贝构造函数或者赋值操作符，还需要对其进行适当的定义。