#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 1) {
        cout << "there's no input program!";
        return 0;
    }
    ifstream fin(argv[1]);
    string code = "";
    
    int memory[16] = {0};
    
    int reg=0;
    if (fin.fail()) {
        cout << "program not found!";
        return 0;
    }
    while (!fin.eof()) {
        string line;
        fin >> line;
        code += line;
    }
    for (int i = 0; i < code.size() - 9; i += 8) {
        string command = { code[i] , code[i + 1] , code[i + 2] , code[i + 3] };
        string data = {code[i + 4] , code[i + 5] , code[i + 6] , code[i + 7] };      
        if (command == "0000") reg = (int)strtol(data.c_str(), NULL, 2);
        if (command == "0001") reg = memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "0010") memory[(int)strtol(data.c_str(), NULL, 2)] = reg;
        if (command == "0011") reg += memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "0100") reg -= memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "0101") reg *= memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "0110") reg /= memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "0111") cout << memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "1000") cin >> memory[(int)strtol(data.c_str(), NULL, 2)];
        if (command == "1111") return 0;
    }
    return 0;



}

