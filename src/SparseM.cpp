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

    size_t prevLine = 0;
    size_t totElts = 0; // total number of elements counted
    size_t iElts = 1; // line number, one-based because always elts[0] = 0

    // values read in file
    size_t iLine; 
    size_t iCol; 
    double iVal; 

    std::string line;
    while(getline(matrixFile, line))
    {
        // Verify that the line contains 3 values 
        std::istringstream iss(line);
        if (!(iss >> iLine >> iCol >> iVal))
            throw std::runtime_error("Invalid matrix entry");

        if (iLine < 1 || iLine > dim || iCol < 1 || iCol > dim)
            throw std::runtime_error("Index out of bounds at line #{}" + std::to_string(iLine));

        iLine--; // one-based indexing to zero-based

        if (iLine < prevLine)
            throw std::runtime_error("Input values are expected in ascending line order, error in line #" + std::to_string(iElts + 3));
        
        // treat intermediate lines not containing any elements
        while (prevLine < iLine)
        {
            iElts++;
            elts[iElts] = totElts;
            prevLine++;
        }

        // reached the line of the current element, increase total elements and add it to the line
        totElts++;
        elts[iElts] = totElts;

        iCol--; // one-based indexing to zero-based
        col.push_back(iCol);

        val.push_back(iVal);
    }

    // treat trailing lines with no elements (absent from the input file)
    while (iElts < dim)
    {
        iElts++;
        elts[iElts] = totElts;
    }

    matrixFile.close();
}


void SparseM::CheckSuccess()
{
    size_t iLine = 0;
    while(isSuccess && iLine < dim)
    {
        isSuccess = isSuccess && (res[iLine] == std::accumulate(val.begin() + elts[iLine], val.begin() + elts[iLine + 1], 0.0));
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