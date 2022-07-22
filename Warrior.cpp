#include "Warrior.h"
#include "Enemy.h"
#include "funkcije.h"

void Warrior::showCombat(Enemy& y) //funkcija koja obavlja combat između igrača i neprijatelja, pass by reference
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
    int razlika = y.getDamage() - getArmor() - getBlock(); //računanje damage atributa koji će se nanijeti igraču
    if (razlika < 0) // izbjegavanje "dobijanja" health pointa
        razlika = 0;
    std::cout << "The enemy attacks! He deals " << razlika << " damage!\n";
    setHealth(getHealth() - razlika);
    setBlock(0);
}
void Warrior::spellbook(Enemy& y) //funkcija koja će se implementirati za wizard klasu, u warrior klasi služi za brzo propuštanje poteza dok se program testira
{
    std::cout << "You are a warrior, you can't cast any spells!\n";
    showCombat(y);
}
void Warrior::setArmor(int x)
{
    armor = x;
}
int Warrior::getArmor()
{
    return armor;
}
Warrior::Warrior()
{
    setMaxHealth(getMaxHealth() * 1.1);
    armor = 1;
    setHealth(getMaxHealth());
}
Warrior::~Warrior()
{
};
void Warrior::show()
{
    std::cout << "Character stats:\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "HP: " << getHealth() << "/" << getMaxHealth() << "\n";
    std::cout << "Damage: " << getDamage() << "\n";
    std::cout << "Armor: " << armor << "\n";
}

void Warrior::levelUp()
{
    int roll = nasumicni(), lvlup=0;
    if (roll%3==1)
    {
        std::cout << "Congratulations, you leveled up! Choose your reward: \n";
        std::cout << "1. +"<<getLevel()*5<<" max HP\n" << "2. +" << getLevel() + 1 << " Armor \n";
        std::cin >> lvlup;
        switch (lvlup)
        {
        case 1:
        {
            setMaxHealth(getMaxHealth() + 5);
            std::cout << "You gained "<< getLevel() * 5 <<" max HP and now have " << getMaxHealth() << " max HP!\n";
            break;
        }
        case 2:
        {
            setArmor(getArmor() + 2);
            std::cout << "You gained 2 armor and now have " << getArmor() << " armor!\n";
            break;
        }
        }
    }
    else if (roll % 3 == 0)
    {
        std::cout << "Congratulations, you leveled up! Choose your reward: \n";
        std::cout << "1. +"<<getLevel()<<" damage\n" << "2. +"<< getLevel() + 1<<" Armor \n";
        std::cin >> lvlup;
        switch (lvlup)
        {
        case 1:
        {
            setDamage(getDamage() + getLevel());
            std::cout << "You gained "<< getLevel()<<" damage and now have " << getDamage() << " damage!\n";
            heal();
            break;
        }
        case 2:
        {
            setArmor(getArmor() + getLevel() + 1);
            std::cout << "You gained " << getLevel() + 1 << " armor and now have " << getArmor() << " armor!\n";
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
    setLevel(getLevel() + 1);

}