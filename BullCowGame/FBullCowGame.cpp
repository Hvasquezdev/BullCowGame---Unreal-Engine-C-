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
	bGameIsWon = false;
	return;
}

void FBullCowGame::NewCurrentTry(int32 NewTry)  {  MyCurrentTry = NewTry;  }

int32 FBullCowGame::GetMaxTries() const  {  return MyMaxTries;  }

int32 FBullCowGame::GetCurrentTry() const  {	return MyCurrentTry;	}

int32 FBullCowGame::GetWordLength() const  {	return MyHiddenWord.length();  }

bool FBullCowGame::IsGameWon()	{  return bGameIsWon;  }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)	{  
	
	if (false) // If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write a function for this
	} 
	else if (false) // If the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; // TODO write a function for this
	}
	else if (Guess.length() != GetWordLength()) // If the guess length is wrong
	{
		return EGuessStatus::Worng_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	for (int32 i = 0; i < WordLength; i++) // Loop through all letters in the HiddendWord
	{
		for (int32 j = 0; j < WordLength; j++) // Compare the letter against the guess
		{
			if (MyHiddenWord[i] == Guess[j]) // If they match then
			{
				if (i == j) // If they're in the same place
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			} 
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
