#pragma once

#include "MxV.h"

class FullM : public MxV
{
    private:
        std::vector<double> full; // matrix elements

    public: 
        FullM(std::fstream& matrixFile);

    private: 
        void Assign(std::fstream& matrixFile) override;
        void CheckSuccess() override;
        void RightProd(const std::vector<double>& inV) override;
};