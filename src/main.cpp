#include "sort/quicksort.cpp"
#include "sort/mergesort.cpp"
#include <mpi.h>

// namespace fs = std::filesystem;

void parallel_sort(vector<int> &arr, int sortType)
{
    switch (sortType)
    {
    case 1:
        sort::mergesort(arr, 0, arr.size() - 1);
        break;
    case 2:
        sort::quicksort(arr, 0, arr.size() - 1);
    default:
        std::cout << "Error sort type!" << std::endl;
        break;
    }
}

int main(int argc, char **argv)
{
    // fs::path datapath = "../data";
    // datapath /= "random.txt";
    std::vector<int> arr= readData(argv[2]);
    // printf("Original data:\n");
    // printData(arr);
    if (atoi(argv[1]) == 3 || atoi(argv[1]) == 4)
    {
        parallel_sort(arr, atoi(argv[1])-2);
        for (int i = 0; i < arr.size(); i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }
    
    // Initialize MPI
    MPI_Init(&argc, &argv);

    /**
     * size: how many processors in the communicator
     * rank: the current processor rank in the communicator
     */
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // read data from file
    // if (rank == 0)
    // {
    //     arr = readData(datapath);
    //     printData(arr);
    // }
    
    const int n = arr.size();
    int batch_size = n / size;

    // Scatter the array to all processes
    std::vector<int> sub_arr(batch_size);
    
    MPI_Scatter(arr.data(), batch_size, MPI_INT, sub_arr.data(), batch_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Sort the subarray
    parallel_sort(sub_arr, atoi(argv[1]));
    printf("Processor %d out of %d processors\n",
           rank, size);
    // printData(sub_arr);
    printf("sub_arr size: %d\n", sub_arr.size());
    vector<int> sorted(n);
    // Gather the sorted subarrays on process 0
    // int *sorted = NULL;
    // if (rank == 0)
    // {
    //     printf("create sorted array\n");
    //     // sorted = new vector<int>(n);
    //     sorted = new int[n];
    // }
    
    MPI_Gather(sub_arr.data(), batch_size, MPI_INT, sorted.data(), batch_size, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        // printData(sorted);
        // merge remain
        for (int i = 0; i < size; i++)
        {
            sort::merge(sorted, 0, i * batch_size - 1, (i + 1) * batch_size - 1);
        }
        
        printf("This is the sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", sorted[i]);
        }
        printf("\n");
    }
    
    // // clean up the rest
    // delete sorted; 
    // clean up the MPI environment
    MPI_Finalize();
    cout << "end" << endl;
    // printData(arr);
    return 0;
}
