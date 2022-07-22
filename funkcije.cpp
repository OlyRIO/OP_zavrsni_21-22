#include "Player.h"
#include "funkcije.h"
#include "Warrior.h"
#include "Enemy.h"
#include "Wizard.h"

using namespace std;

void ClassChoice()
{
    int choice;
    cout << "Select the class you want to play (1/2):\n";
    cout << "1. Warrior\n" << "2.Wizard\n";
    Player* player;
    cin >> choice;
    if (choice == 1)
    {
        player = new Warrior();
        player->gameplay();
    }
    else if (choice == 2)
    {
        player = new Wizard();
        player->gameplay();
    }
    else
    {
        cout << "Invalid input, please enter 1 for warrior, 2 for wizard.\n";
        ClassChoice();
    }
    
}

/*void WarriorGameplay()
{
    Warrior player;
    int choice;
    cout <<
        "You have chosen to play as the mighty warrior! Your health points have been increased by 10% and you have armor available at your disposal!\n";
    cout <<
        "Armor will decrease incoming physical damage by 1 for each point of armor your character has.\n";
    cout <<
        "-------------------------------------------------------------\n";
    player.show();
    do
    {
        cout <<
            "You lie awake in a cave. There are three corridors in front of you, none different then the other. Which corridor do you choose?(1/2/3)\n";
        cout << "1. Corridor on the left.\n" << "2. Corridor in the middle.\n"
            << "3. Corridor on the right.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "You opt to follow the corridor on the left. The scent of dead animals start to suround you. Suddenly, a goblin jumps out of a hole in the wall!\n";
            Enemy goblin(player.getLevel() * 4, player.getLevel() * 15, player.getLevel() * 0);
            do
            {
                player.showCombat(goblin);
            } while (player.getHealth() > 0 && goblin.getHealth() > 0);
            if (player.getHealth() <= 0)
            {
                cout << "You died!\n";
                playAgain();

            }
            else if (goblin.getHealth() <= 0)
                cout << "Congratulations! You killed the goblin!\n";
            player.levelUp();
            cout << "\n\n\nAfter walking for some time down the corridor, you see a cloaked figure standing in your way. \
                he raises his hand towards you: \"Approach, child, and learn the secret of eternal life.\"\n";
            cout << "What do you want to do?\n";
            cout << "1. Approach the cloaked figure (50% chance for +5 max health)\n";
            cout << "2. Tell the figure you think immortality is an absurd social construct and you prefer a limited lifespan.\
                (33% chance of getting attacked)\n";
            cin >> choice;
            int roll = nasumicni();
            if (choice == 1)
            {
                cout << "You decide to approach the figure.\n";
                if (roll % 2 == 0)
                {
                    cout << "The cloaked figure hands you a trinket best described as a dried prune, but a bit more bloodier. He urges\
                    you to eat it, and you do.\n";
                    cout << "You recieve +5 max health points!\n";
                    player.setMaxHealth(player.getMaxHealth() + 5);
                }
                else
                {
                    cout << "While approaching the cloaked figure, you notice him slowly vanishing in the mist. Upon arriving to the \
                    place where he stood, you find no trace of him left. You can't help but feel tricked.\
                    You continue your journey.\n";
                }

            }
            else if (choice == 2)
            {
                cout << "You decide to tell the figure what you think of its' weak life philosophy.\n";
                if (roll == 1 || roll == 2)
                {
                    cout << "The figure is offended by your gibberish and decides to attack!You rush to defend yourself.\n";
                    Enemy cloakedFigure(player.getLevel() * 4 - 2, player.getLevel() * 15, player.getLevel() * 0 + 1);
                    do
                    {
                        player.showCombat(cloakedFigure);
                    } while (player.getHealth() > 0 && cloakedFigure.getHealth() > 0);
                    if (player.getHealth() <= 0)
                    {
                        cout << "You died!\n";
                        playAgain();
                    }
                    else if (cloakedFigure.getHealth() <= 0)
                        cout << "After a long and weary combat, you manage to outwitt the figure and put him to dust. Behind him \
                        remains a shiny orb that you feel oddly compelled to. You pick it up and put it into your pocket.(+2 damage)\n";
                    player.setDamage(player.getDamage() + 2);
                    player.levelUp();
                    player.show();
                }
                else
                {
                    cout << "Mortal fool, you know not of the things lurking behind the dreams of men and shadows.\n";
                    cout << "With a cryptic message, the figure dissappears. A little confused (but otherwise healthy), you \
                    continue your journey.\n";
                }
            }
            break;
        }
        case 2:
        {
            cout << "Corridor in the middle.\n";
            break;
        }
        case 3:
        {
            cout << "Corridor on the right.\n";
            break;
        }
        default:
        {
            cout << "Wrong choice! Please enter a number 1-3.\n";
            break;
        }

        }
        cout << "You reach the end of the corridor. In the middle of the room, a horned demon is sitting and gazing you with his \
        flaming red eyes.\n\"I've been waiting for you,\" he says. Without breaking eye contact, he pulls a two-faced axe from his \
           back. You prepare for combat.\n";
        Enemy finalBoss(player.getLevel() * 4, player.getLevel() * 15, player.getLevel() * 0 + 1);
        do
        {
            player.showCombat(finalBoss);
        } while (player.getHealth() > 0 && finalBoss.getHealth() > 0);
        if (player.getHealth() <= 0)
        {
            cout << "You died!\n";
            playAgain();
        }
        else if (finalBoss.getHealth() <= 0)
        {
            cout << "After what seemed like a lifetime of drawn out combat, your last slice brings the demon to its' knees.\
            \"This is not over,\"he snarls, \"The world of mortals shall meet its doom!\" With continued muttering in Latin, \
            the demon slowly crumbles down and dies.\n";
            cout << "Congratulations! You win!\n";
            playAgain();
        }


    } while (choice != 1 && choice != 2 && choice != 3);

}

*/

