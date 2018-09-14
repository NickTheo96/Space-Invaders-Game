#pragma once
class Rocket
{
public:
	void ClampScreenX();
	void ClampScreenY();
	int x = 400;
	int y = 300;
	int vx = 0;
	int vy = 0;
	static constexpr int width = 7;
	static constexpr int height = 20;
	int r = 255;
	int g = 255;
	int b = 255;
};