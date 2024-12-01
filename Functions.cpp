#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include "Functions.h"

using namespace std;

vector<string> Functions::explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}
int Functions::randomInt(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    return min + (rand() % (max - min + 1));
}