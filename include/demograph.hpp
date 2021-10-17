/*
** EPITECH PROJECT, 2021
** demography
** File description:
** demograph
*/

#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

#define cErr(message) std::cerr << message << std::endl;
#define cOut(message) std::cout << message << std::endl;
#define cOutn(message) std::cout << message;

#define _ _coords

#define uraise(message) ({ \
    cErr(message); \
    std::exit(84); \
})

#define toDouble(v) ({ \
    std::stringstream ss; \
    double tmp; \
    ss << std::string{v}; \
    ss >> tmp; \
    tmp; \
})

#define calcOfB() ((_valList.size() * _.xy - _.xi * _.yi) / (_valList.size() * (first ? _.x2 : _.y2) - pow(first ? _.xi : _.yi, 2)))
#define calcOfA() (((1.0 / _valList.size()) * (first ? _.yi : _.xi)) - b * 1.0 / _valList.size() * (first ? _.xi : _.yi))

typedef char const *__restrict const *__restrict arr_const_restrict;

struct Coordonates {
    double xi;
    double yi;
    double x2;
    double y2;
    double xy;
};

struct Getline {
    std::string line;
    std::vector<std::string> pars;
    std::vector<double> val;
    int i ;
    bool find;
};

class Demograph
{
    public:
        Demograph(int const _ac, arr_const_restrict _av);
        ~Demograph() = default;

        void run();
        void loadCountry();
        void calc(bool first);
        void corelation();
    private:
        void countryFound();
        void readFile(std::string);
        std::vector<std::string> parsLine(std::string);
        std::map<int, double> _valList;
        std::vector<std::string> _codeList;
        std::vector<std::string> _countryList;
        Coordonates _coords;
        Getline _file;
};
