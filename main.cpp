#include <SFML/Graphics.hpp>
#include "Framework.h"

int main()
{
	Framework mainloop;
	TextureHolder textureHolder;

	mainloop.Initialize();

	while (true)
	{
		mainloop.Update();
		
		mainloop.Draw();

	}

}