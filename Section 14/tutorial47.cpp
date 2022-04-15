#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(1);
    stack.push(5);

    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "\n\n";

    std::queue<int> queue;
    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(6);

    queue.front() = 11;

    while (!queue.empty()) {
        printf("First element is %d, and last element is %d.\n", queue.front(), queue.back());
        queue.pop();
    }

    std::cout << "\n";

    std::priority_queue<int> pqueue;
    pqueue.push(1);
    pqueue.push(5);
    pqueue.push(3);
    pqueue.push(7);
    pqueue.push(2);

    while (!pqueue.empty()) {
        std::cout << pqueue.top() << " ";
        pqueue.pop();
    }
    std::cout << "\n";

    enum day {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    std::cout << day::Thursday << "\n";

    return 0;
}