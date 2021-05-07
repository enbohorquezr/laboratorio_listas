#pragma once
#include <vector>
#include <iostream>
#include <list>

#include <array>
#include "Tile.h"

using namespace std;

class TileGraph
{
private:
	//Tile* tiles;
	//vector<Tile*> vectorTilesGraph;
	list<Tile*> listTilesGraph;
	int anchoTileGraph;
	int altoTileGraph;

	int getIndice(int _x, int _y);

public:
	TileGraph();
	TileGraph(int _anchoTileGraph, int _altoTileGraph);
	~TileGraph();

	void configurar(int _anchoTileGraph, int _altoTileGraph);
	Tile* getTileEn(int _x, int _y);

	array<Tile*, 4> get4Vecinos(Tile* _tile);
	array<Tile*, 8> get8Vecinos(Tile* _tile);

	Pacman* getPacman(list<Tile*> &_listTileGraphX);
};




