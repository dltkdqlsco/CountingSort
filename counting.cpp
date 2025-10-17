#include <iostream>

using namespace std;

void counting_sort(int *arr, int size)
{
    int *counting, *sorted;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    counting = new int[max + 1]{0};
    sorted = new int[size]{0};

    // cout << "counting arr" << endl;
    for (int i = 0; i < size; i++)
    {
        counting[arr[i]]++;
    }
    // for (int i = 0; i <= max; i++)
    // {
    //     cout << counting[i] << " ";
    // }
    // cout << endl;

    // cout << "counting sum" << endl;
    for (int i = 1; i <= max; i++)
    {
        counting[i] += counting[i - 1];
    }
    // for (int i = 0; i <= max; i++)
    // {
    //     cout << counting[i] << " ";
    // }

    for (int i = 0; i < size; i++)
    {
        sorted[counting[arr[i]] - 1] = arr[i];
        counting[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = sorted[i];
    }

    delete[] counting;
    delete[] sorted;
}

int main(void)
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 5, 7, 6};

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    counting_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}