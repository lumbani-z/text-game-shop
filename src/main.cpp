#include <iostream> // I need to include the I/O libray for input and output
#include <SFML/Audio.hpp> // Include SFML Audio module
#include <cstdlib>

// Sturcture for Player character
struct Player{
    std::string name;   // This is the name of the player
    int health;         // This is the health of the player
    int xp;             // This is the experience points of the player
    int gold;           // This is the amount of gold the player has
    int level;         // This is the level of the player
    std::string inventory[10]; // This is the inventory of the player
    int inventoryCount = 0; // This is the number of items in the inventory
};

struct Shop{
    std::string name = "The Tutorial Shop";
    std::string inventory[3] = {"Health Potion", "Mana Potion", "Sword"}; // This is the inventory of the shop
    int inventoryCount = 7; // This is the number of items in the shop's inventory
    int potionCost = 10;
    int swordCost = 10;
    int numHealthPotions = 3;
    int numManaPotions = 3;
    int numSwords = 1;
};

// This is my main function
int main() {
    // Load background music
    sf::Music music;
    if (!music.openFromFile("24.wav")) { // Replace with your music file path
        std::cout << "Error: Could not load music file!" << std::endl;
        return -1;
    }
    music.setLooping(true); // Loop the music
    music.play(); // Start playing the music

    // Instance of the player struct
    Player player;
    player.health = 100; // Default value for HP
    player.gold = 100; // Default value for gold
    player.level = 1; // Default value for level
    player.xp = 0; // Default value for XP

    Shop shop;

    //  std::cout is used to print to the console
    //  std::endl is used to end the line
    //  cout means character output stream
    //  endl means end line
    system("cls");
    std::cout << "Welcome to the title screen." << std::endl;
    std::cout << "For this introductory project, you will experience the tutorial shop of an RPG." << std::endl;


    // We ask the player for their name
    std::cout << "Before we begin, what is your name? ";
    std::cin >> player.name;

    // We greet the player


    // int choice holds the player's decision
    int choice;
    // int nestedchoice holds the user's nested decision
    int nestedChoice;
    // The player is shopping
    bool shopping = true;
    bool invalidChoice = false; // Flag for invalid choice

    while(shopping){
        system("cls");
        std::cout << "Welcome to "<< shop.name << std::endl;
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "What will you do?" << std::endl;
        std::cout << "1. Purchase items" << std::endl;
        std::cout << "2. Check status" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Please enter your choice [1-3]: " << std::endl;
        if (invalidChoice){
            std::cout << "Invalid choice!" << std::endl;
            invalidChoice = false; // Reset the invalidChoice flag
        }
        std::cin >> choice; // Logs the user's choice


        // Checks the user's choice and diplays one of the following messages
        if (choice == 1){
                bool buying = true;
                bool noGold = false;
                bool outOfStock = false;
                bool succesfulPurchase = false;
                while(buying){
                    system("cls");
                    std::cout << "Available products!" << std::endl;
                    std::cout << "--------------------------------------------------------" << std::endl;
                    std::cout << "1. Health Potion - 10 Gold" << std::endl;
                    std::cout << "2. Mana Potion - 10 Gold" << std::endl;
                    std::cout << "3. Sword - 10 Gold" << std::endl;
                    std::cout << "4. Back" << std::endl;
                    std::cout << "Please enter your choice [1-4]: " << std::endl;
                    if (noGold){
                        std::cout << "You do not have enough gold!" << std::endl;
                        noGold = false; // Reset the noGold flag
                    }
                    else if (outOfStock){
                        std::cout << "Out of stock!" << std::endl;
                        outOfStock = false; // Reset the outOfStock flag
                    }
                    else if (invalidChoice){
                        std::cout << "Invalid choice!" << std::endl;
                        invalidChoice = false; // Reset the invalidChoice flag
                    }
                    if (succesfulPurchase){
                        std::cout << "You have successfully purchased a " << player.inventory[player.inventoryCount - 1] << "!" << std::endl;
                        succesfulPurchase = false; // Reset the succesfulPurchase flag
                    }

                    std::cin >> nestedChoice; // Logs the user's choice
                    if (std::cin.fail()){
                        std::cin.clear(); // Clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                    }
                    else if (nestedChoice == 1){
                        if (player.gold >= shop.potionCost){
                            if (shop.numHealthPotions > 0){
                                std::cout << "You have purchased a health potion!" << std::endl;
                                player.inventory[player.inventoryCount] = "Health Potion";
                                player.inventoryCount++;
                                player.gold -= shop.potionCost;
                                shop.numHealthPotions--;
                                shop.inventoryCount--;
                                succesfulPurchase = true; // Set the succesfulPurchase flag to true
                            }
                            else{
                                outOfStock = true;
                            }
                        }
                        else{
                            noGold = true;
                        }
                    }
                    else if (nestedChoice == 2){
                        if (player.gold >= shop.potionCost){
                            if (shop.numManaPotions > 0){
                                std::cout << "You have purchased a mana potion!" << std::endl;
                                player.inventory[player.inventoryCount] = "Mana Potion";
                                player.inventoryCount++;
                                player.gold -= shop.potionCost;
                                shop.numManaPotions--;
                                shop.inventoryCount--;
                                succesfulPurchase = true;
                            }
                            else{
                                outOfStock = true;
                            }
                        }
                        else{
                            noGold = true; 
                        }
                    }
                    else if (nestedChoice == 3){
                        if (player.gold >= shop.potionCost){
                            if (shop.numSwords > 0){
                                std::cout << "You have purchased a Sword!" << std::endl;
                                player.inventory[player.inventoryCount] = "Sword";
                                player.inventoryCount++;
                                player.gold -= shop.swordCost;
                                shop.numSwords--;
                                shop.inventoryCount--;
                                succesfulPurchase = true;
                            }
                            else{
                                outOfStock = true;
                            }
                        }
                        else{
                            noGold = true;
                        }
                    }
                    else if (nestedChoice == 4){
                        buying = false;
                    }
                    else{
                        invalidChoice = true;
                    }
                    if (std::cin.fail()){
                        std::cin.clear(); // Clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                        invalidChoice = true;
                    }
                     // Reset the invalidChoice flag
                    //nestedChoice = 0;
                }
            
        }
        else if (choice == 2){
            bool checking = true;
            while(checking){
                system("cls");
                std::cout << player.name << "'s status" << std::endl;
                std::cout << "--------------------------------------------------------" << std::endl;
                std::cout << "Level: " << player.level << std::endl;
                std::cout << "XP: " << player.xp << std::endl;
                std::cout << "Health: " << player.health << std::endl;
                std::cout << "Gold: " << player.gold << std::endl;
                std::cout << "Inventory: " << std::endl;
                if (player.inventoryCount > 0){
                    for (int i = 0; i < player.inventoryCount; i++){
                        if (!player.inventory[i].empty()){
                        std::cout << "- " << player.inventory[i] << std::endl; // Display the inventory
                        }
                    }
                }
                else{
                    std::cout << "No items in inventory." << std::endl;
                }
                if (invalidChoice){
                    std::cout << "Invalid choice!" << std::endl;
                    invalidChoice = false; // Reset the invalidChoice flag
                }
                std::cout << "Enter [1] to go back" << std::endl;
                std::cin >> nestedChoice; 
                if (std::cin.fail()){
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                    invalidChoice = true; // Set the invalidChoice flag
                }
                if (nestedChoice == 1){
                    checking = false;
                }
                else{
                    invalidChoice = true; // Set the invalidChoice flag
                }
                    
                

            }
        }
        // If the user decides to quit the game
        else if (choice == 3){
            shopping = false;
        }
        else {
            if (std::cin.fail()){
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            }
            invalidChoice = true; // Set the invalidChoice flag
        }
    }

    music.stop(); // Stop the music when the game ends

    // Return 0 signifies that the program has ended successfully
    return 0;
}