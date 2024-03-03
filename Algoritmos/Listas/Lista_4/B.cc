#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(vector<int>& heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(vector<int>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

int extractMin(vector<int>& heap) {
    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    minHeapify(heap, 0);
    return root;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> minHeap;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            minHeap.push_back(num);
        }

        buildMinHeap(minHeap);

        int totalCost = 0;
        while (minHeap.size() > 1) {
            int num1 = extractMin(minHeap);
            int num2 = extractMin(minHeap);
            int sum = num1 + num2;
            totalCost += sum;
            minHeap.push_back(sum);
            minHeapify(minHeap, minHeap.size() - 1);
        }

        cout << totalCost << endl;
    }

    return 0;
}
/*Sample Input
3
1 2 3
4
1 2 3 4
0
Sample Output
9
19*/