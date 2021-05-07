#include "TileGraph.h"

TileGraph::TileGraph()
{
	//tiles = nullptr;

	anchoTileGraph = 0;
	altoTileGraph = 0;
}

TileGraph::TileGraph(int _anchoTileGraph, int _altoTileGraph)
{
	// Crear un array dinamico de Tile
	//tiles = new Tile[_anchoTileGraph * _altoTileGraph];

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			//tiles[x + (y * _anchoTileGraph)].setPosicionX(x);
			//tiles[x + (y * _anchoTileGraph)].setPosicionY(y);
			listTilesGraph.push_back(new Tile(x, y));
		}
	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

void TileGraph::configurar(int _anchoTileGraph, int _altoTileGraph)
{
	// If the TileGraph is not empty, empty it
	/*if (tiles != nullptr)
		delete[] tiles;*/

	//tiles = new Tile[_anchoTileGraph * _altoTileGraph];

	if(!listTilesGraph.empty())
		listTilesGraph.clear();

	// Set position of all tiles
	// NOTE: This could propably be also made with constructor
	for (int y = 0; y < _altoTileGraph; y++) {
		for (int x = 0; x < _anchoTileGraph; x++) {
			//tiles[x + (y * _anchoTileGraph)].setPosicionX(x);
			//tiles[x + (y * _anchoTileGraph)].setPosicionY(y);
			
			listTilesGraph.push_back(new Tile(x, y));
		}
	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

TileGraph::~TileGraph()
{
	//delete[] tiles;
	listTilesGraph.clear();
}

Tile* TileGraph::getTileEn(int x, int y)
{
	int indice = getIndice(x, y);
	if (indice < 0)
		return nullptr;

	//return listTilesGraph[indice];

	//return &tiles[indice];

	int c = 0;
	for (auto ilvo = listTilesGraph.begin(); ilvo != listTilesGraph.end(); ++ilvo) {
		listTilesGraph.push_back(*ilvo);
		if (c == indice) {
			return (*ilvo);
		}
		c++;
	}
	return nullptr;
}

array<Tile*, 4> TileGraph::get4Vecinos(Tile* tile)
{
	std::array<Tile*, 4> Vecinos;

	int x = tile->getPosicionX();
	int y = tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph

	return Vecinos;
}

array<Tile*, 8> TileGraph::get8Vecinos(Tile* tile)
{
	std::array<Tile*, 8> Vecinos;

	int x = tile->getPosicionX();
	int y = tile->getPosicionY();

	Vecinos[0] = getTileEn(x, y + 1);		// N
	Vecinos[1] = getTileEn(x + 1, y);		// E
	Vecinos[2] = getTileEn(x, y - 1);		// S
	Vecinos[3] = getTileEn(x - 1, y);		// _anchoTileGraph
	Vecinos[4] = getTileEn(x + 1, y + 1);	// NE
	Vecinos[5] = getTileEn(x - 1, y + 1);	// SE
	Vecinos[6] = getTileEn(x - 1, y - 1);	// SW
	Vecinos[7] = getTileEn(x + 1, y - 1);	// NW

	return Vecinos;
}

Pacman* TileGraph::getPacman(std::list<Tile*> & _listTileGraphX)
{
	/*for (unsigned int i = 0; i < anchoTileGraph * altoTileGraph; i++) {
		Tile tile = tiles[i];

		if (tile.getPacman() != nullptr)
			return tile.getPacman();
	}*/

	for (auto ilvo = listTilesGraph.begin(); ilvo != listTilesGraph.end(); ++ilvo) {
		// _listTileGraphX.push_back(*ilvo);

		 if ((*ilvo)->getPacman())
			 return (*ilvo)->getPacman();
		/*if (tile.getPacman() != nullptr)*/
			//return tile.getPacman();
	}

	/*for (unsigned int i = 0; i < vectorTilesGraph.size(); i++) {

		Tile newTile = vectorTilesGraph[i];

		if (newTile.getPacman() != nullptr)
			return newTile.getPacman();
	}*/


	return nullptr;
}

int TileGraph::getIndice(int x, int y)
{
	if (x >= anchoTileGraph || y >= altoTileGraph)
		return -1;

	if (x < 0 || y < 0)
		return -1;

	return x + y * anchoTileGraph;
}