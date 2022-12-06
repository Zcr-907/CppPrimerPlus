#ifndef CPP_DEV_QUEUE_H
#define CPP_DEV_QUEUE_H

// 定义队列中的元素类型
class Customer {
};

typedef Customer Item;

class Queue {
private:
    // 类自定义类型
    enum {
        DEFAULT_SIZE = 10
    };
    struct Node {
        Item item;
        struct Node *next;
    };
    // 类中属性
    int items;          // 队列中的元素数量
    Node *front;        // 队列头部元素
    Node *rear;         // 队列尾部元素
    const int q_size;   // 队列容量大小,声明为常量是为了后期不被修改
    // 类中方法
    // 将默认方法置于私有作用域,这样调用接口方就不能使用这些方法,也不会生成默认复制函数,但是像函数参数仍然可以使用到自定义的这些函数
    // 为什么将qsize置为0,因为目前暂不想提供复制的方法
    Queue(const Queue &q) : q_size(0),front(nullptr),rear(nullptr),items(0) {}
    Queue &operator=(const Queue &q){return *this};

public:
    Queue(int qs = DEFAULT_SIZE);

    ~Queue();

    bool isEmpty() const;

    bool isFull() const;

    int queueCont() const;

    bool poll(const Item &item);

    bool peek(Item& item);

};


#endif //CPP_DEV_QUEUE_H
