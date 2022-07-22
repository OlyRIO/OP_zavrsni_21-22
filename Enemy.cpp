#include "Enemy.h"


void Enemy::setArmor(int x)
{
    armor = x;
}
int Enemy::getArmor()
{
    return armor;
}
Enemy::Enemy(int dmg, int mhp, int arm)
{
    setHealth(mhp);
    setDamage(dmg);
    armor = arm;
    setMaxHealth(mhp);
}
void Enemy::show() // funkcija za prikaz protivničkih atributa
{
    std::cout << "Enemy stats:\n";
    std::cout << "HP: " << getHealth() << "/" << getMaxHealth() << "\n";
    std::cout << "Damage: " << getDamage() << "\n";
    std::cout << "Armor: " << getArmor() << "\n";
}
