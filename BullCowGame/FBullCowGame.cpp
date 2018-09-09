#include "pch.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map


FBullCowGame::FBullCowGame()  {  Reset();  } // Default constructor

void FBullCowGame::NewCurrentTry(int32 NewTry)  {  MyCurrentTry = NewTry;  }

int32 FBullCowGame::GetCurrentTry() const  {	return MyCurrentTry;	}

int32 FBullCowGame::GetWordLength() const  {	return MyHiddenWord.length();  }

bool FBullCowGame::IsGameWon()	{  return bGameIsWon;  }

int32 FBullCowGame::GetMaxTries() const { 

	TMap <int32, int32> WordLengthToMaxTries{ {3,5}, {4,7}, {5,10}, {6,12}, { 7,18} };

	return WordLengthToMaxTries[MyHiddenWord.length()]; 

}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES{8};

	MyCurrentTry = 1;
	MyHiddenWord = "planet";
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)	{  
	
	if (!IsIsogram(Guess)) // If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (!IsLowerCase(Guess)) // If the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
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

	for (int32 i{0}; i < WordLength; i++) // Loop through all letters in the HiddendWord
	{
		for (int32 j{0}; j < WordLength; j++) // Compare the letter against the guess
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


bool FBullCowGame::IsIsogram(FString Word) const 
{ 
	// Treat 0 and 1 letter words as isogram
	if (Word.length() < 1) {  return true;  }

	TMap <char, bool> LetterSeen;

	for (auto Letter : Word) // Loop through all letters in the word
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) // If any letter is in the map
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true; // Add the letterto the map
		}
	}
	return true; // For example where 0/1 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}