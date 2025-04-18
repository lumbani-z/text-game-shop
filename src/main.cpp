#include <iostream> // I need to include the I/O libray for input and output
#include <SFML/Audio.hpp> // Include SFML Audio module
#include <cstdlib>

// Sturcture for Player character
struct Player{
    std::string name;   // This is the name of the player
    int health;         // This is the health of the player
    int xp;             // This is the experience points of the player
    std::string inventory[10]; // This is the inventory of the player
    int inventoryCount = 0; // This is the number of items in the inventory
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

    // Instance of the pPlayer struct
    Player player;
    player.health = 100; // Default value for HP

    //  std::cout is used to print to the console
    //  std::endl is used to end the line
    //  cout means character output stream
    //  endl means end line
    system("cls");
    std::cout << "Welcome to the Dragon Realm" << std::endl;

    // We ask the player for their name
    std::cout << "Before we begin, what is your name adventurer? ";
    std::cin >> player.name;

    // We greet the player with their name
    std::cout << "Welcome, " << player.name << ", to the Dragon Realm!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // int choice holds the player's decision
    int choice;
    // int nestedchoice holds the user's nested decision
    int nestedChoice;
    // The player is exploring
    bool exploring = true;

    // You can choose to go to one of three locations: 1) Moonlight Markets. 2) Grand Library. 3) Infinity Lake
    std::cout << "As you begin your adventure, you must choose where to start" << std::endl;
    
    while(exploring){
        
        std::cout << "Where will you go?" << std::endl;
        std::cout << "1. Moonlight Markets" << std::endl;
        std::cout << "2. Grand Library" << std::endl;
        std::cout << "3. Infinity Lake" << std::endl;
        std::cout << "4. Exit the game" << std::endl;
        std::cout << "Please enter your choice [1-4]: " << std::endl;
        std::cin >> choice; // Logs the user's choice

        // Checks the user's choice and diplays one of the following messages
        if (choice == 1){
            std::cout << "You have chosen Moonlight Markets!" << std::endl;
        }
        else if (choice == 2){
            std::cout << "You have chosen Grand Library!" << std::endl;
        }
        else if (choice == 3){
            std::cout << "You have chosen Infinity Lake!" << std::endl;

            // Introduce Infinity Lake, and create a scenario
            std::cout << player.name << " arrives at Infinity Lake. " << std::endl;
            std::cout << "Like the name suggests, you are greeted by a seemingly endless mass of water." << std::endl;
            std::cout << "No matter how you look, it seems to extend forever." << std::endl;
            std::cout << "As you take in your surroundings, a woman approaches you from behind." << std::endl;
            std::cout << "She taps you shoulder to get your attention: " << std::endl;
            std::cout << "'Sorry to bother you, but could I ask for your assistance?'" << std::endl;
            std::cout << "You've never met this woman before... obviously. What will you do?" << std::endl;
            
            // Log the user's choice. 
            std::cout << "1. Pretend you didn't hear her." << std::endl;
            std::cout << "2. Make up an excuse and walk away." << std::endl;
            std::cout << "Please enter your choice [1-2]: " << std::endl;
            std::cin >> nestedChoice; // Logs the user's choice

            // If the user chooses 1, they pretend they do not hear the woman. 
            // If the user chooses 2, they acknowledge the woman but try to create an excuse to get away. 

            // Evaluate the user's nestedChoice
            if (nestedChoice == 1){
                std::cout << "You pretend to not hear the woman..." << std::endl;
                std::cout << "Thinking you didn't hear her, the woman asks again:" << std::endl;
                std::cout << "'Um... Excuse me?'" << std::endl;
                std::cout << "She's still trying to get your attention..." << std::endl;
                std::cout << "You realize now that it's too late to correct course." << std::endl;
                std::cout << "As you continue to ignore her, you start to wond- Oh" << std::endl;
                std::cout << "She's gone." << std::endl;
            }
            else if (nestedChoice == 2){
                std::cout << "You've decided to talk your way out of this encounter" << std::endl;
                std::cout << "Thinking you didn't hear her, the woman asks again:" << std::endl;
                std::cout << "'Um... Excuse me?'" << std::endl;
                std::cout << "She's still trying to get your attention..." << std::endl;
                std::cout << "It's now or never " << player.name << "." << std::endl;
                std::cout << "You turn toward the woman." << std::endl;
                std::cout << "..." << std::endl;
                std::cout << "..." << std::endl;
                std::cout << "..." << std::endl;
                std::cout << "You didn't think of an excuse..." << std::endl;
                std::cout << "Clearly puzzled by your behavior, the woman remarks:" << std::endl;
                std::cout << "'You know what, never mind.' " << std::endl;
                std::cout << "The woman turns to leave." << std::endl;
                std::cout << "You notice a silver coin drop from her bag as she walks away..." << std::endl;      
                std::cout << "You pick it up and add it to your inventory." << std::endl;      
                player.inventory[player.inventoryCount] = "Coin"; // Add the coin to the inventory
                player.inventoryCount++; // Increment the inventory count

                std::cout << player.name << "'s Inventory:" << std::endl;
                for (int i = 0; i < player.inventoryCount; i++){
                    if (!player.inventory[i].empty()){
                    std::cout << "- " << player.inventory[i] << std::endl; // Display the inventory
                    }
                }
            }
        }
        // If the user decides to quit the game
        else if (choice == 4){
            exploring = false;
        }
        else {
            std::cout << "Invalid choice" << std::endl;
        }
    }

    music.stop(); // Stop the music when the game ends

    // Return 0 signifies that the program has ended successfully
    return 0;
}
