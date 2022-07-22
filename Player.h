#pragma once
#include <iostream>

class Enemy;

class Player
{
private:
    int health, MaxHealth, level, damage, block;
public: 
    void setHealth(int x);
    int getHealth();
    void setMaxHealth(int x);
    int getMaxHealth();
    void setLevel(int x);
    int getLevel();
    void setDamage(int x);
    int getDamage();
    void setBlock(int x);
    int getBlock();
    Player();
    virtual ~Player();
    virtual void show();
    void heal();
    void attack(Enemy& y);
    void gameplay();
    virtual void levelUp();
    virtual void showCombat(Enemy& y);
    void showRoom();

};

