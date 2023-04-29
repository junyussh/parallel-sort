#include "sort/quicksort.cpp"
#include <filesystem>
#include "commons.hpp"
namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    fs::path datapath = "../data";
    datapath /= "random.txt";
    
    std::vector<int> arr = readData(datapath);
    sort::quicksort(arr, 0, arr.size()-1);
    printData(arr);
    return 0;
}
