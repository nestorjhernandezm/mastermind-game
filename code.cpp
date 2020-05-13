#include "code.hpp"

const std::vector<std::string> Code::color_list = {
    "Purple", "Blue", "Green", "Yellow", "Orange", "Red"}; // Code peg colors

Code::Code () :
    m_code_length(4), m_repeat_colors(1)
{
    m_code.resize(m_code_length);
    m_code = {"", "", "", ""};
}

Code::Code (int code_length, int repeat_colors) :
    m_code_length(code_length), m_repeat_colors(repeat_colors)
{
    m_code.resize(m_code_length);

    srand(static_cast<int>(time(0)));

    if (repeat_colors)
    {
        for (int i = 0; i < code_length; ++i)
        {
            m_code[i] = color_list[rand() % 6];
        }
    }
    else
    {
        std::vector<int> index(6); // vector with 100 ints.
        std::iota(std::begin(index), std::end(index), 0);

        for (int i = 0; i < code_length; ++i)
        {
            int random_value = rand() % (int)(6 - i);
            m_code[i] = color_list[index[random_value]];
            index.erase(index.begin() + random_value);
        }
    }
}

Code::Code(std::vector<std::string> code)
{
    m_code_length = code.size(); 
    m_code.resize(m_code_length);

    for (int i = 0; i < m_code_length; ++i)
    {
        m_code[i] = code[i];
    }
}

std::vector<std::string> Code::get_code()
{
    return m_code;
}

std::string Code::print_code()
{
    std::string code_str = "";

    for (int i = 0; i < m_code_length; ++i)
    {
        if (i != m_code_length - 1)
        {
            code_str += m_code[i] + ",";
        }
        else
        {
            code_str += m_code[i];
        }        
    }
    return code_str;
}

int Code::length()
{
    return m_code_length;
}

std::string& Code::operator[](const int index)
{
    return m_code[index];
}
