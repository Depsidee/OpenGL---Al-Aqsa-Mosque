#pragma once
class Dome
{
public:
	Dome();
	~Dome();

	static void draw1(int texture, int textureCylinder, int textureHalfBall, int textureGround);
	static void draw2(int textureCube, int textureOctahedron, int textureHalfBall, int textureDoor, int textureGround,int textureWindow);
	static void draw3(int texture1, int texture2);
};

