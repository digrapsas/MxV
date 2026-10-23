#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>
#include <numeric>

class MxV
{
    protected:
        // class attributes
        size_t dim; // dimension
        std::vector<double> unity; // will get a unity vector of dimension dim
        std::vector<double> res; // will get the result of the multiplication
        
        bool isSuccess = true; // was the calculation successfully verified?
        bool isFull; // is the matrix full?
        
    protected:
        // constructor
        MxV(std::fstream& matrixFile);

        // class methods
        void PrintRes() const;

        // virtual methods
        virtual ~MxV(){};

        virtual void Assign(std::fstream& matrixFile) = 0; 
        virtual void CheckSuccess() = 0;
        virtual void RightProd(const std::vector<double>& inV) = 0;
};