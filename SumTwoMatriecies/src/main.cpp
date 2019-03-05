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
std::ostream &operator<<(std::ostream &wyjscie,  Matrix elements){
    for(int i: elements){
        wyjscie << i << " ";
    }
    return wyjscie;
}

// Stores informations about matriecies
class Matriecies{

    int size;   //amount of elements in one matrix

    std::vector<int> matricies; //all elements from matrix A and matrix B

public:
    Matriecies(int n, int m, std::vector<int> matricies){

        this->matricies = std::move(matricies);

        this->size = n*m;
    }

    //Add matrix A to matrix B
    Matrix Sum(){
        Matrix result;

        for (int i = 0; i < size; ++i) {
            result.push_back(matricies[i] + matricies[size + i]);
        }

        return result;
    }
};



class SumMatriciesTester : public Tester<Matrix, std::vector<int>>
{
  protected:
    Matrix runAlgorithm(const std::vector<int>& inputData) override;
    std::vector<int> readSingleInput(std::istream& inputStream) override;
};

Matrix SumMatriciesTester::runAlgorithm(const std::vector<int>& inputData)
{
    std::vector<int> matriciesElements = std::vector<int>(inputData.begin() + 2, inputData.end());  //cut two first elements
    Matriecies matriecies = Matriecies(inputData[0], inputData[1], matriciesElements);

    return matriecies.Sum();
}

std::vector<int> SumMatriciesTester::readSingleInput(std::istream& inputStream)
{
    int nSize = 0;
    int mSize = 0;
    int amountOfData = 0;

    inputStream >> nSize;
    inputStream >> mSize;
    amountOfData = 2*nSize*mSize;

    std::vector<int> result;

    result.push_back(nSize);
    result.push_back(mSize);


    for(auto i = 0; i < amountOfData; ++i)
    {
        int dataElement;

        inputStream >> dataElement;

        result.push_back(dataElement);
    }

    return result;
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
