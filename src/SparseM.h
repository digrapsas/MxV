#pragma once

#include "MxV.h"

class SparseM : public MxV
{
    private:
        std::vector<size_t> col, elts; // sparse matrix elements in csr
        std::vector<double> val;

    public: 
        SparseM(std::fstream& matrixFile);

    private:
        void Assign(std::fstream& matrixFile) override;
        void CheckSuccess() override;
        void RightProd(const std::vector<double>& inV) override;
};