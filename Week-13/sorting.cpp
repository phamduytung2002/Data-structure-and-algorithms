#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
int arr[maxn], n;

void insertionSort() {
    // O(n^2) so sanh va gan
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i], pos = i - 1;
        while (pos >= 0 && tmp < arr[pos]) {
            arr[pos + 1] = arr[pos];
            --pos;
        }
        arr[pos + 1] = tmp;
    }
}

void selectionSort() {
    // O(n^2) so sanh, O(n) phep doi cho
    for (int i = 0; i < n - 1; ++i) {
        int minval = arr[i], minid = i;
        for (int j = i; j < n; ++j) {
            if (arr[j] < minval) {
                minval = arr[j];
                minid = j;
            }
        }
        // (a, b) -> (a xor b, b) -> (a xor b, b xor (a xor b))
        // = (a xor b, a) -> (b, a)
        // sai khi a va b la cung 1 bien va a, b khong la so nguyen
        if (i != minid) {
            arr[i] ^= arr[minid];
            arr[minid] ^= arr[i];
            arr[i] ^= arr[minid];
        }
    }
}

void bubbleSort() {
    //  O(n^2) doi cho, O(n^2) so sanh, bestcase O(n)
    int tmp;
    for (int i = n - 1; i >= 0; --i) {
        bool noSwap(true);
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                noSwap = false;
            }
        }
        if (noSwap) return;
    }
}

int tmparr[maxn];
void mergeSort(int l, int r) {  //[l, r)
    if (l >= r - 1) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid, r);
    int cur = l, lcur = l, rcur = mid;
    while (cur < r) {  // merge
        if (lcur == mid) {
            tmparr[cur++] = arr[rcur++];
        } else if (rcur == r) {
            tmparr[cur++] = arr[lcur++];
        } else {
            if (arr[lcur] < arr[rcur]) {
                tmparr[cur++] = arr[lcur++];
            } else
                tmparr[cur++] = arr[rcur++];
        }
    }
    for (int i = l; i < r; ++i) arr[i] = tmparr[i];
}

void mergeSortt() {
    mergeSort(0, n);
}

void quickSort(int l, int r) {  //[l,r)
    if (l >= r - 1) return;
    function<int()> partition = [=]() {
        int pivot = arr[l];
        int lcur = l + 1, rcur = r - 1;
        while (true) {
            while (lcur < r - 1 && arr[lcur] <= pivot) ++lcur;
            while (rcur > l && arr[rcur] >= pivot) --rcur;
            if (lcur >= rcur) break;
            swap(arr[lcur], arr[rcur]);
        }
        swap(arr[l], arr[rcur]);
        return rcur;
    };
    int idPivot = partition();
    quickSort(l, idPivot);
    quickSort(idPivot + 1, r);
}

void quickSortt() {
    quickSort(0, n);
}

void maxHeapify(int i, int n) {  // 0-based index
    arr[maxn - 1] = INT_MIN;
    if (i >= n / 2) return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= n) left = maxn - 1;
    if (right >= n) right = maxn - 1;
    int idMax, Max;
    if (arr[left] > arr[right]) {
        idMax = left;
        Max = arr[left];
    } else {
        idMax = right;
        Max = arr[right];
    }
    if (Max > arr[i]) {
        swap(arr[i], arr[idMax]);
        maxHeapify(idMax, n);
    }
}

void buildHeap() {
    for (int i = n / 2 - 1; i >= 0; --i) maxHeapify(i, n);
}

void heapSort() {
    buildHeap();
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        maxHeapify(0, i);
    }
}

// some addition function for testing
bool check(function<void()> sortFunc) {
    int c[n];
    copy(arr, arr + n, c);
    sort(c, c + n);
    sortFunc();
    for (int i = 0; i < n; ++i)
        if (arr[i] != c[i]) {
            return false;
        }
    return true;
}

void testgen() {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 2000 - 1000;
    }
}

bool testNTimes(int N, function<void()> sortFunc) {
    for (int i = 0; i < N; ++i) {
        testgen();
        if (!check(sortFunc))
            return false;
    }
    return true;
}

int main() {
    srand(time(NULL));
    n = 2000;
    int N = 1000;
    if (testNTimes(N, insertionSort)) cout << "Insertion sort is correct\n";
    if (testNTimes(N, selectionSort)) cout << "Selection Sort is correct\n";
    if (testNTimes(N, bubbleSort)) cout << "Bubble sort is correct\n";
    if (testNTimes(N, mergeSortt)) cout << "Merge sort is correct\n";
    if (testNTimes(N, quickSortt)) cout << "Quick sort is correct\n";
    if (testNTimes(N, heapSort)) cout << "Heap sort is correct\n";
}