int nasumicni()
{
    srand(time(0));
    int a = rand() % 6 + 1;
    return a;
}
void playAgain()
{
    cout << "Play again?(y/n)";
    char pick;
    cin >> pick;
    if (pick == 'y')
        ClassChoice();
    else if (pick == 'n')
        exit(0);
}
void WizardGameplay()
{
    Wizard player;
    int choice;
    cout <<
        "You have chosen to play as the mysterious wizard! You gain mighty mana at your disposal, but start with decreased\
         damage attribute!\n";
    cout <<
        "Mana is used for casting spells.\n";
    cout <<
        "\n";
    player.show();
    do
    {
        cout <<
            "You lie awake in a cave. There are three corridors in front of you, none different then the other. Which corridor do you choose?(1/2/3)\n";
        cout << "1. Corridor on the left.\n" << "2. Corridor in the middle.\n"
            << "3. Corridor on the right.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "You opt to follow the corridor on the left. The scent of dead animals start to suround you. Suddenly, a goblin jumps out of a hole in the wall!\n";
            Enemy goblin(player.getLevel() * 4, player.getLevel() * 15, player.getLevel() * 0);
            do
            {
                player.showCombat(goblin);
            } while (player.getHealth() > 0 && goblin.getHealth() > 0);
            if (player.getHealth() <= 0)
            {
                cout << "You died!\n";
                playAgain();

            }
            else if (goblin.getHealth() <= 0)
                cout << "Congratulations! You killed the goblin!\n";
            player.levelUp();
            cout << "\n\n\nAfter walking for some time down the corridor, you see a cloaked figure standing in your way. \
                he raises his hand towards you: \"Approach, child, and learn the secret of eternal life.\"\n";
            cout << "What do you want to do?\n";
            cout << "1. Approach the cloaked figure (50% chance for +5 max health)\n";
            cout << "2. Tell the figure you think immortality is an absurd social construct and you prefer a limited lifespan.\
                (33% chance of getting attacked)\n";
            cin >> choice;
            int roll = nasumicni();
            if (choice == 1)
            {
                cout << "You decide to approach the figure.\n";
                if (roll % 2 == 0)
                {
                    cout << "The cloaked figure hands you a trinket best described as a dried prune, but a bit more bloodier. He urges\
                    you to eat it, and you do.\n";
                    cout << "You recieve +5 max health points!\n";
                    player.setMaxHealth(player.getMaxHealth() + 5);
                    player.heal();
                }
                else
                {
                    cout << "While approaching the cloaked figure, you notice him slowly vanishing in the mist. Upon arriving to the \
                    place where he stood, you find no trace of him left. You can't help but feel tricked.\
                    You continue your journey.\n";
                }

            }
            else if (choice == 2)
            {
                cout << "You decide to tell the figure what you think of its' weak life philosophy.\n";
                if (roll == 1 || roll == 2)
                {
                    cout << "The figure is offended by your gibberish and decides to attack!You rush to defend yourself.\n";
                    Enemy cloakedFigure(player.getLevel() * 4 - 2, player.getLevel() * 15, player.getLevel() * 0 + 1);
                    do
                    {
                        player.showCombat(cloakedFigure);
                    } while (player.getHealth() > 0 && cloakedFigure.getHealth() > 0);
                    if (player.getHealth() <= 0)
                    {
                        cout << "You died!\n";
                        playAgain();
                    }
                    else if (cloakedFigure.getHealth() <= 0)
                        cout << "After a long and weary combat, you manage to outwitt the figure and put him to dust. Behind him \
                        remains a shiny orb that you feel oddly compelled to. You pick it up and put it into your pocket.(+2 damage)\n";
                    player.setDamage(player.getDamage() + 2);
                    player.levelUp();
                    player.show();
                }
                else
                {
                    cout << "Mortal fool, you know not of the things lurking behind the dreams of men and shadows.\n";
                    cout << "With a cryptic message, the figure dissappears. A little confused (but otherwise healthy), you \
                    continue your journey.\n";
                }
            }
            break;
        }
        case 2:
        {
            cout << "Corridor in the middle.\n";
            break;
        }
        case 3:
        {
            cout << "Corridor on the right.\n";
            break;
        }
        default:
        {
            cout << "Wrong choice! Please enter a number 1-3.\n";
            break;
        }

        }
        cout << "You reach the end of the corridor. In the middle of the room, a horned demon is sitting and gazing you with his \
        flaming red eyes.\n\"I've been waiting for you,\" he says. Without breaking eye contact, he pulls a two-faced axe from his \
           back. You prepare for combat.\n";
        Enemy finalBoss(player.getLevel() * 4, player.getLevel() * 15, player.getLevel() * 0 + 1);
        do
        {
            player.showCombat(finalBoss);
        } while (player.getHealth() > 0 && finalBoss.getHealth() > 0);
        if (player.getHealth() <= 0)
        {
            cout << "You died!\n";
            playAgain();
        }
        else if (finalBoss.getHealth() <= 0)
        {
            cout << "After what seemed like a lifetime of drawn out combat, your last slice brings the demon to its' knees.\
            \"This is not over,\"he snarls, \"The world of mortals shall meet its doom!\" With continued muttering in Latin, \
            the demon slowly crumbles down and dies.\n";
            cout << "Congratulations! You win!\n";
            playAgain();


        }


    } while (choice != 1 && choice != 2 && choice != 3);

}