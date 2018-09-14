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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
	const bool down = wnd.kbd.KeyIsPressed(VK_DOWN);
	const bool up = wnd.kbd.KeyIsPressed(VK_UP);
	const bool left = wnd.kbd.KeyIsPressed(VK_LEFT);
	const bool right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	shift = wnd.kbd.KeyIsPressed(VK_SHIFT);
	const bool space = wnd.kbd.KeyIsPressed(VK_SPACE);
	ctrl = wnd.kbd.KeyIsPressed(VK_CONTROL);


	if (up == true)
	{
		{
			if (inhibitUp)
			{
			}
			else
			{
				rocket.vy = rocket.vy - 1;
				inhibitUp = true;
			}
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (down == true)
	{
		{
			if (inhibitDown)
			{
			}
			else
			{
				rocket.vy = rocket.vy + 1;
				inhibitDown = true;
			}
		}
	}
	else
	{
		inhibitDown = false;
	}

	if (left == true)
	{
		if (inhibitLeft)
		{
		}
		else
		{
			rocket.vx = rocket.vx - 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	if (right == true)
	{
		if (inhibitRight)
		{
		}
		else
		{
			rocket.vx = rocket.vx + 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
	if (space == true)
	{
		rocket.vx = 0;
		rocket.vy = 0;
	}
	rocket.x = rocket.x + rocket.vx;
	rocket.y = rocket.y + rocket.vy;

	rocket.ClampScreenX();
	rocket.ClampScreenY();

	colliding =
		OverlapTest(x_fixed0, y_fixed0, rocket.x, rocket.y ) ||
		OverlapTest(x_fixed1, y_fixed1, rocket.x, rocket.y ) ||
		OverlapTest(x_fixed2, y_fixed2, rocket.x, rocket.y ) ||
		OverlapTest(x_fixed3, y_fixed3, rocket.x, rocket.y );
}

void Game::ComposeFrame()
{
	
	DrawAlien(x_fixed0, y_fixed0, 255, 0, 0);
	DrawAlien(x_fixed1, y_fixed1, 0, 0, 255);
	DrawAlien(x_fixed2, y_fixed2, 255, 0, 255);
	DrawAlien(x_fixed3, y_fixed3, 0, 255, 0);
	DrawRocket(rocket.x, rocket.y, rocket.r, rocket.g,rocket.b);
			
}

void Game::DrawAlien(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 8, y, r, g, b);
	gfx.PutPixel(x + 3, y + 1, r, g, b);
	gfx.PutPixel(x + 7, y + 1, r, g, b);
	gfx.PutPixel(x + 2, y + 2, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 4, y + 2, r, g, b);
	gfx.PutPixel(x + 5, y + 2, r, g, b);
	gfx.PutPixel(x + 6, y + 2, r, g, b);
	gfx.PutPixel(x + 7, y + 2, r, g, b);
	gfx.PutPixel(x + 8, y + 2, r, g, b);
	gfx.PutPixel(x + 1, y + 3, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 6, y + 3, r, g, b);
	gfx.PutPixel(x + 8, y + 3, r, g, b);
	gfx.PutPixel(x + 9, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 2, y + 4, r, g, b);
	gfx.PutPixel(x + 3, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 6, y + 4, r, g, b);
	gfx.PutPixel(x + 7, y + 4, r, g, b);
	gfx.PutPixel(x + 8, y + 4, r, g, b);
	gfx.PutPixel(x + 9, y + 4, r, g, b);
	gfx.PutPixel(x + 10, y + 4,r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b );
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 6, y + 5, r, g, b);
	gfx.PutPixel(x + 7, y + 5, r, g, b);
	gfx.PutPixel(x + 8, y + 5, r, g, b);
	gfx.PutPixel(x + 10, y + 5, r, g, b);
	gfx.PutPixel(x, y + 6, r, g, b);
	gfx.PutPixel(x + 2, y + 6, r,g, b);
	gfx.PutPixel(x + 8, y + 6, r,g, b);
	gfx.PutPixel(x + 10, y + 6, r,g, b);
	gfx.PutPixel(x + 3, y + 7, r, g, b);
	gfx.PutPixel(x + 4, y + 7, r, g, b);
	gfx.PutPixel(x + 6, y + 7, r, g, b);
	gfx.PutPixel(x + 7, y + 7, r, g, b);
}

void Game::DrawRocket(int x, int y, int r, int g, int b)
{
	if (ctrl == false)
	{
		
		gfx.PutPixel(x + 4, y    ,r, g, b);
		gfx.PutPixel(x + 4, y + 1,r, g, b);
		gfx.PutPixel(x + 3, y + 2,r, g, b);
		gfx.PutPixel(x + 5, y + 2,r, g, b);
		gfx.PutPixel(x + 2, y + 3,r, g, b);
		gfx.PutPixel(x + 4, y + 3,r, g, b);
		gfx.PutPixel(x + 6, y + 3,r, g, b);
		gfx.PutPixel(x + 0, y + 4,r, g, b);
		gfx.PutPixel(x + 2, y + 4,r, g, b);
		gfx.PutPixel(x + 4, y + 4,r, g, b);
		gfx.PutPixel(x + 6, y + 4,r, g, b);
		gfx.PutPixel(x + 8, y + 4,r, g, b);
		gfx.PutPixel(x + 0, y + 5,r, g, b);
		gfx.PutPixel(x + 1, y + 5,r, g, b);
		gfx.PutPixel(x + 2, y + 5,r, g, b);
		gfx.PutPixel(x + 4, y + 5,r, g, b);
		gfx.PutPixel(x + 6, y + 5,r, g, b);
		gfx.PutPixel(x + 7, y + 5,r, g, b);
		gfx.PutPixel(x + 8, y + 5,r, g, b);
		gfx.PutPixel(x + 0, y + 6,r, g, b);
		gfx.PutPixel(x + 3, y + 6,r, g, b);
		gfx.PutPixel(x + 4, y + 6,r, g, b);
		gfx.PutPixel(x + 5, y + 6,r, g, b);
		gfx.PutPixel(x + 8, y + 6,r, g, b);
	}
	
	else
	{
		gfx.PutPixel(x  - 5, y, r, g, b);
		gfx.PutPixel(x  - 4, y, r, g, b);
		gfx.PutPixel(x  - 3, y, r, g, b);
		gfx.PutPixel(x  + 3, y, r, g, b);
		gfx.PutPixel(x  + 4, y, r, g, b);
		gfx.PutPixel(x  + 5, y, r, g, b);
		gfx.PutPixel(x , y - 5, r, g, b);
		gfx.PutPixel(x , y - 4, r, g, b);
		gfx.PutPixel(x , y - 3, r, g, b);
		gfx.PutPixel(x , y + 3, r, g, b);
		gfx.PutPixel(x , y + 4, r, g, b);
		gfx.PutPixel(x , y + 5, r, g, b);
	}
	
}


bool Game::OverlapTest(int x_box0, int y_box0, int x_box1, int y_box1)
{
	const int left_box0 = x_box0 - 5;
	const int right_box0 = x_box0 + 5;
	const int top_box0 = y_box0 - 5;
	const int bottom_box0 = y_box0 + 5;

	const int left_box1 = x_box1 - 5;
	const int right_box1 = x_box1 + 5;
	const int top_box1 = y_box1 - 5;
	const int bottom_box1 = y_box1 + 5;

	colliding = left_box0 <= right_box1 && right_box0 >= left_box1 && bottom_box0 >= top_box1 &&  top_box0 <= bottom_box1;

	if (colliding)
	{
		rocket.r = 0;
		rocket.g = 255;
		rocket.b = 0;
		return true;
	}
	else
	{
		if (shift)
		{
			rocket.r = 255;
			rocket.g = 0;
			rocket.b = 0;
		}
		else
		{
			rocket.r = 255;
			rocket.g = 255;
			rocket.b = 255;
		}
		return false;
	}
}

