#pragma once

class FBullCowGame 
{
public:
	FBullCowGame();

	void Reset(); // TODO make a more rich return value
	void NewCurrentTry(int NewTry);

	int GetMaxTries() const;
	int GetCurrentTry() const;

	bool IsGameWon();
	bool CheckGuessValidity();

private:
	int MyCurrentTry;
	int MyMaxTries;
};