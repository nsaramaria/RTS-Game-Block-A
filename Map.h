#pragma once

namespace Tmpl8 {
	//class Surface;
}
 

namespace Tmpl8 {
	class Map
	{ 
	public:
		Map(Surface* nscreen);
		Surface* screen;
		Surface tilemap{ "assets/TileMapRTS.png" };
		std::vector<int> tiles;
		void TiledDraw(int index, int x, int y);
		void DrawMap();
		void InitializeTiles();

	};

}//Tmpl8