#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Worng_Length,
	Not_Lowercase
};

class FBullCowGame 
{
public:
	FBullCowGame();

	void Reset(); // TODO make a more rich return value
	void NewCurrentTry(int32 NewTry);

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;

	bool IsGameWon();
	EGuessStatus CheckGuessValidity(FString Guess);
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
};