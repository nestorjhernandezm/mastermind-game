#include "mastermind.hpp"

int main()
{
    // Welcome to Mastermind!

    // You are a codebreaker and the purpose of the game is to decipher a
    // hidden code made of colors pegs from the codemaker (computer). To do
    // so, you will have a given number of trials to guess the code. Once you
    // introduce a code, the codemaker will indicate how good your guess was
    // through feedback. It will show you "Black" for each correct color peg
    // of your code in a correct position. Also, it will show you "White" for
    // each correct color peg of your code, but in an incorrect position.
    // Finally, it will show "Empty" when neither the color nor the position
    // is correct. The order of how do these appear does not indicate about
    // the order in the code. Before the game starts, you are able to choose
    // some of the game parameters.

    // Good luck!

    std::cout << "Welcome to Mastermind!" << std::endl;
    std::cout << "For the instructions, please check the first comment"
              << " from main.cpp" << std::endl;

    std::cout << "Introduce maximum number of trials (integer)" << std::endl;
    int trials;
    std::cin >> trials;

    std::cout << "Introduce the code length (integer)" << std::endl;
    int length;
    std::cin >> length;

    std::cout << "Do you want to repeat colors in a code? (Yes: 1, No: 0)"
              << std::endl;
    int repeat_colors;
    std::cin >> repeat_colors;

    Mastermind game(trials, length, repeat_colors);

    std::string feedback;

    for (int i = 0; i < game.get_trials(); ++i)
    {
        std::cout << "Guess trial: " << i + 1 << std::endl;
        std::cout << std::endl;

        std::cout << "Introduce your guess (Example: Red,Green,Blue,Purple)"
                  << std::endl;
        feedback = game.test_code(game.get_code());

        std::cout << "Feedback: " + feedback << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        if (feedback == " Black  Black  Black  Black ")
        {
            std::cout << "You won in " << i + 1 << " guesses!" << std::endl;
            break;
        }
    }

    std::cout << "Maximum trials reached!"<< std::endl;
    std::cout << "Hidden code was: " + game.print_hidden() << std::endl;
}
