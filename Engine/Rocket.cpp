#include "Rocket.h"
#include "Graphics.h"

void Rocket::ClampScreenX()
{
	const int right = x + width;
	if (x < 0)
	{
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
	}
}

void Rocket::ClampScreenY()
{
	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
	}
}
