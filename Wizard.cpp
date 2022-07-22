#include "Wizard.h"
#include "Enemy.h"
#include "funkcije.h"

void Wizard::setMana(int x)
{
    mana = x;
}
int Wizard::getMana()
{
    return mana;
}
void Wizard::setMaxMana(int x)
{
    MaxMana = x;
}
int Wizard::getMaxMana()
{
    return MaxMana;
}
Wizard::Wizard()
{
    MaxMana = 10;
    mana = MaxMana;
    setDamage(getDamage() - 1);
}
void Wizard::replenishMana()
{
    setMana(getMaxMana());
}
Wizard::~Wizard()
{};
void Wizard::show()
{
    std::cout << "Character stats:\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "HP: " << getHealth() << "/" << getMaxHealth() << "\n";
    std::cout << "Damage: " << getDamage() << "\n";
    std::cout << "Mana: " << mana << "/" << MaxMana << "\n";
}
void Wizard::spellbook(Enemy& y)
{
    std::cout << "Select a spell you want to cast:\n\n" << "1. Fireball (does 8 damage, costs 5 mana)\n";
    int choice;
    std::cin >> choice;
    if (choice == 1 && getMana() >= 5)
    {
        setMana(getMana() - 5);
        y.setHealth(y.getHealth() - 8);
    }
    else if (getMana() < 5)
    {
        std::cout << "Not enough mana to cast fireball! Please select a different option.\n";
        showCombat(y);
    }
}
void Wizard::showCombat(Enemy& y) //funkcija koja obavlja combat između igrača i neprijatelja, pass by reference
{
    int menu;
    show();
    std::cout << "\n\n";
    y.show();
    std::cout << "Select an action: \n" << "1. Basic attack(deals " << getDamage() << " damage)\n";
    std::cout << "2. Block(blocks " << getLevel() + 5 << " damage)\n";
    std::cout << "3. Cast a spell\n";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
    {
        attack(y);
        break;
    }
    case 2:
    {
        setBlock(getLevel() + 5);
        break;
    }
    case 3:
    {
        spellbook(y);
        break;
    }
    }
    std::cout << "The enemy attacks! He deals " << y.getDamage() << " damage!\n";
    int diff = y.getDamage() - getBlock();
    if (diff < 0)
        diff = 0;
    setHealth(getHealth() - diff);
    setBlock(0);
}
void Wizard::levelUp()
{
    int roll = nasumicni(), lvlup = 0;
    if (roll % 3 == 1)
    {
        std::cout << "Congratulations, you leveled up! Choose your reward: \n";
        std::cout << "1. +" << getLevel() * 5 << " max HP\n" << "2. +" << getLevel() * 5 << " Max Mana \n";
        std::cin >> lvlup;
        switch (lvlup)
        {
        case 1:
        {
            setMaxHealth(getMaxHealth() + 5);
            std::cout << "You gained " << getLevel() * 5 << " max HP and now have " << getMaxHealth() << " max HP!\n";
            break;
        }
        case 2:
        {
            setMaxMana(getMaxMana() + (getLevel() * 5));
            std::cout << "You gained "<< getLevel() * 5<<" Max Mana and now have " << getMaxMana() << " Max Mana!\n";
            break;
        }
        }
    }
    else if (roll % 3 == 0)
    {
        std::cout << "Congratulations, you leveled up! Choose your reward: \n";
        std::cout << "1. +" << getLevel() << " damage\n" << "2. +" << getLevel() * 5 << " Max Mana \n";
        std::cin >> lvlup;
        switch (lvlup)
        {
        case 1:
        {
            setDamage(getDamage() + getLevel());
            std::cout << "You gained " << getLevel() << " damage and now have " << getDamage() << " damage!\n";
            heal();
            break;
        }
        case 2:
        {
            setMaxMana(getMaxMana() + (getLevel() * 5));
            std::cout << "You gained " << getLevel() * 5 << " Max Mana and now have " << getMaxMana() << " Max Mana!\n";
            break;
        }
        }
    }
    else if (roll % 3 == 2)
    {
        std::cout << "Congratulations, you leveled up! Choose your reward: \n";
        std::cout << "1. +" << getLevel() << " damage\n" << "1. +" << getLevel() * 5 << " max HP\n";
        std::cin >> lvlup;
        switch (lvlup)
        {
        case 1:
        {
            setDamage(getDamage() + getLevel());
            std::cout << "You gained " << getLevel() << " damage and now have " << getDamage() << " damage!\n";
            break;
        }
        case 2:
        {
            setMaxHealth(getMaxHealth() + 5);
            std::cout << "You gained " << getLevel() * 5 << " max HP and now have " << getMaxHealth() << " max HP!\n";
            break;
        }
        }
    }
    heal();
    replenishMana();
    setLevel(getLevel() + 1);

}
