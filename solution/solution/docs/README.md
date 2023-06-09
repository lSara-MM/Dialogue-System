# Dialogue Systems

## 1. What are dialogue systems

Dialogue systems are a game mechanic used in many games to communicate with the player in a more natural way, usually to guide them through the game and story and keep them involved. This is found in many adventure games and RPG, however, certain video game genres such as dating sims and visual novels are completely based on this mechanic.

In RPGs and adventure games, certain conversations within the game are triggered by in-game events, such as completing a dungeon or obtaining a particular item.


###  1.1 Origin
The core of this mechanic, the dialogue tree, was first described in "The Garden of Forking Paths," a 1941 story by Jorge Luis Borges,  in which the combination book of Ts'ui Pên allows all major outcomes from an event branch into their own chapters.
Later from 1964 to 1966, the first computer dialogue system was showcased in ELIZA and emulated an interaction with a therapist. 

![ELIZA (1964-1966)](https://upload.wikimedia.org/wikipedia/commons/7/79/ELIZA_conversation.png)

## 2. Types of dialogue systems

### 2.1. Non-Branching dialogues
Non-Branching dialogue is the simplest form of interaction with an NPC in which the player has no choices and follows a linear conversation whether as text box, bubble speech or cutscene. Sometimes specific events like the player having a certain item, recently died, has already spoken to that or another NPC, etc. can trigger different lines.

The player only requires to initiate the conversation and sometimes to press a button/key to continue with the dialogue, hence it can feel unengaging and boring.   

**Examples**:

| Final Fantasy VI (1994) | The Legend of Zelda: Ocarina of Time (1998) |
| --- | ----------- |
| ![Final Fantasy VI](https://thumbs.gfycat.com/NegativeSerpentineEgret-max-1mb.gif)| ![The Legend of Zelda: Ocarina of Time (1998)](https://64.media.tumblr.com/7d78bf14f44b5d910e22436b7be146a2/tumblr_n51gbyPgKG1smsowro9_500.gif)|		


### 2.2. Branching dialogue
Dialogue trees are a common technique to simulate dialogue in video games since they allow the player to have a limited number of choices that influence the direction of the conversation, and can lead to different outcomes. The choices are usually presented in a tree-like structure, with branches that branch out depending on the player's responses.

In some games, certain branches of the tree will be inaccessible unless a particular event in the game has occurred or depending on the player’s reputation to the NPC.

![Branching Dialogue Tree](https://i.stack.imgur.com/GEuBj.png)

Typically the options are limited to two or three and oftenly they just end on the same path creating the illusion of free choice to the player.

Despite that, there are some games that use an evolved version whither the player’s choices can impact relationships with other characters, alter the course of the story, and even lead to different endings.   


**Examples**:

| Fallout series | Mass Effect |
| ----------- | ----------- |
| ![Fallout series](https://external-preview.redd.it/f8P_i_fMd-mPtdVyRiFMKOy88ciPVew4CGU9YmJ_W7s.jpg?width=640&crop=smart&auto=webp&s=51194a7f6424204858a10b688b1b05565caa826f) | ![Mass Effect 2007](http://cdn3.whatculture.com/wp-content/uploads/2015/11/3ehM1gNO.gif)|

| Detroit: Become Human (2018) |  |
| ----------- | ----------- |
| ![Detroit: Become Human (2018)](https://i.redd.it/k9tj3vqm4hi31.png) | ![Detroit: Become Human (Choices Tree)](https://www.kotaku.com.au/wp-content/uploads/sites/3/2018/04/detroit-become-human-2.jpg?quality=80&w=1280)|
			

### 2.3. Hub-and-Spokes
In a hub-and-spoke format, the player selects conversation options from a central "hub." Upon selection, the conversation branches out into a series of unique lines and additional response options, until that particular branch has been fully explored. The player then returns to the hub and can select a different option to explore another branch.  

**Examples**:

| Undertale (2015) | The Elder Scrolls V: Skyrim (2011) |
| ----------- | ----------- |
| ![Undertale (2015)](https://i.pinimg.com/originals/fa/0a/fb/fa0afbd0f7d9ec29299b49fa747be4c0.gif) | ![The Elder Scrolls V: Skyrim (2011)](https://www.playthepast.org/wp-content/uploads/2022/02/D_dialogue_I-dont-care-if-you-wrote-it-yourself.jpg)|


### 2.4. Parser-Driven
This method is relatively rare today as the NPC responses aren’t automated and the NPC may ignore or reply something out of context which will break the illusion of a real conversation. 

In a parser-driven dialogue system, the player input their response exactly as they want it to appear, and the system attempts to understand and parse the input. The NPC then responds with one of several predetermined responses or creates a response using a combination of the player's words and pre-set phrases.

**Examples**:

| Façade (2005) | Bot Colony (2010) {speaking or typing} |
| --- | ----------- |
| ![Façade (2005)](https://thumbs.gfycat.com/RigidSlimyCockroach-size_restricted.gif)| ![Bot Colony (2010) {speaking or typing}](https://www.destructoid.com/wp-content/uploads/2020/12/276766-bot1.jpg)|

### 2.5. Systemic Interactions
Some games, rather than relying on traditional dialogue trees or scripted conversations, systemic interactions use the game's mechanics and systems to enable the player to interact with NPCs in unique ways.
This provides a unique approach to dialogue systems in video games, allowing for more organic interactions, letting players engage with the game world and characters in a more dynamic and meaningful way.

**Examples**:

| Stardew Valley (2016) | Spore (2008) |
| --- | ----------- |
| ![Stardew Valley (2016)](https://oyster.ignimgs.com/mediawiki/apis.ign.com/stardew-valley/c/ce/Gift.PNG) | ![Spore (2008)](https://static.wikia.nocookie.net/spore/images/c/cc/Sing.png/revision/latest?cb=20101004171123)|

In "Stardew Valley," the player can interact with NPCs by giving them gifts, completing quests for them, and performing other actions that affect their relationship with the player character. As the relationship grows, the NPC may reveal more information about themselves or the game's story, creating a form of dialogue that is integrated into the gameplay mechanics.


## 3. Dialogue design
### 3.1 Writing
* **Be concise**: avoid long and unnecessary texts as they can easily bore the reader. Keep the dialogue concise and focused on advancing the plot or providing useful information to the player.

   - Don’t: 
     "Hail, noble traveller.  Please, permit me to beseech your aid.  I am Jammers, a peasant in service to Count Argyle.  A pack of wolves have taken to my flock of prized sheep.  I intended to give one to the Count as a tribute for this year’s harvest festival.  If you kill 10 of them, I will reward you with 50 gold pieces."
   - Do:
     "Traveller, help me!  Giant wolves have taken to my flock.  Kill 10 and I will give you 50 gold pieces."

* **Make it character-specific**: give your characters a personality, background, and goals and convey it to their lines. This will help make them feel more real and relatable to the player.

* **Keep it relevant**: Don't include dialogue that doesn't add anything to the story or game mechanics, players will either want to get to the more character centric parts, or to the parts that are immediately relevant to the main story. 

  It is preferable to leave the negligible and redundant parts for the side quests or include them in a way the player can choose whether to read it or not.  

*  **Barks**: The bark refers to short snippets of dialogue, typically one-sentence exclamations, that characters blurt out. It is meant to give the player feedback while making the world feel like a living, responsive entity.

* **A picture speaks a thousand words**: As with any form of writing, it's important to show rather than tell. Use dialogue to reveal character traits or plot points through actions, rather than simply stating them outright.

* **Create interest out of nothing**: make the players question why the NPCs would do or say something. Hint the players about the characters background and possible ulterior motives to pique their interest and get them to analyse the character.

* **Use humor**: Humor can be a great way to add levity to a game, but it can also fall flat if not executed properly. Make sure the humor is appropriate for the tone of the game and the characters involved.

## 4. TO DOs

## 5. References
- [defining-dialogue-systems](https://www.gamedeveloper.com/design/defining-dialogue-systems)

- [successful-in-game-dialogue-should-carry-players-forward](https://www.polygon.com/2014/3/17/5519270/successful-in-game-dialogue-should-carry-players-forward#:~:text=%22Conversations%20are%20a%20hallmark%20of,to%20new%20characters%20and%20locations)

- [video-game-dialogue-writing](https://gamedesignlounge.com/video-game-dialogue-writing/)

- [Realistic Dialogue Engine for Video Games](https://ir.lib.uwo.ca/cgi/viewcontent.cgi?referer=https://www.google.co.uk/&httpsredir=1&article=4141&context=etd)

- [A Summary of Research on Intelligent Dialogue Systems](https://iopscience.iop.org/article/10.1088/1742-6596/1651/1/012020/pdf#:~:text=Classification%20of%20dialogue%20systems&text=According%20to%20the%20purpose%20of,and%20small%2Dtalk%20dialogue%20system)

