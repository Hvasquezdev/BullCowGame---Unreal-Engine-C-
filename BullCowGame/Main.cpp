// Bulls and Cows game for practice C++ skills with the course "The Unreal Engine Developer Course - Learn C++ & Make Games"

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
void PrintGameSummary();
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
	std::cout << "\n\nWellcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetWordLength() << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	int32 i = 1;

	if (BCGame.IsGameWon())
	{
		i = 1;
	}

	// Loop for the number of turns asking for guesses
	do
	{
		BCGame.NewCurrentTry(i);
		Ftext Guess = GetValidGuess();

		if (Guess != "Error")
		{
			// Submit valid guess to the game, and receive counts
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

			std::cout << "Bulls: " << BullCowCount.Bulls;
			std::cout << ". Cows: " << BullCowCount.Cows << std::endl;

			std::cout << "Your guess was: " << Guess << std::endl;

			i++;
		}
	} while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries);
	PrintGameSummary();
	return;
}


Ftext GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	
	// Get a guess from the player
	Ftext Guess;
	std::cout << "\nCurrent Try: " << CurrentTry << " - Enter your guess: ";
	std::getline(std::cin, Guess);

	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
	case EGuessStatus::Not_Isogram:
		std::cout << "Please enter a word without repeating letters." << std::endl;
		return "Error";
		break;
	case EGuessStatus::Worng_Length:
		std::cout << "Please write a guess with " << BCGame.GetWordLength() << " Letters." << std::endl;
		return "Error";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "Please write al guess in lowercase" << std::endl;
		return "Error";
		break;
	default:
		return Guess;
		break;
	}

}


bool AskToPlayAgain()
{
	Ftext Response;
	std::cout << "\nDo you want to play again with the same hidden word? (y/n) ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
} 

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\nWell Done! - You win the game";
	}
	else
	{
		std::cout << "\nBetter luck next time!";
	}
	return;
}