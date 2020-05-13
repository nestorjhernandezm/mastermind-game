#ifndef CODE_H
#define CODE_H

#include <cstdlib>
#include <ctime>
#include <numeric>
#include <string>
#include <vector>

class Code
{
    public:
        static const std::vector<std::string> color_list;

    public:
        Code();
        Code(int, int);
        Code(std::vector<std::string>);
        std::vector<std::string> get_code();
        std::string print_code();
        int length();

        std::string& operator[](const int);

    private:
        int m_code_length; // Number of holes per code
        int m_repeat_colors; // Allow repeated colors in a code
        std::vector<std::string> m_code; // The code
};

#endif /* CODE_H */
