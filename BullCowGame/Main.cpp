// Bulls and Cows game for practice C++ skills with the course "The Unreal Engine Developer Course - Learn C++ & Make Games"

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Entry point for our application
int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}


void PrintIntro()
{
	// Introduce the game
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Wellcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	// Loop for the number of turns asking for guesses
	for (int i = 1; i <= MaxTries; i++)
	{
		BCGame.NewCurrentTry(i);
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
	}
}


std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	// Get a guess from the player
	std::string Guess;
	std::cout << "\nCurrent Try: " << CurrentTry << " - Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain()
{
	std::string Response;
	std::cout << "\nDo you want to play again? (y/n) ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
} 