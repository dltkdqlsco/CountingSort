#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0);

    for (int num : arr)
    {
        count[num]++;
    }

    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        int num = arr[i];
        int position = count[num] - 1;
        output[position] = num;
        count[num]--;
    }

    arr = output;
}

void printVector(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> data = {2, 5, 3, 0, 2, 3, 0, 3};
    cout << "원본 배열: ";
    printVector(data);
    countingSort(data);
    cout << "정렬된 배열: ";
    printVector(data);
}