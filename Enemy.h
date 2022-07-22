#pragma once
#include "Player.h"


class Enemy : public Player
{

private: //parametri bitni za combat za protivnika
    int armor;
public: //pripadne getter i setter funkcije
    void setArmor(int x);
    int getArmor();
    Enemy(int dmg, int mhp, int arm);
    void show();

};

