#include <iostream>


int partition (int x[], int lb, int ub){
    int down, up, a, temp;
    a = x[lb];  // the pivot element
    up = ub;
    down = lb;
    //traverse the array and swap elements
    while (down < up){
        while (x[down] <= a && down < ub)
            down++;
        while (x[up] > a)
            up--;
        if (down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
            }
        }
        x[lb] = x[up];
        x[up] = a;
        //return the index where the pivot is now at
        return up;
    } // end partition

// main qsort method with array, lower and upper bound
void quicksort(int x[], int lb, int ub){
    // lower bound crossed upper bound
    if(lb >= ub) return;

    int j = partition(x, lb, ub);
    // ^^ this function will choose
    // which element to partition
    // around
    quicksort(x, lb, j-1); // quicksort on left of j
    quicksort(x, j+1, ub); // quicksort on the right of j
}

int main(){

    int arr[] = { 43, 66, 10, 56, 78, 88, 93, 58, 36};

    std::cout << "Before quicksort: ";
    for (int x : arr){
        std::cout << x << " ";
    }

    std::cout << std::endl << "After quicksort: ";
    quicksort(arr, 0, 8);
    for(int i : arr){
        std::cout << i << " ";
    }
}

