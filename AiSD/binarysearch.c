#include <iostream>



int binarysearch (int * arr, int looked_for, int left, int right){
    int m;
    while (left <= right){
        m = left + (right - left) /2;
        if (arr[m] == looked_for){
            return m;
        }
        if (looked_for < arr[m]){
            right = m - 1;
        }
        else{
            left = m + 1;
        }
    }
    return -1;
}

int main (){
    int arr[] = {-10, -4, -1 , 0 , 5, 7, 10, 12, 17, 20};
    int looked_for = -4;
    int i = binarysearch(arr, looked_for, 0, 10);
    printf ("%d", i);
    return 0;
}
