#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
namespace sort
{
    int partition(vector<int> &arr, int l, int r)
    {
        int pivot = arr[(l + r) / 2];
        int i = l, j = r;
        while (j > i)
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        return r;
    }
    void quicksort(vector<int> &arr, int l, int r)
    {
        if (r > l)
        {
            int pivot = partition(arr, l, r);
            quicksort(arr, l, pivot - 1);
            quicksort(arr, pivot + 1, r);
        }
    }
} // namespace sort

#ifdef DO_COMPILE_QUICKSORT_MAIN
int main(int argc, char const *argv[])
{
    // string filename(argv[1]);
    // ifstream in(filename);
    vector<int> arr = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    // int num;
    // while (in >> num)
    // {
    //     arr.push_back(num);
    // }
    sort::quicksort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif
