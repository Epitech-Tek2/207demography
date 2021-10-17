//
// EPITECH PROJECT, 2018
// 207demography
// File description:
// demograph method
//

#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "demograph.hpp"

Demograph::Demograph(int const _ac, arr_const_restrict _av)
    : _coords{0, 0, 0, 0, 0}
{
    for (int i = 1; i < _ac; i++) _codeList.push_back(static_cast<std::string>(_av[i]));
}

void Demograph::run()
{
    loadCountry();
    calc(true);
    calc(false);
    corelation();
}

void Demograph::loadCountry()
{
    unsigned int size = 0;

    for (auto &it : _codeList) readFile(it);
    cOutn("Country: ");
    for (std::size_t i = 0; i < _countryList.size(); ++i, ++size) {
        cOutn(_countryList[i]);
        if (size < (_countryList.size() - 1)) cOutn(", ");
    }
    cOutn(std::endl);
    for (auto &it : _valList)
        _coords = (Coordonates){.xi = _.xi += it.first, .yi = _.yi += it.second,
        .x2 = _.x2 += pow(it.first, 2), .y2 = _.y2 += pow(it.second, 2),
        .xy = _.xy += it.first * it.second};
}

void Demograph::countryFound()
{
    _countryList.push_back(_file.pars[0]);
    _file.find = true;
    for (; _file.pars.size() > _file.i; ++_file.i)
        if (_file.i > 1) _valList[_file.i + 1958] += toDouble(_file.pars[_file.i]);
}

void Demograph::readFile(std::string country)
{
    std::ifstream file("./207demography_data.csv");

    _file = (Getline){.i = 0, .find = false};
    if (!file) throw std::overflow_error("File not found");
    while (getline(file, _file.line)) {
        _file.pars = parsLine(_file.line);
        if (_file.pars[1] == country) countryFound();
    }
    file.close();
    if (_file.find == false) throw std::overflow_error(country + " doesn't exist");
}

std::vector<std::string> Demograph::parsLine(std::string line)
{
    std::vector<std::string> list;
    int start = 0;
    std::size_t end = line.find(';');

    for (; true; start = end + 1, end = line.find(';', start)) {
        list.push_back(line.substr(start, end - start));
        if (end == std::string::npos) break;
    }
    return list;
}

void Demograph::calc(bool first)
{
    double b, a, sum = 0;

    cOut((first ? "Fit1" : "Fit2"));
    b = calcOfB();
    a = calcOfA();
    (void)(first && (a /= 1000000));
    b = first ? b /= 1000000 : b *= 1000000;
    std::printf(first ? "    Y = %.2lf X %s%.2lf\n" : "    X = %.2lf Y %s%.2lf\n", b, (a < 0) ? "- " : "+ ", (a < 0) ? a * -1 : a);
    for (auto &it : _valList) sum += pow(it.second - ((first ? (b * (double)it.first + a) : ((it.first - a) / b)) * 1000000), 2);
    std::printf("    Root-mean-square deviation:\t%.2lf\n    Population in 2050:\t%.2lf\n", sqrt(sum / _valList.size()) / 1000000, first ? ((b * 2050.0) + a) : ((2050.0 - a) / b));
}

void Demograph::corelation()
{
    std::printf("Correlation: %.4lf\n", (((_valList.size()) * _.xy - _.xi * _.yi) / sqrt(((_valList.size()) * _.x2 - pow(_.xi, 2)) * ((_valList.size()) * _.y2 - pow(_.yi, 2)))));
}
