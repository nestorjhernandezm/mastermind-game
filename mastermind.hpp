#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
#include <sstream>

#include "code.hpp"

class Mastermind
{
    public:
        Mastermind();
        Mastermind(int);
        Mastermind(int, int, int);
        std::string test_code(Code);
        int get_trials();
        Code get_code();
        std::string print_hidden();

    private:
        int m_max_trials;  // Maximum number of trials to guess a code
        Code m_hidden_code; // Code to decipher
};

#endif /* MASTERMIND_H */
