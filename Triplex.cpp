#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
   std::cout << "\nYou are aa secret agent breaking into a level " << Difficulty;
   std::cout << " secure server room... \nEnter the correct code to continue..." << std::endl;
}
bool PlayGame(int Difficulty)
{
   PrintIntroduction(Difficulty);
   // Declare 3 number code
   const int CodeA = rand() % Difficulty + Difficulty, CodeB = rand() % Difficulty + Difficulty, CodeC = rand() % Difficulty + Difficulty;
   /*
      This is a multi line comment and it is mostly just used to long explanations.
   */
   const int CodeSum = CodeA + CodeB + CodeC;
   const int CodeProduct = CodeA * CodeB * CodeC;
   //Print sum and product to the terminal
   std:: cout << std:: endl;
   std:: cout << "There are 3 numbers in the code" << std::endl;
   std:: cout << "The codes add up to: " << CodeSum << std:: endl;
   std:: cout << "The codes multiply to give: " << CodeProduct << std:: endl;
   
   //Store Player Guess
   int GuessA, GuessB, GuessC;
   std::cin >> GuessA;
   std::cin >> GuessB;
   std::cin >> GuessC;
   
   int GuessSum = GuessA + GuessB + GuessC;
   int GuessProduct = GuessA * GuessB * GuessC;
   //Check if the players guess is correct
   if((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
   {
       std:: cout << "Well Done Agent! You have extracted a file! Keep Going!" << std::endl;
       return true;
   }
   else
   {
       std:: cout << "You failed to extract the file! Keep going! " << std::endl;
       return false;
   }
   return true;
}
int main()
{
    srand(time(NULL)); //create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); //all boolean variable names need to start with a lowercase in unreal
        std::cin.clear(); //clear errors for cin
        std::cin.ignore(); //Discards the buffer
        if (bLevelComplete)
        { //increase the level difficulty
           ++LevelDifficulty;
        }
        
    }
    std:: cout << "Congratuations you have completed the game!" << std:: endl;
   return 0;
}