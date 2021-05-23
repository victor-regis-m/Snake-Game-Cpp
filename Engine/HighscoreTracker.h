#pragma once

class HighscoreTracker
{
public:
	HighscoreTracker();
	void HighScoreCheckSet(int score);
	int GetHighScore();
private:
	int highscore;
	void CompareHighScore(int score);
	void SetStoredHighScore();
	void GetStoredHighScore();
};