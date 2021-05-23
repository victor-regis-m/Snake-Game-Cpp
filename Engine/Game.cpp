/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snake(brd.GetBoardCenter()),
	moveDirection{ -1,0 },
	rng(rd()),
	xDist(brd.GetBoardCenter().x - (brd.GetBoardWidth() - 2) / 2,
		brd.GetBoardCenter().x + (brd.GetBoardWidth() - 2) / 2),
	yDist(brd.GetBoardCenter().y - (brd.GetBoardHeight() - 2) / 2,
		brd.GetBoardCenter().y + (brd.GetBoardHeight() - 2) / 2),
	collectible(Location{ xDist(rng), yDist(rng) }),
	lastMovedDirection{ -1,0 },
	highscoreTracker()
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (hasStarted)
	{
		if (floor(snake.GetPoints() / 100) <= 7)
			speedUp = floor(snake.GetPoints() / 100);
		else
			speedUp = 7;
		GetMovementInput();
		if (++frameCounter == framesPerMove-speedUp)
		{
			if (snake.CheckIfAlive())
			{
				sfxSlither.Play(rng, 0.08f);
				snake.MoveBy(moveDirection);
				snake.CheckSelfCollision();
				lastMovedDirection = moveDirection;
				collectible.Collider(snake);
				snake.CheckHeadInBoard(brd);
				if (collectible.Relocate(Location{ xDist(rng),yDist(rng) }, snake, rng, xDist, yDist))
					sfxEat.Play(rng, 0.8f);
			}
			frameCounter = 0;
		}
	}
	if (!snake.CheckIfAlive())
	{
		highscoreTracker.HighScoreCheckSet(snake.GetPoints());
		sndMusic.StopAll();
	}
}

void Game::ComposeFrame()
{
	if (hasStarted)
	{
		if (snake.CheckIfAlive())
		{
			snake.Draw(brd);
			brd.DrawBoardEdges();
			collectible.Draw(brd);
			brd.DrawTitle(Location{ 5,6 });
			SpriteCodex::ShowScore(10, 10, snake, gfx);
			SpriteCodex::DrawHighscore(720, 10, highscoreTracker, gfx);
		}
	}
	else
	{
		SpriteCodex::DrawTitle(300, 210, gfx);
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			sndMusic.Play(1.0f, 0.6f);
			hasStarted = true;
		}
	}
	if (!snake.CheckIfAlive())
	{
		SpriteCodex::DrawGameOver(340, 250, gfx);
		if(endFramesCounter==1)
			sndTitle.Play();
		if (endFramesCounter++ == endFramesCount)
		{
			snake = Snake(brd.GetBoardCenter());
			hasStarted = false;
			endFramesCounter = 0;
			moveDirection = Location{ -1,0 };
		}
	}
}

void Game::GetMovementInput()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		if(lastMovedDirection!=Location{1,0})
			moveDirection = Location{ -1,0 };
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		if (lastMovedDirection != Location{ -1,0 })
			moveDirection = Location{ 1,0 };
	if (wnd.kbd.KeyIsPressed(VK_UP))
		if (lastMovedDirection != Location{ 0,1 })
			moveDirection = Location{ 0,-1 };
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
		if (lastMovedDirection != Location{ 0,-1 })
			moveDirection = Location{ 0,1 };
}
