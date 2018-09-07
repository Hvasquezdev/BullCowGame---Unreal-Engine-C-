#include "pch.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;	
	MyHiddenWord = "planet";
	return;
}

void FBullCowGame::NewCurrentTry(int32 NewTry)  {  MyCurrentTry = NewTry;  }

int32 FBullCowGame::GetMaxTries() const  {  return MyMaxTries;  }

int32 FBullCowGame::GetCurrentTry() const  {	return MyCurrentTry;	}

int32 FBullCowGame::GetHiddenWordLength() const  {	return MyHiddenWord.length();  }

bool FBullCowGame::IsGameWon()	{  return false;  }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)	{  
	
	if (false) // If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (false) // If the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // If the guess length is wrong
	{
		return EGuessStatus::Worng_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the number of turn
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	// Loop through all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// Compare the letter against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// If they match then
			if (MyHiddenWord[i] == Guess[j])
			{
				// If they're in the same place
				if (i == j)
				{
					// Increment bulls
					BullCowCount.Bulls++;
				}
				else
				{
					// Increment Cows
					BullCowCount.Cows++;
				}
			} 
		}
	}

	return BullCowCount;
}
