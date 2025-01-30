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

int main()
{
    string str = "amana";

    if(checkPalindrome(str, 0)) {
        cout << "String is palindrome";
    } else {
        cout << "String is not palindrome";
    }
}