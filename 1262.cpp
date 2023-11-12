#include <iostream>
#include <vector>

class Queue {
public:
    void enqueue(int item) {
        items.push_back(item);
    }

    int dequeue() {
        if (!is_empty()) {
            int front = items.front();
            items.erase(items.begin());
            return front;
        }
        return -1;
    }

    bool is_empty() const {
        return items.empty();
    }

private:
    std::vector<int> items;
};

std::vector<int> process_data(const std::vector<int>& data) {
    Queue Q;
    std::vector<int> result;

    for (int number : data) {
        if (number != 0) {
            Q.enqueue(number);
        } else {
            Q.enqueue('*');
        }
    }


    while (!Q.is_empty()) {
        result.push_back(Q.dequeue());
    }

    return result;
}

int main() {
    std::vector<int> data = {5, 7, 12, 4, 0, 4, 6, 8, 67, 34, 23, 5, 0, 44, 33, 22, 6, 0};
    std::vector<int> resulting_queue = process_data(data);


    for (int item : resulting_queue) {
        std::cout << item << " ";
    }

    return 0;
}

