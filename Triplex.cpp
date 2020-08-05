#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //first story intro
    std::cout << "\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\n  You need to enter the correct codes to continue...\n\n";
    std::cout << std::endl;
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //std::cout << "Hello, World!\n";
    //declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to terminal
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The product of the code is: " << CodeProduct << std::endl;
    std::cout << std::endl;

    //store player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    //std::cin >> GuessB;
    //std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check players answer
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou Entered The Correct Code, You Win!\n";
        return true;
    }
    else
    {
        std::cout << "\nYou Entered The Wrong Code... Try It Again!\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //creates new random sequence based on time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;
    while (LevelDifficulty <= MaxDifficulty) // loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears the error flag on cin
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        
        
    }

    std::cout << "\nCongratulations, You Have Entered All The Codes Correctly\n";
    return 0;
}