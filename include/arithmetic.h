#ifndef Ar
#define Ar

#include"stack.h"

struct Lexem {
    double numb;
    char op;
    bool isOp = 0;
    int pos;
};

// isOp = true  -> op
// isOp = false  -> nmb


class Arithmetic {
    std::string string;
    std::vector<Lexem> postfix;
    double result;
    std::pair<int, std::string> error;
    void Convert(std::string str);
    double Calculate();
public:
    Arithmetic(std::string str);
    std::pair<double, int> Execution();

};
#endif 
