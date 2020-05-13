#include "mastermind.hpp"

Mastermind::Mastermind() : m_max_trials(10), m_hidden_code (4, 1)
{
}

Mastermind::Mastermind(int max_trials) : m_max_trials(max_trials),
    m_hidden_code (4, 1)
{
}

Mastermind::Mastermind(int max_trials, int code_length, int repeat_colors) :
    m_max_trials(max_trials), m_hidden_code(code_length, repeat_colors)
{
}

std::string Mastermind::test_code(Code guess)
{
    int blacks = 0;
    int whites = 0;
    int empty = 0;

    int code_length = m_hidden_code.length();

    // Get black pegs first
    for (int i = 0; i < code_length; ++i)
    {
        if (guess[i] == m_hidden_code[i])
        {
            blacks++;
        }
    }

    // For the white pegs, get the total amount of correct color matches
    // between the user guess and the hidden code. Then, subtract the previous
    // black pegs amount.

    // For each color, the least amount between the guess and hidden code
    // tells how many times a color was correct, regardless if it is in the
    // right position or not. The total amount of matches is just adding the
    // result for all the colors.

    // Set color count containers
    int color_list_size = Code::color_list.size();

    int guess_color_count[color_list_size];
    int hidden_color_count[color_list_size];

    std::fill_n(guess_color_count, color_list_size, 0);
    std::fill_n(hidden_color_count, color_list_size, 0);

    // Get color counts
    for (int i = 0; i < code_length; ++i)
    {
        for (int j = 0; j < color_list_size; ++j)
        {
            if (guess[i] == Code::color_list[j])
            {
                guess_color_count[j]++;
            }

            if (m_hidden_code[i] == Code::color_list[j])
            {
                hidden_color_count[j]++;
            }
        }
    }

    int total_color_matches = 0;

    for (int j = 0; j < color_list_size; ++j)
    {
        total_color_matches += std::min(guess_color_count[j],
            hidden_color_count[j]);
    }

    // Get white pegs
    whites = total_color_matches - blacks;

    // Finally, calculate the empty peg holes
    empty = code_length - total_color_matches;

    std::string guess_feedback = "";

    for (int i = 0; i < blacks; ++i)
    {
        guess_feedback += " Black ";
    }

    for (int i = 0; i < whites; ++i)
    {
        guess_feedback += " White ";
    }

    for (int i = 0; i < empty; ++i)
    {
        guess_feedback += " Empty ";
    }

    return guess_feedback;
}

int Mastermind::get_trials()
{
   return m_max_trials;
}

Code Mastermind::get_code()
{
    std::string input;
    std::vector<std::string> code;

    std::cin >> input;
    std::istringstream ss(input);
    std::string split;

    while(std::getline(ss, split, ','))
    {
        code.emplace_back(split);
    }

    return Code(code);
}

std::string Mastermind::print_hidden()
{
    return m_hidden_code.print_code();
}
