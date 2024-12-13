# Boomer Shooter / PRAMS

- Petter Sandvik
- Hannah Burkart
- Nikolai Skaaheim-Grøna

## Gameplay video
This video shows off various gameplay sections of the game to give an idea of the general game functionality.
https://www.dropbox.com/scl/fi/61j3msh3vnqhxfzajyu0j/group-video.mp4?rlkey=zgnuk1cboe13gk503db9n04rn&st=k9nk0jsl&dl=0
#### Main menu and Level 3: https://youtu.be/ooKvDYnENTo

## Group Discussion
### Strengths and weaknesses of Unreal Engine usage
### Strengths
#### Blueprint Visual Scripting
Unreal's Blueprint system allows non-programmers to create complex game logic using a drag-and-drop interface. This makes development more accessible and lets team members contribute regardless of coding experience.

#### Pre-Built Features
The engine provides many pre-built elements, like character controllers and collision handling, which significantly speed up development. These tools allowed us to focus on unique aspects of our game instead of building everything from scratch.

#### High-Quality Graphics
Unreal Engine excels in producing high-quality graphics with advanced lighting and shading systems. Its real-time ray tracing, detailed material editor, and post-processing effects like motion blur and depth of field make it easy to create photorealistic visuals. This capability allows developers to achieve stunning, high-fidelity graphics with minimal effort, making Unreal a popular choice for AAA games and high-end projects. However, for our retro shooter, this level of graphic quality wasn't really necessary, as our focus was more on gameplay and nostalgic visuals rather than cutting-edge realism.

### Weaknesses
#### Limited and Inconsistent Documentation
One major issue we ran into was Unreal Engine’s documentation. While it’s available, it often lacks detail or doesn’t cover everything we needed. Several times, the official docs were too vague, so we had to turn to community forums, Discord groups, or Reddit to find solutions. While the community is generally helpful, relying on external sources for important information can be time-consuming and frustrating.

#### Limited and Outdated Tutorials
Unreal Engine has fewer tutorials compared to Unity, and many of the ones that are available are outdated. This made learning some parts of the engine harder for our team, especially when dealing with advanced topics like optimization or custom C++ scripting. It would be much easier to learn if there were more up-to-date and comprehensive tutorials.

#### Performance Issues in the Editor
We also faced occasional performance issues in the Unreal Editor. Sometimes the FPS would drop for no clear reason, making it difficult to work smoothly. While this wasn’t always the case, it definitely interrupted our workflow and made development a bit more frustrating than expected.

#### Challenges with 2D Game Development
While Unreal Engine is great for 3D games, it’s not the best choice for 2D games. The tools and workflows are built around 3D, and trying to make a 2D game feels more difficult than it needs to be.

### Process and communication during development
Effective process and communication is vital when working with a team. Thorughout the project, we faced several challenges and discovered strategies to helo us collabborate more effectively. When starting the project, we held group meetings in order to assign a role to each of the team members, as well as setting up a scrumboard to keep track of the tasks we were going to finish. We held group meetings once or twice every week, showing off what we each have done and came up with improvements, and asked questions about each others showcases. We have had some challenges with communication where some liked to work more independently and others joined up for team meetings, but the communication and process during the game development was overall good. We split up the development into branches and specific task per groupmember like leveldesign, weapon and character implementation as well as main menu of the game and the development of the enemies.


### Use of version control systems, ticket tracking, branching, version control
In our project we have used Git and GitHub for version control and storing of our project code. In our group there was however a large difference between members in knowlegde and experience with using Git, so this is also reflected in our usage of Git. So not everything is optimal in this aspect.

#### Issue tracking
When we started working on the project we made a variety of different issues including what we saw as the main sections neccessary for making the game. These sections could cover a broad aspect of them. For example we had Level Design, HUD, Enemy AI Programming and Gameplay Programming. Because of this there werent that many issues made in general. At that stage we also distributed 4 issues for each group member that we planned to follow, but in the end we had to move members over to different issues to make everything work out. Since that initial creation of issues there were only a couple additional ones created like Main Menu, and an issue opened for a playtesting session. Use of smart commits were hardly uses to refer to specific issues since commits in general were rarely done by majority of members.

#### Branching strategy
For branching strategy there was a difference between each member. Some members did all their work in one single branch that they never moved out of, while others features or sections of their work down into individual branches. In retrospect the branching strategy should likely have been discussed more to settle on one approach at the beginning of the project.

#### Merging branches
Merges were mainly conducted when sections that group members had been working on were finished up. In some situations, group members wanted/required something that was being worked on in another branch. In such cases merges would be done between development branches instead of merging into main, to avoid merging incomplete functionality to the main branch. For the merges themselves, not all members took use of the pull request functionality of GitHub, and just straight up moved their changes directly to main despite using pull requests being the best option. Using pull requests you can more easily track changes being done and potentially easily revert them. Again, in retrospect this should likely have been discussed more clearly in the beginning.
#### Challenges and reflection
Overall our use of version control was not great during the course of the project. We realize that a more clear strategy should have been chosen in the start reflecting group members experience and knowledge. In some cases it would be cleaner if all members used the same strategies even if there existed better alternatives.
