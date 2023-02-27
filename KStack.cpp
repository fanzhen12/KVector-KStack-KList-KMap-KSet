// 要求不使用STL库中自带的函数及接口，实现一个KStack ，代码要求有详细的注释
// 下面是一个基于数组的 KStack 的实现，其中 KStack 代表普通栈。在这个实现中，我们定义了一个数组 arr 和一个指针 top，分别表示栈的元素和栈顶指针
class KStack {
private:
    int* arr;
    int top;
    int capacity;
    int size;

public:
    KStack(int cap) : arr(new int[cap]), top(-1), capacity(cap), size(0) {}

    ~KStack() {
        delete[] arr;
    }

    // 将元素压入栈顶
    void push(int val) {
        if (size == capacity) {
            return;
        }
        top++;
        arr[top] = val;
        size++;
    }

    // 弹出栈顶元素
    void pop() {
        if (size == 0) {
            return;
        }
        top--;
        size--;
    }

    // 返回栈顶元素
    int peek() const {
        return arr[top];
    }

    // 返回栈中元素的数量
    int length() const {
        return size;
    }

    // 判断栈是否为空
    bool empty() const {
        return size == 0;
    }
};
// 在这个实现中，我们使用了一个数组来实现栈。为了方便起见，我们还实现了一些基本的栈操作，如将元素压入栈顶、弹出栈顶元素、返回栈顶元素、返回栈长度以及判断栈是否为空。
// 请注意，这个实现并没有使用 STL 库中自带的函数和接口，而是使用了动态内存分配来创建数组。






