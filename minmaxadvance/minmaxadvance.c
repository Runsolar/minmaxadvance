/*
minmaxadvance.c
This is an implementation of the MinMax like of the sorting algorithm which mixed with the bubble sort. 
It is just a main idea, you might it change as you like ;).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//For tests
#define SIZE 20

void minmaxadvance(int* array, int size) {
    int k = 0;
    bool isSort = true;

/* Uncomment it below if you wanna more fast but it takes O(N) of memmory. */
/*
    int *tmparray = (int *)malloc(size * sizeof(int));
    memcpy(tmparray, array, size * sizeof(int));
    memset(array, 0, size * sizeof(int));

    int sum = 0;
    double average;
    for (int i = 0; i < size; i++) {
        sum += tmparray[i];
    }

    average = sum / size;
    int m = 0;

    for (int i = 0; i < size; i++) {
        if (tmparray[i] < average) {
            array[m] = tmparray[i];
            ++m;
        }
    }

    for (int i = 0; i < size; i++) {
        if (tmparray[i] >= average) {
            array[m] = tmparray[i];
            ++m;
        }
    }

    printf("average = %f\n", average);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
*/

    while (isSort) {
        int sum = 0;
        int indexOfMin = k;
        int indexOfMax = k;
        int minElement = array[k];
        int maxElement = array[k];

        for (int i = k; i < size - k; ++i)
        {
            if (i < size - k - 1) {
                if (array[i] > array[i + 1]) {
                    int tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }

            if (maxElement <= array[i]) {
                indexOfMax = i;
                maxElement = array[i];
            }

            if (minElement >= array[i]) {
                indexOfMin = i;
                minElement = array[i];
            }
        }

        ++k;

        printf("k=%d\n", k);

        int tempMaxElement = array[size - k];
        array[size - k] = maxElement;
        array[indexOfMax] = tempMaxElement;

        if (indexOfMin != size - k) {
            int tempMinElement = array[k - 1];
            array[k - 1] = minElement;
            array[indexOfMin] = tempMinElement;
        }
        else {
            int tempMinBreemElement = array[k - 1];
            array[k - 1] = array[indexOfMax];
            array[indexOfMax] = tempMinBreemElement;
        }

        for (int i = k; i < size - k; i++) {
            if (array[i] > array[i + 1])
            {
                ++sum;
            }
        }

        if (sum == 0) { isSort = false; }

        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    //free(tmparray);
}

int main()
{
    //Some tests
    int arr1[] = { 20, 5, 15, 17, 8, 15, 4, 3, 6, 12 }; //10
    int arr2[] = { 20, 5, 15, 17, 8, 15, 4, 3, 6, 12, 21, 30, 1, 2, 3, 5, 1, 3, 0, 7 }; //20
    int arr3[] = { 2, 10, 8, 4, 6, 5, 7, 3, 9, 1 };
    int arr4[] = { 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
    int arr5[] = { 5, 2, 3, 4, 1, 10, 7, 8, 9, 6 };

    minmaxadvance(arr2, SIZE);
}