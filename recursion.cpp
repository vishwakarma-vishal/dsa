#include <bits/stdc++.h>
using namespace std;

bool isSorted(int num[], int idx)
{
    // base case
    if (idx == 5)
        return true;

    // recursive call

    if (num[idx] > num[idx + 1])
    {
        return false;
    }
    else
    {
        return isSorted(num, idx + 1);
    }
}

int findSum(int num[], int n, int idx)
{
    // base case
    if (idx == n - 1)
    {
        return num[idx];
    }

    return num[idx] + findSum(num, n, idx + 1);
}

bool findElement(int num[], int n, int ele, int ind) {
    if (ind == n) {
        return false;
    }

    if (num[ind] == ele) {
        return true;
    } else {
        return findElement(num, n, ele, ind + 1);
    }
}

bool findElementBinary(int num[], int low, int high, int ele) {

    // base case
    if (low > high) return false;
    
    //processing
    int mid = (low + high) / 2;
    
    if (num[mid] == ele) {
        return true;
    } 
    
    if (num[mid] > ele){
        return findElementBinary(num, low, mid - 1, ele);
    } 

    return findElementBinary(num, mid + 1, high, ele);
}

void reverseString(string &str, int start, int end){
    // base case 
    if (start > end) {
        return;
    }

    swap(str[start], str[end]);

    reverseString(str, start + 1, end - 1);
}

bool checkPalindrome(string str, int start) {
    int end = str.length() - start - 1;
    // base case
    if (start > end) return true;

    // processing
    if (str[start] != str[end]) return false;
    start++;

    // recursive relation
    return checkPalindrome(str, start);
}

long long findPower(int n, int power) {
    // base case
    if (power == 0) return 1LL;

    // processing and call
    if (power % 2 == 0) {
        return findPower(n, power/2) * findPower(n, power/2);
    } else {
        return n * findPower(n, power/2) * findPower(n, power/2);
    }
} 

void printArray(int num[], int size) {
   
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
} 

void bubbleSort(int *num, int size) {
    //base case
    if (size == 0) return;

    // processing
    int large = num[0];
    int largeInd = 0;
    for (int i = 0; i < size; i++) {
        if(num[i] > large) {
            large = num[i];
            largeInd = i;
        }
    }
    swap(num[largeInd], num[size - 1]);

    // recursive relation
    bubbleSort(num, size -1);
}

void selectionSort(int *num, int idx, int size) {
    // base case 
    if (idx == size - 2) return;

    // processing
    int smallest = num[idx];
    int smallestIdx = idx;
    for (int i = idx; i < size; i++) {
        if (num[i] < smallest) {
            smallest = num[i];
            smallestIdx = i;
        }
    }
    swap(num[smallestIdx], num[idx]);

    // recursive call
    selectionSort(num, idx + 1, size);
}

void insertionSort(int *num, int idx, int size) {
    //base case
    if (idx == size - 1) return;

    //processing
    int j = idx + 1;
    while (j > 0 && num[j - 1] > num[j]) {
        swap(num[j-1], num[j]);
        j--;
    }

    //recursive call
    insertionSort(num, idx + 1, size);
}

int main()
{
    int arr[] = {4, 5, 12, 5, 10, 19};
    
    cout << "Given array-> ";
    printArray(arr, 6);

    insertionSort(arr, 1, 6);
    
    cout << "Sorted array-> ";
    printArray(arr, 6);
}