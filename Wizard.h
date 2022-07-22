#pragma once
#include "Player.h"

class Wizard : public Player
{

private:
    int mana, MaxMana;
public:
    void setMana(int x);
    int getMana();
    void setMaxMana(int x);
    int getMaxMana();
    Wizard();
    virtual ~Wizard();
    void show();
    void spellbook(Enemy& y);
    void replenishMana();
    void showCombat(Enemy& y);
    void levelUp();
};

