# Derivative of Pix - OOP Project
This project is a basic level two dimensional implementation of Minecraft game. It contains three screens:
- Home Screen - When the executable file is ran, the home screeen appears up. It has 2 options, **Play** which directs us to play screen (discussed later) and the **Exit** option which closes the game.
- Game Screen - This screen is where the user interacts with the player and moves it. It creates the whole game environment which is being discussed below in "How to Play" section.
- Storage Screen - This screen is accessed via game screen and its details can be found in the "How to Play" section below

# How to Play
In order to play the game, run the given executable file and the home screen will pop up. Clcik play which will take you to the game screen. in the game screen, we can see the player initally standing in the middle and 4 horizontal layers of blocks. The player can move left to right and in order to make the player move, press the left and the right krys of the keyboard to make the player move in the corresponding direction.
As the player gets closer to the left or the right side of the screen, the screen starts shifiting and random blocks are being generated as the player keeps movving. This screen strecthes infinitely from the left to right and the blocks keeps on generating as we move. The player can also perform certain actions which are as follows:
- Player Jumps by pressing the space bar
- Player brokes and picks up the block by pressing the left mouse button with cursor on the block. Note that the player should be adjacent to the block to remove it.
- Player places a block when the cursor is on empty space and the left mouse button is pressed. Note that the player can place the block only in the empty spaces that are adjacent to him and only if he has that type of block in his storage.
- Player dies if he falls down and goes below the bottom of the screen. When the player dies, we retrun to the main screen and everything else is resetted.
- There are 12 types of blocks and initially player contains 5 of each type.

There are two options on the top-left of the screen. The **Home** option takes us back to the Home Screen and the **Storage** option takes us to the storage screen. In the storage screen, we can see 12 blocks. In order to select which bolck to place, we have to click on that block. then if we go back to the game screen, we can place that type of block. In order to exit the storage screen, press the escape key.



Minor Issue - The game works fine on the initial screen but as we move to the left or to the right, the placing and breaking of blocks is affected due to some coordinate mapping issues.
