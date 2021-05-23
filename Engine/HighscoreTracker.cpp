#include "HighscoreTracker.h"
#include <iostream>
#include <fstream>
using namespace std;

HighscoreTracker::HighscoreTracker()
{
	GetStoredHighScore();
}

void HighscoreTracker::HighScoreCheckSet(int score)
{
	CompareHighScore(score);
	SetStoredHighScore();
}

int HighscoreTracker::GetHighScore()
{
	return highscore;
}

void HighscoreTracker::CompareHighScore(int score)
{ 
	if (score > highscore)
		highscore = score;
}

void HighscoreTracker::SetStoredHighScore()
{
	std::ofstream scoreFile("scores.txt");
	scoreFile << highscore;
}

void HighscoreTracker::GetStoredHighScore()
{
	std::ifstream scoreFile("scores.txt");	
	scoreFile >> highscore;
}
