#include "precomp.h"
#include <fstream>
#include <string>


// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	map = new Map(screen);
	map->InitializeTiles();
	// anything that happens only once at application start goes here
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	
	screen->Clear( 0 ); 
	map->DrawMap();
	

}