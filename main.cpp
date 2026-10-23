// #include "src/MatrixVectorMultiplication.h"
#include "src/FullM.h"
#include "src/SparseM.h"

int main() 
{
    // std::cout << "Enter matrix file to multiply with unit vector:" << std::endl;
    const std::string fileName = "input/Sparse4.2.txt";
    // std::cin >> fileName;

    std::fstream matrixFile;
    matrixFile.open(fileName, std::ios::in);  
    if(matrixFile.is_open()) 
    {
        // first line is matrix type
        std::string line;
        getline(matrixFile, line);
        if (line == "Full matrix")
        {
            FullM m = FullM(matrixFile);
        }
        else
        {
            SparseM m = SparseM(matrixFile);
        }
    }
    else
    {
        std::cout << "Matrix file not found" << std::endl;
    }
}