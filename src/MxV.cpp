#include "MxV.h"

MxV::MxV(std::fstream& matrixFile)
{
    std::string line;
    getline(matrixFile, line);
    
    dim = std::stoi(line);
    unity.resize(dim, 1);
    res.resize(dim, 0);
}

void MxV::PrintRes() const
{
    std::cout << "\nresult = ( ";;
    for (double i : res)
    {
        std::cout << i << " ";
    }
    std::cout << ")^t" << std::endl;

    std::cout << std::endl;
    if (isSuccess)
    {
        std::cout << "Result verified: each element of result is the sum of the elements of the corresponding line of the matrix" << std::endl;
    }
}