# Game Design Document


A game design document is living document which describes the intent of the game design. 
It has two goals, first to document the decisions that have been made about the game and communicate those concepts to the entire team. 
Thus, it needs to be detailed enough for programmers to refer to when they need clarification about an aspect of the game. 
It must be able to be updated as the game is to be built. 
The need to have a game design document increases with the size of the team and length of the project. 

For a student project the intent is to capture as much as possible of your design. 
The game design will be larger than what you can achieve in a semester, but you must then decide what you need to do first. 
This document should be in version control so that you can see it changing and growing. 
Given we are using git you could also use @name to assign parts of the design to individual members of the team.


## Overview
*Petter, Hannah , Nikolai*

### Game Concept
What the game is about? - Move and shoot

### Genre
What other games is it like? - Doom, Quake, Wolfenstein 3D, Ultrakill, Half Life 1

### Target Audience
Who will play it? - Genre fans(?); nostalgic players, people who wanna play such games

### Game Flow Summary
How does the player move through the game? - Move and shoot, leave nothing alive

### Look and Feel
What is the basic look and feel of the game?  What is the visual style? - Pixelated/retro vibe/aesthetic, grotesque feel(gore, blood etc)

## Gameplay and Mechanics
What does the player do? - Move and shoot. Resource management(ammo, health etc). Advanced movement options(double jump, dash). Mix and match strategies for different type of enemies.

### Gameplay
What is the core of the players interaction with the game? - Move and shoot.

#### Game progression
How does the player progress through the experience and how do they know they are making progress? - Distribution of upgrades throughout the game. Progressively harder combat encounters, boss fights etc.

#### Mission/challenge Structure
Is there a heirachy to the challenges in the game? - Hierarchy of fights and enemy types.

#### Puzzle Structure
Are there puzzles, ie challenges that have a correct answer? - Platforming puzzles(?). Enemies are more susceptible to a certain set of strategies comparatively.

#### Objectives
What is the player trying to achieve? - Absolute extinction of enemy threat.

### Mechanics
What are the rules to the game, both implicit and explicit?  
This is the model of the universe that the game works under.  
Think of it as a simulation of a world. How do all the pieces interact?

#### Physics
How does the physical universe work? - Over the top. Enemies can explode. Supernatural physics.

#### Movement
How the player interacts with the game? - Navigate throughout the levels. Shoot and hit things.

#### Objects
What are the objects in the game?
How does the player interact with them? - Shoot'em? Punch'em?

#### Actions
What are the other interactions the player has with the game world?

#### Combat
If there is combat or conflict, how is this specifically modeled? - Different enemies have different behaviours patterns. Strong and slow enemies, flying enemies, glass cannon enemies etc.

#### Economy
What is the economy of the game? How does it work? - Ammo is dispended upon use. Health and ammo can recovered by using pickups. Powerups(?)

#### Screne Flow
A graphical description of how each screne is related to every other and a description of the purpose of each screen. - HUD question mark?

### Game Options
What are the options and how do they affect gameplay and mechanics?

### Replay and Saving

### Cheats and Easter Eggs
 - IDDQD

## The Story, Setting, and Character
80s action man archetype against the horde.

### Story and Narrative
If there is a story component includes back story, plot elements, game progression, and cut scenes. 
Cut scenes descriptions include the actors, the setting, and the storyboard or script.

### Game World
The setting of the game

#### General look and feel of the World
Aesthetics - Pixelated. Pulpy and over-the-top.

#### Areas
including the general description and physical characteristics as well as how it relates to the rest of the world 
(what levels use it, how it connects to other areas).

### Characters
Each character should include the back story, personality, appearance, animations, abilities, relevance to the story and relationship to other characters.

## Levels

### Playing Levels
Each level should include a synopsis, the required introductory material (and how it is provided), the objectives, 
and the details of what happens in the level.  
Depending on the game, this may include the physical description of the map, the critical path that the player needs to take, 
and what encounters are important or incidental.

### Training level
How is onboarding managed? - Frontload a few upgrades to the first few levels. As an upgrade is acquired, an encounter is provided to help familiarize the players with the core mechanics.

## Interface
HUD.

### Visual System
If you have a HUD, what is on it?  What menus are you displaying? What is the camera model? - Essentials(health, ammo, cooldowns etc). 1st person camera.

### Control System
How does the game player control the game?   What are the specific commands? - WASD to move. Spacebar to jump. LCTRL/LSHIFT to dash. Q/E to melee/interact. M1 to fire.

### Audio, Music, Sound Effects

### Help System

## Artificial Intelligence

### Opponent and Enemy AI
The active opponent that plays against the player and therefore requires strategic decision making.

### Non-combat and Friendly Characters

### Support AI

### Player and Collision Detection, Path-finding.

## Technical

### Target Hardware

### Development Hardware and Software (including game engine)

### Network requirements

## Game Art

### Key assets 
How are they being developed.  Intended style.

This is an extension of parts of [cs.unc.edu](http://wwwx.cs.unc.edu/Courses/comp585-s11/585GameDesignDocumentTemplate.docx)
