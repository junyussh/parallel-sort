#include <vector>
#include "../commons.hpp"

using namespace std;
namespace sort
{
    void merge(vector<int> &arr, int l, int mid, int r)
    {
        const int n1 = mid - l + 1, n2 = r - mid;
        // Create temporary arrays
        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            R[i] = arr[mid + 1 + i];
        }

        // Merge the temporary arrays back into arr[l..r]
        int idxLeft = 0, idxRight = 0, idx = l;
        while (idxLeft < n1 && idxRight < n2)
        {
            if (L[idxLeft] < R[idxRight])
            {
                arr[idx] = L[idxLeft];
                idxLeft++;
            }
            else
            {
                arr[idx] = R[idxRight];
                idxRight++;
            }
            idx++;
        }

        // Copy the remaining elements of L[], if there are any
        while (idxLeft < n1)
        {
            arr[idx] = L[idxLeft];
            idx++;
            idxLeft++;
        }

        // Copy the remaining elements of R[], if there are any
        while (idxRight < n2)
        {
            arr[idx] = R[idxRight];
            idx++;
            idxRight++;
        }
    }
    void mergesort(vector<int> &arr, int l, int r)
    {
        if (r > l)
        {
            int mid = (l + r) / 2;
            mergesort(arr, l, mid);
            mergesort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
}

#ifdef DO_COMPILE_MERGESORT_MAIN
int main(int argc, char const *argv[])
{
    vector<int> arr = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    sort::mergesort(arr, 0, arr.size()-1);
    printData(arr);
    return 0;
}
#endif
