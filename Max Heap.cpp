#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] <= heap[parentIndex]) {
            break;  // Heap property satisfied
        }
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest == index) {
            break;  // Heap property satisfied
        }

        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}

void insert(int heap[], int& size, int value) {
    if (size >= MAX_SIZE) {
        throw std::out_of_range("Heap is full.");
    }

    heap[size] = value;
    heapifyUp(heap, size);
    size++;
}

int extractMax(int heap[], int& size) {
    if (size <= 0) {
        throw std::out_of_range("Heap is empty.");
    }

    int maxValue = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(heap, size, 0);

    return maxValue;
}

int findMax(const int heap[], int size) {
    if (size <= 0) {
        throw std::out_of_range("Heap is empty.");
    }

    return heap[0];
}

int findMin(const int heap[], int size) {
    if (size <= 0) {
        throw std::out_of_range("Heap is empty.");
    }

    int minVal = heap[0];
    for (int i = 1; i < size; i++) {
        if (heap[i] < minVal) {
            minVal = heap[i];
        }
    }

    return minVal;
}

void deleteMin(int heap[], int& size) {
    if (size <= 0) {
        throw std::out_of_range("Heap is empty.");
    }

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(heap, size, 0);
}

void deleteMax(int heap[], int& size) {
    if (size <= 0) {
        throw std::out_of_range("Heap is empty.");
    }

    size--;
    heapifyDown(heap, size, 0);
}

bool empty(int size) {
    return size == 0;
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;

    insert(heap, size, 5);
    insert(heap, size, 10);
    insert(heap, size, 3);
    insert(heap, size, 8);

    std::cout << "Max Value: " << findMax(heap, size) << std::endl;
    std::cout << "Min Value: " << findMin(heap, size) << std::endl;

    deleteMin(heap, size);
    deleteMax(heap, size);

    while (!empty(size)) {
        std::cout << extractMax(heap, size) << " ";
    }
    std::cout << std::endl;

    return 0;
}
