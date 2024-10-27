#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, double> variables;

class nao
{
public:
    nao(const string &var, double value)
    {
        variables[var] = value;
    }
};

class jog_koro
{
public:
    jog_koro(const string &result, const string &operand1, const string &operand2)
    {
        variables[result] = variables[operand1] + variables[operand2];
    }
};

void dao(const string &message, const string &var)
{
    if (variables.find(var) != variables.end())
    {
        cout << message << variables[var] << endl;
    }
    else
    {
        cerr << "Error: Variable " << var << " is not defined" << endl;
    }
}

int main()
{
    nao a("a", 5);
    nao b("b", 6);
    jog_koro c("c", "a", "b");
    dao("jog fol holo: ", "c");

    return 0;
}
