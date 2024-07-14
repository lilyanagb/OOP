
#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
    setName(name);
}

void TestSuite::add(const TestCase& newTest)
{
    testCase.insert(testCase.end(), newTest);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
    std::vector<TestCase> filter;
    int length = testCase.size();
    for (int i = 0; i < length; i++) {
        if (testCase[i].isPassing()) {
            filter.push_back(testCase[i]);
        }
    }
    return filter;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
    std::vector<TestCase> filter;
    int length = testCase.size();
    for (int i = 0; i < length; i++) {
        if (testCase[i].hasError()){
            filter.push_back(testCase[i]);
        }
    }
    return filter;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType error) const
{
    std::vector<TestCase> filter;
    int length = testCase.size();
    for (int i = 0; i < length; i++) {
        if (testCase[i].getErrorType() == error) {
            filter.push_back(testCase[i]);
        }
    }
    return filter;
}

void TestSuite::removeByErrorType(ErrorType error)
{
    int length = testCase.size();
    for (int i = 0; i < length; i++) {
        if (testCase[i].getErrorType() == error) {
            testCase.erase(testCase.begin() + i);
        }
    }
}

std::string TestSuite::getName() const
{
    return name;
}

void TestSuite::setName(const std::string& name)
{
    this->name = name;
}
