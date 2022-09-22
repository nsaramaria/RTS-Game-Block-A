#include "precomp.h"
#include "Map.h"
#include <fstream>

Tmpl8::Map::Map(Surface* nscreen)
{
    screen = nscreen;
}

void Map::TiledDraw(int index, int x, int y)
{
            int tx = (index - 1) % 60;
            int ty = (index - 1) / 60;
            uint* src = tilemap.pixels + tx * 32 + (ty * 32) * tilemap.width;
            uint* dst = screen->pixels + x * 32 + y * 32 * screen->width;
            for (int i = 0; i < 32; i++)
            {
                for (int j = 0; j < 32; j++)
                      dst[j] = src[j];
                src += tilemap.width, dst += screen->width;
            }
}

void Map::DrawMap()
{
    int x, y;
    for (int y = 0; y < 23; y++)
    {
        for (int x = 0; x < 40; x++)
        {
            TiledDraw(tiles[x + y * 70], x, y);
        }
    }
}

void Map::InitializeTiles()
{
    ifstream fin("tilemap/tilemap.txt");
    int x;
    while (fin >> x)
    {
        tiles.push_back(x);
    }
    std::cout << tiles.size(); 
    fin.close();
}


//initialize citeste numerele fisier -> tiles
//draw -> for (i =0; i < tiles.size();i++)
//int x = i % 41;
//int y = i / 41;
//TiledDraw (tiles[i], x, y);