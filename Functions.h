#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#pragma once

using namespace std;

class Functions {
    public:
        static vector<string> explode(string const & s, char delim);
        static int randomInt(int min, int max);
};