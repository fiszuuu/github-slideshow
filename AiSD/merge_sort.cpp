#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define N 10

int tmp_arr[N];

// void  merge (int *arr, int left, int middle, int right)
// {
//     int i = left, j = middle+1, k;

//     for (k=left; k <= right; ++k)
//     {
//         if (i <= middle)
//         {
//             if (j <= right)
//             {
//                 if (arr[i]>=arr[j])
//                 {
//                     tmp_arr[k] = arr[j];
//                     j++;
//                 }
//                 else
//                 {
//                     tmp_arr[k] = arr[i];
//                     i++;
//                 }
//             }
//             else
//             {
//                 tmp_arr[k] = arr[i];
//                 i++;
//             }
//         }
//         else
//         {
//             tmp_arr[k] = arr[j];
//             j++;
//         }
//     }
//     for (k=0; k <= right; ++k)
//     {
//         arr[k] = tmp_arr[k];
//     }  
// }

void merge (int arr[], int left, int middle, int right){
    int i = left; int j = middle +1;
    for (int k = left; k < right +1; ++k){ // czy na pewno +1
        if (i <= middle){
            if (j <= right){
                if (arr[j] > arr[i]){
                    tmp_arr[k] = arr[i];
                    i++;
                }
                else {
                    tmp_arr[k] = arr[j];
                    j++;
                }
            }   
            else {
                tmp_arr[k] = arr[i];
                i++;
            }
        }
        else {
            tmp_arr[k] = arr[j];
            j++;
        }
    }
    
    for (int k = left; k < right +1; ++k){
        arr[k] = tmp_arr[k];
    }

}
void merge_sort (int arr[N], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = (right + left)/2;

    merge_sort (arr, left, middle);
    merge_sort (arr, middle+1, right);

    merge (arr, left, middle, right);
}
void print_arr(int arr[N])
{
    for (int i=0; i<N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main ()
{
    int arr[N];
    srand(time(NULL));
    for (int i=0; i<N; i++)
    {
        arr[i] = rand()%50 + 1;
    }
    print_arr(arr);
    merge_sort(arr, 0, N-1);
    print_arr(arr);
    return 0;
}