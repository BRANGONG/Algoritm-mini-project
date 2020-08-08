#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<chrono>

using namespace std;

void swap(unsigned long long *xp, unsigned long long *yp)
{
    unsigned long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(unsigned long long arr[], unsigned long long n)
{
    unsigned long long i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

void selectionSort(unsigned long long arr[], unsigned long long n)
{
    unsigned long long i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


void insertionSort(unsigned long long arr[], unsigned long long n)
{
    unsigned long long i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(unsigned long long arr[], unsigned long long l, unsigned long long m, unsigned long long r)
{
    unsigned long long i, j, k;
    unsigned long long n1 = m - l + 1;
   unsigned long long n2 = r - m;

    unsigned long long L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(unsigned long long arr[], unsigned long long l, unsigned long long r)
{
    if (l < r) {
       unsigned long long m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void heapify(unsigned long long arr[], unsigned long long n, unsigned long long i)
{
    unsigned long long largest = i;
    unsigned long long l = 2*i + 1;
    unsigned long long r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(unsigned long long arr[], unsigned long long n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
int partition (unsigned long long arr[], unsigned long long low, unsigned long long high)
{
 	unsigned long long pivot = arr[high];
    unsigned long long i = (low - 1);

    for (unsigned long long j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(unsigned long long arr[], unsigned long long low, unsigned long long high)
{
    if (low < high)
    {
        unsigned long long pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    using namespace std::chrono;

    unsigned long long size;
    cout<<"Enter the size of the array    :";
    cin>>size;

    unsigned long long arr_1[size], arr_2[size], arr_3[size], arr_4[size], arr_5[size], arr_6[size];

    unsigned long long x = pow(size, 6);
    cout<<x<<endl;

    for(int i=0; i<size;i++)
    {
        arr_1[i] = arr_2[i] = arr_3[i] = arr_4[i] = arr_5[i] = arr_6[i]  =(rand() % x)+1;
    }

    auto start = high_resolution_clock::now();
    bubbleSort(arr_1, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for Bubble sort:";
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    selectionSort(arr_2, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for selection sort:";
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    insertionSort(arr_3, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for insertion sort:";
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    mergeSort(arr_4, 0, size-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for Merge sort:";
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    heapSort(arr_5, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for Heap sort:";
    cout << duration.count() << endl;

    start = high_resolution_clock::now();
    quickSort(arr_6, 0, size - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken for Quick sort:";
    cout << duration.count() << endl;


    return 0;
}
