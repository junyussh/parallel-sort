#include <iostream>
#include <vector>
#include <fstream>
int main(int argc, char const *argv[])
{
    const std::string filename(argv[2]);
    std::ofstream out(filename, std::ofstream::trunc);
    const int n = atoi(argv[1]);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        out << rand() << std::endl;
    }
    out.close();
    return 0;
}
