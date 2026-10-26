#include "FullM.h"

FullM::FullM(std::fstream& matrixFile) : MxV(matrixFile)
{
    isFull = true; 
    Assign(matrixFile);
    RightProd(unity);
    CheckSuccess();
    PrintRes();
}

void FullM::Assign(std::fstream& matrixFile)
{
    full.resize(dim*dim);
    
    std::string line;
    size_t iLine = 0;
    while(getline(matrixFile, line))
    {
        std::istringstream iss(line);
        
        for (size_t iCol = 0; iCol < dim; iCol++)
        {
            iss >> full[iLine*dim + iCol];
        }

        iLine++;

        if (iLine == dim)
            std::runtime_error("Input matrx contains more lines than the expected dimensions (" + std::to_string(dim) + ")");
    }

    matrixFile.close();
}


void FullM::CheckSuccess()
{
    size_t iLine = 0;
    while(isSuccess && iLine < dim)
    {
        isSuccess = isSuccess && (res[iLine] == std::accumulate(full.begin() + iLine * dim, full.begin() + (iLine + 1) * dim, 0.0));
        iLine++;
    }
}


void FullM::RightProd(const std::vector<double>& inV)
{
    for (size_t iLine = 0; iLine < dim; iLine++)
    {
        for (size_t iCol = 0; iCol < dim; iCol++)
        {
            res[iLine] += full[iLine * dim + iCol] * inV[iCol];
        }
    }
}