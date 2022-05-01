#include "NewGamePlay.h"

void NewGamePlay::Init()
{
	mainView.setCenter(0, 0);
	mainView.setSize()
}

void NewGamePlay::Update()
{
}

void NewGamePlay::Draw(RenderWindow& window)
{
}

void NewGamePlay::Release()
{
}

int NewGamePlay::CreateBackGround(VertexArray& va, IntRect arena)
{
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;

	int cols = arena.width / TILE_SIZE;
	int rows = arena.height / TILE_SIZE;

	va.setPrimitiveType(Quads);
	va.resize(cols * rows * VERTS_IN_QUAD);


	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			int index = r * cols + c;

			float x = c * TILE_SIZE;
			float y = r * TILE_SIZE;

			int vertexIndex = index * VERTS_IN_QUAD;

			va[vertexIndex + 0].position = Vector2f(x, y);
			va[vertexIndex + 1].position = Vector2f(x + TILE_SIZE, y);
			va[vertexIndex + 2].position = Vector2f(x + TILE_SIZE, y + TILE_SIZE);
			va[vertexIndex + 3].position = Vector2f(x, y + TILE_SIZE);

			int texIndex = Utils::RandomRange(0, TILE_TYPES);
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
			{
				texIndex = 3;
			}
			float offset = texIndex * TILE_SIZE;
			va[vertexIndex + 0].texCoords = Vector2f(0.f, offset);
			va[vertexIndex + 1].texCoords = Vector2f(TILE_SIZE, offset);
			va[vertexIndex + 2].texCoords = Vector2f(TILE_SIZE, offset + TILE_SIZE);
			va[vertexIndex + 3].texCoords = Vector2f(0.f, offset + TILE_SIZE);
		}
	}

	return cols * rows;
}

void NewGamePlay::CreateZombies(std::vector<Zombie*>& zombies, int count, IntRect arena, std::vector<Wall*> walls)
{
	for (auto v : zombies)
	{
		delete v;
	}
	zombies.clear();

	int offset = 50;
	int minX = arena.left + offset;
	int maxX = arena.width - offset;
	int minY = arena.top + offset;
	int maxY = arena.height - offset;

	for (int i = 0; i < count; ++i)
	{
		int x = Utils::RandomRange(minX, maxX + 1);
		int y = Utils::RandomRange(minY, maxY + 1);
		ZombieTypes type = (ZombieTypes)Utils::RandomRange(0, (int)ZombieTypes::COUNT);
		Zombie* zombie = new Zombie();
		zombie->Spawn(type, arena, x, y, walls);
		zombies.push_back(zombie);
	}
}

void NewGamePlay::CreateWalls(std::vector<Wall*>& walls, IntRect arena)
{
	for (auto v : walls)
	{
		delete v;
	}

	walls.clear();

	int offset = 25;
	Wall* wallUp = new Wall(0, arena.left, arena.width, offset);
	walls.push_back(wallUp);
	Wall* wallDown = new Wall(arena.top + arena.height - offset, arena.left, arena.width, offset);
	walls.push_back(wallDown);
	Wall* wallLeft = new Wall(offset, arena.left, offset, arena.height - 2 * offset);
	walls.push_back(wallLeft);
	Wall* wallRight = new Wall(offset, arena.left + arena.width - offset, offset, arena.height - 2 * offset);
	walls.push_back(wallRight);
}
