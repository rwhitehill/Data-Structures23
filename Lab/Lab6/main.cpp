#include <iostream>
#include <stack>

template <typename T>
class MyQueue {
private:
    std::stack<T> queue;
    std::stack<T> temp_storage;

public:
    MyQueue() = default;

    void enqueue(T t) {
        while (!queue.empty()) {
            T temp_val = queue.top();
            queue.pop();
            temp_storage.push(temp_val);
        }

        queue.push(t);

        while (!temp_storage.empty()) {
            T temp_val = temp_storage.top();
            temp_storage.pop();
            queue.push(temp_val);
        }
    }

    void dequeue() { queue.pop(); }
    T& head() { return queue.top(); }
    const T& head() const { return queue.top(); }
    bool empty() { return queue.empty(); } 
    bool full() { return false; } // What does this mean?
    int size() { return queue.size(); }
};

int main()
{

    MyQueue<int> mqi;
    for (auto i : { 1,2,3,4,5 }) {
        mqi.enqueue(i);
    }

    while (!mqi.empty()) {
        std::cout << mqi.head() << " ";
        mqi.dequeue();
    }
    std::cout << std::endl;

    return 0;
}
