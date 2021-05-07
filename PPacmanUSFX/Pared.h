#pragma once
#include "GameObject.h"
class Pared :
    public GameObject
{

public:
    Pared(Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

};

