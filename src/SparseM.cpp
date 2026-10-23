#include "SparseM.h"




#include<iostream>

SparseM::SparseM(std::fstream& matrixFile) : MxV(matrixFile)
{
    isFull = false;
    Assign(matrixFile);
    RightProd(unity);
    CheckSuccess();
    PrintRes();
}

void SparseM::Assign(std::fstream& matrixFile)
{
    elts.resize(dim + 1, 0);

    int prevLine = 0;
    int totElts = 0; // total number of elements counted
    int iElts = 1; // line number, one-based because always elts[0] = 0

    // values read in file
    int iLine; 
    int iCol; 
    double iVal; 

    std::string line;
    while(getline(matrixFile, line))
    {
        totElts++;
        
        std::istringstream iss(line);
        
        iss >> iLine;
        iLine--; // one-based indexing to zero-based
        if (iLine != prevLine)
        {  
            iElts ++;
            prevLine = iLine;
        }
        elts[iElts] = totElts;

        iss >> iCol;
        iCol--; // one-based indexing to zero-based
        col.push_back(iCol);

        iss >> iVal;
        val.push_back(iVal);
    }

    std::cout << "val = ";
    for (auto value : val)
        std::cout << value << " ";
    std::cout << std::endl;

    std::cout << "col = ";
    for (auto column : col)
        std::cout << column << " ";
    std::cout << std::endl;

    std::cout << "elts = ";
    for (auto element : elts)
        std::cout << element << " ";
    std::cout << std::endl;

    matrixFile.close();
}


void SparseM::CheckSuccess()
{
    size_t iLine = 0;
    while(isSuccess && iLine < dim)
    {
        isSuccess = isSuccess && (res[iLine] == std::accumulate(val.begin() + elts[iLine], val.begin() + elts[iLine + 1], 0));
        iLine++;
    }
}


void SparseM::RightProd(const std::vector<double>& inV)
{
    for (size_t iLine = 0; iLine < dim; iLine++)
    {
        for (size_t iElt = elts[iLine]; iElt < elts[iLine + 1]; iElt++)
        {
            res[iLine] += val[iElt] * inV[col[iElt]];
        }
    }
}