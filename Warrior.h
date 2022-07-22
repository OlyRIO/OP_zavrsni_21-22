#pragma once
#include "Player.h"
class Player;

class Warrior : public Player
{
private: 
    int armor;
public:  
    void setArmor(int x);
    int getArmor();
    Warrior();
    virtual ~Warrior();
    void show();
    void showCombat(Enemy& y);
    void spellbook(Enemy& y);
    void levelUp();
};

