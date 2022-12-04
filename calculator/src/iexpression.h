#ifndef IEXPRESSION_H
#define IEXPRESSION_H

class Expression;
class Operation;

class IExpression {
public:
    bool negative;
    bool unary;
    Operation *base_operations;

    virtual Expression *getExpression() { return 0; }
    virtual double calculate() { return 0; }
    virtual ~IExpression() { delete base_operations; }
};

#endif IEXPRESSION_H