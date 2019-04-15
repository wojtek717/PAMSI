#include <utility>

#include <utility>

#include "pamsi_tester/Tester.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <numeric>
#include <vector>


// THIS CLASS EXIST ONLY TO OVERRIDE OPERATOR << FOR VECTOR<>
class Matrix : public std::vector<int> {};

// Override << operator
std::ostream &operator<<(std::ostream &output,  Matrix elements){
    for(int i: elements){
        output << i << " ";
    }
    return output;
}

// Stores informations about matriecies
class Matrices{

    int size;   //amount of elements in one matrix

    std::vector<int> matrices; //all elements from matrix A and matrix B

public:
    Matrices(int n, int m, std::vector<int> matrices){

        this->matrices = std::move(matrices);

        this->size = n*m;
    }

    //Add matrix A to matrix B
    Matrix Sum() const{
        Matrix result;

        for (int i = 0; i < size; ++i) {
            result.push_back(matrices[i] + matrices[size + i]);
        }

        return result;
    }
};



class SumMatriciesTester : public Tester<Matrix, Matrices>
{
  protected:
    Matrix runAlgorithm(const Matrices& inputData) override;
    Matrices readSingleInput(std::istream& inputStream) override;
};

Matrix SumMatriciesTester::runAlgorithm(const Matrices& inputData)
{
    //std::vector<int> matriciesElements = std::vector<int>(inputData.begin() + 2, inputData.end());  //cut two first elements
   // Matrices matriecies = Matrices(inputData[0], inputData[1], matriciesElements);

    return inputData.Sum();
}

Matrices SumMatriciesTester::readSingleInput(std::istream& inputStream)
{
    int nSize = 0;
    int mSize = 0;
    int amountOfData = 0;

    inputStream >> nSize;
    inputStream >> mSize;
    amountOfData = 2*nSize*mSize;

    std::vector<int> matricesElements((u_long)amountOfData);


    for(auto i = 0; i < amountOfData; ++i)
    {
        int dataElement;

        inputStream >> dataElement;

        matricesElements.push_back(dataElement);
    }

    Matrices matrices = Matrices(nSize, mSize, matricesElements);

    return matrices;
}

int main(int /*argc*/, char* /*argv*/[])
{
    std::ifstream inputFile{"input.txt"};
    std::ofstream dataOutputFile{"output.txt"}, timeOutputFile{"times.csv"};

    SumMatriciesTester tester;

    if(!inputFile)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }

    tester.runAllTests(inputFile, dataOutputFile, timeOutputFile);
}
