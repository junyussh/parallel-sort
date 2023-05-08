#include<fstream>
#include<iostream>
#include<vector>

std::vector<int> readData(std::string filename)
{
    std::ifstream in(filename);
    std::vector<int> arr;
    int num;
    while (in >> num)
    {
        arr.push_back(num);
    }
    in.close();
    printf("there has %d records of data\n", arr.size());
    return arr;
}

void saveData(const std::vector<int> &arr, std::string filename)
{
    std::ofstream out(filename);
    printf("Write output to %s\n", filename.c_str());
    for (int i = 0; i < arr.size(); i++)
    {
        out << arr[i] << std::endl;
    }
}

void printData(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
}