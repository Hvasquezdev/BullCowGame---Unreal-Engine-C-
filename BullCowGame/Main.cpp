// Bulls and Cows game for practice C++ skills with the course "The Unreal Engine Developer Course - Learn C++ & Make Games"

#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make the syntax unreal engine friendly
using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game, wich we re-use across the plays 

// Entry point for our application
int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		system("cls");
	} while (bPlayAgain);

	return 0;
}


void PrintIntro()
{
	// Introduce the game
	std::cout << "\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "=> Can you guess the " << BCGame.GetWordLength() << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries{ BCGame.GetMaxTries() };
	int32 i{1};

	if (BCGame.IsGameWon())
	{
		i = 1;
	}

	do	// Loop for the number of turns asking for guesses
	{
		BCGame.NewCurrentTry(i);
		Ftext Guess{ GetValidGuess() };

		if (Guess != "Error")
		{
			// Submit valid guess to the game, and receive counts
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

			std::cout << "\n================================= " << std::endl;
			std::cout << "=> Bulls: " << BullCowCount.Bulls;
			std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
			std::cout << "=> Your last guess was: " << Guess << std::endl;
			std::cout << "================================= "<< std::endl;

			i++;
		}
	} while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries);
	PrintGameSummary();
	return;
}


Ftext GetValidGuess()
{
	int32 CurrentTry{ BCGame.GetCurrentTry() };
	
	// Get a guess from the player
	Ftext Guess;
	std::cout << "\nCurrent Try: " << CurrentTry;
	std::cout << " of: " << BCGame.GetMaxTries() << " - Enter your guess: ";
	std::getline(std::cin, Guess);

	EGuessStatus Status{ BCGame.CheckGuessValidity(Guess) };
	switch (Status)
	{
	case EGuessStatus::Not_Isogram:
		std::cout << "\n================================= " << std::endl;
		std::cout << "=> Please enter a word without repeating letters." << std::endl;
		std::cout << "================================= " << std::endl;
		return "Error";
		break;
	case EGuessStatus::Worng_Length:
		std::cout << "\n================================= " << std::endl;
		std::cout << "=> Please write a guess with " << BCGame.GetWordLength() << " Letters." << std::endl;
		std::cout << "================================= " << std::endl;
		return "Error";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "\n================================= " << std::endl;
		std::cout << "=> Please write al letters in lowercase" << std::endl;
		std::cout << "================================= " << std::endl;
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