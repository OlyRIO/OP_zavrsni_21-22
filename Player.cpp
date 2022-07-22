#include "Player.h"
#include "Enemy.h"
#include "funkcije.h"


void Player::attack(Enemy& y) //funkcija koja obavlja napad igrača na protivnika
{
    int difference = getDamage() - y.getArmor();
    if (difference < 0)
        difference = 0;
    std::cout << "You attack the enemy! You deal " << difference << "damage!\n";
    y.setHealth(y.getHealth() - difference);
};
void Player::heal()
{
    setHealth(getMaxHealth());
}

void Player::setHealth(int x)
{
    health = x;
}
int Player::getHealth()
{
    return health;
}
void Player::setMaxHealth(int x)
{
    MaxHealth = x;
}
int Player::getMaxHealth()
{
    return MaxHealth;
}
void Player::setLevel(int x)
{
    level = x;
}
int Player::getLevel()
{
    return level;
}
void Player::setDamage(int x)
{
    damage = x;
}
int Player::getDamage()
{
    return damage;
};
void Player::setBlock(int x)
{
    block = x;
}
int Player::getBlock()
{
    return block;
}
Player::Player()
{
    health = 30;
    MaxHealth = 30;
    level = 1;
    damage = 5;
    block = 0;
}
void Player::levelUp() { std::cout << "Player prazna level up funkcija. \n"; }
void Player::showCombat(Enemy& y) { std::cout << "Player prazna show combat funkcija. \n"; }

Player::~Player()
{
};
void Player::show()
{
    std::cout << "Character stats:\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "HP: " << getHealth() << "/" << getMaxHealth() << "\n";
    std::cout << "Damage: " << getDamage() << "\n";
}

void Player::gameplay()
{
        int choice;
        std::cout <<
            "You have chosen to play as the mighty warrior! Your health points have been increased by 10% and you have armor available at your disposal!\n";
        std::cout <<
            "Armor will decrease incoming physical damage by 1 for each point of armor your character has.\n";
        std::cout <<
            "/***************************************************************/\n";
        this->show();
        do
        {
            std::cout <<
                "You lie awake in a cave. There are three corridors in front of you, none different then the other. Which corridor do you choose?(1/2/3)\n";
            std::cout << "1. Corridor on the left.\n" << "2. Corridor in the middle.\n"
                << "3. Corridor on the right.\n";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "You opt to follow the corridor on the left. The scent of dead animals start to suround you. Suddenly, a goblin jumps out of a hole in the wall!\n";
                Enemy goblin(this->getLevel() * 4, this->getLevel() * 15, this->getLevel() * 0);
                do
                {
                    this->showCombat(goblin);
                } while (this->getHealth() > 0 && goblin.getHealth() > 0);
                if (this->getHealth() <= 0)
                {
                    std::cout << "You died!\n";
                    playAgain();

                }
                else if (goblin.getHealth() <= 0)
                    std::cout << "Congratulations! You killed the goblin!\n";
                this->levelUp();
                std::cout << "\n\n\nAfter walking for some time down the corridor, you see a cloaked figure standing in your way. \
                he raises his hand towards you: \"Approach, child, and learn the secret of eternal life.\"\n";
                std::cout << "What do you want to do?\n";
                std::cout << "1. Approach the cloaked figure (50% chance for +5 max health)\n";
                std::cout << "2. Tell the figure you think immortality is an absurd social construct and you prefer a limited lifespan.\
                (33% chance of getting attacked)\n";
                std::cin >> choice;
                int roll = nasumicni();
                if (choice == 1)
                {
                    std::cout << "You decide to approach the figure.\n";
                    if (roll % 2 == 0)
                    {
                        std::cout << "The cloaked figure hands you a trinket best described as a dried prune, but a bit more bloodier. He urges\
                    you to eat it, and you do.\n";
                        std::cout << "You recieve +5 max health points!\n";
                        this->setMaxHealth(this->getMaxHealth() + 5);
                    }
                    else
                    {
                        std::cout << "While approaching the cloaked figure, you notice him slowly vanishing in the mist. Upon arriving to the \
                    place where he stood, you find no trace of him left. You can't help but feel tricked.\
                    You continue your journey.\n";
                    }

                }
                else if (choice == 2)
                {
                    std::cout << "You decide to tell the figure what you think of its' weak life philosophy.\n";
                    if (roll == 1 || roll == 2)
                    {
                        std::cout << "The figure is offended by your gibberish and decides to attack!You rush to defend yourself.\n";
                        Enemy cloakedFigure(this->getLevel() * 4 - 2, this->getLevel() * 15, this->getLevel() * 0 + 1);
                        do
                        {
                            this->showCombat(cloakedFigure);
                        } while (this->getHealth() > 0 && cloakedFigure.getHealth() > 0);
                        if (this->getHealth() <= 0)
                        {
                            std::cout << "You died!\n";
                            playAgain();
                        }
                        else if (cloakedFigure.getHealth() <= 0)
                            std::cout << "After a long and weary combat, you manage to outwitt the figure and put him to dust. Behind him \
                        remains a shiny orb that you feel oddly compelled to. You pick it up and put it into your pocket.(+2 damage)\n";
                        this->setDamage(this->getDamage() + 2);
                        this->levelUp();
                        this->show();
                    }
                    else
                    {
                        std::cout << "Mortal fool, you know not of the things lurking behind the dreams of men and shadows.\n";
                        std::cout << "With a cryptic message, the figure dissappears. A little confused (but otherwise healthy), you \
                    continue your journey.\n";
                    }
                }
                break;
            }
            case 2:
            {
                std::cout << "Corridor in the middle.\n";
                break;
            }
            case 3:
            {
                std::cout << "Corridor on the right.\n";
                break;
            }
            default:
            {
                std::cout << "Wrong choice! Please enter a number 1-3.\n";
                break;
            }

            }
            std::cout << "You reach the end of the corridor. In the middle of the room, a horned demon is sitting and gazing you with his \
        flaming red eyes.\n\"I've been waiting for you,\" he says. Without breaking eye contact, he pulls a two-faced axe from his \
           back. You prepare for combat.\n";
            Enemy finalBoss(this->getLevel() * 4, this->getLevel() * 15, this->getLevel() * 0 + 1);
            do
            {
                this->showCombat(finalBoss);
            } while (this->getHealth() > 0 && finalBoss.getHealth() > 0);
            if (this->getHealth() <= 0)
            {
                std::cout << "You died!\n";
                playAgain();
            }
            else if (finalBoss.getHealth() <= 0)
            {
                std::cout << "After what seemed like a lifetime of drawn out combat, your last slice brings the demon to its' knees.\
            \"This is not over,\"he snarls, \"The world of mortals shall meet its doom!\" With continued muttering in Latin, \
            the demon slowly crumbles down and dies.\n";
                std::cout << "Congratulations! You win!\n";
                playAgain();
            }


        } while (choice != 1 && choice != 2 && choice != 3);
}

void Player::showRoom()
{
    int opcije;
    std::cout << "You are currently occupying the "; //naziv << ". What will you do?\n\n";
    std::cout << "1. Engage the enemy.\n" << "Try and sneak past the enemy. (30% succes rate)\n\n";
    std::cin >> opcije;
    if (opcije == 1)
    {
        std::cout << "bok.\n";
    }
}