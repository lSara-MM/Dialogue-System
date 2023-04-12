> [lSara-MM](https://github.com/lSara-MM/Dialogue-System)

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

Some advantages of using this method are:
1. **Character Customization:** Choices made by the player in dialogue can influence their character's personality and traits, allowing the player to create their own unique and personalized story.

2. **Immersion**: Interactivity and the ability to influence the story can increase the feeling of being in control.

3. **Variety in Narrative**: The method can allow for a more complex and in-depth narrative, with multiple subplots and supporting characters who can have their own story arcs.

4. **Variety of Tones**: Dialogue can have different tones, from comical to serious, which can help create a distinctive atmosphere and tone for the game.

5. **Hidden Answers**: Branching dialogue can include hidden or secret answers that are only revealed if the player selects specific options or performs particular actions, which can increase in-game exploration and discovery.

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

| Extra History | Amalie Kae | Game Designer Plays |
| ----------- | ----------- | ----------- |
|[![The Three Pillars of Game Writing - Plot, Character, Lore - Extra Credits](https://i3.ytimg.com/vi/wNNXdoj7cCQ/hqdefault.jpg)](https://www.youtube.com/embed/wNNXdoj7cCQ)|[![Game Writers' Corner - Writing for Video Games: Why it’s different from other industries](https://i3.ytimg.com/vi/GXUrWtGZH3s/hqdefault.jpg)](https://www.youtube.com/watch?v=GXUrWtGZH3s)|[![Most Innovative Dialogue In Games - Game Designer Plays](https://i3.ytimg.com/vi/0a-Im-pCMqE/maxresdefault.jpg)](https://www.youtube.com/watch?v=0a-Im-pCMqE)


## 4. TO DOs
For the handout we will use this example.
![dialogue_project](https://user-images.githubusercontent.com/93879867/230979239-3d7145bb-b907-4927-90d6-da717ad1a915.jpg)


First of all create a module for the dialogue system. That way it will be updated along the game and the own module will manage the GUI buttons for the choices. 

### TODO 1: load dialogue from file

Load the tree with the corresponding ID from file with all its nodes and choices and save it to the **activeTree** Tree. Save as well the **first node** so you can use it to go to the next nodes later.


Load the dialogue tree

```
int DialogueSystem::LoadDialogue(const char* file, int dialogueID)
{
	pugi::xml_parse_result result = dialogues.load_file(file);

	DialogueTree* tree = new DialogueTree(false);

	if (result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file, result.description());
		return -1;
	}
	else
	{		
		pugi::xml_node pugiNode = dialogues.first_child().first_child();

		for (int i = 0; i <= dialogueID && pugiNode != NULL; i++)
		{
			 if (pugiNode.attribute("ID").as_int() == dialogueID)
			 {
				 tree->treeID = pugiNode.attribute("ID").as_int();		
				 tree->activeNode = LoadNodes(pugiNode, tree);
				 activeTree = tree;	 
				 break;
			 }
			 else
			 {
				 pugiNode = pugiNode.next_sibling("dialogueTree");
			 }
		}
	}

	return dialogueID;
}
``` 


Load tree nodes and save first node. Add all nodes to the list in tree

```
DialogueNode* DialogueSystem::LoadNodes(pugi::xml_node& xml_trees, DialogueTree* tree)
{
	DialogueNode* first_node = new DialogueNode;

	for (pugi::xml_node pugiNode = xml_trees.child("node"); pugiNode != NULL; pugiNode = pugiNode.next_sibling("node"))
	{
		DialogueNode* node = new DialogueNode;

		node->nodeID = pugiNode.attribute("id").as_int();
		node->text = pugiNode.attribute("text").as_string();

		LoadChoices(pugiNode, node);

		tree->nodeList.push_back(node);

		if (node->nodeID == 0) { first_node = node; }	// return the first node to set as the active one
	}

	return first_node;
}
```

Load all choices and add them to the list in node

```
void DialogueSystem::LoadChoices(pugi::xml_node& xml_node, DialogueNode* node)
{
	for (pugi::xml_node choice = xml_node.child("choice"); choice != NULL; choice = choice.next_sibling("choice"))
	{
		DialogueChoice* option = new DialogueChoice;
		option->nextNode = choice.attribute("nextNode").as_int();
		option->text = choice.attribute("option").as_string();
	
		option->eventReturn = choice.attribute("eventReturn").as_int();

		node->choicesList.push_back(option);
	}
}
```

### TODO 2: update dialogue

Update the dialogue if there's an existing tree active and render the text box (and whatever assets you may need).

```
if (activeTree != nullptr)
	{
		//Text box
		iPoint pos = { 0, (app->win->GetHeight() - 353) };
		app->render->DrawTexture(textBox_tex, pos.x, pos.y);

		activeTree->UpdateTree(dt, app->dialogueSystem, pos);
		app->guiManager->Draw();
	}
```

### TODO 3: update dialogue pt.2

Create as many buttons as choices has the active node. It's important to use significant numbers as the ID so later on it can be used to identify the choice chosen. 
(Ex. 0-1-2 -> in the choices array, the ID matches the choice position)

```
GuiButton* button;

	// TODO 3: Create buttons for choices
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		const char* ch_option = activeNode->choicesList[i]->text.GetString();	// SString to const char*	
		int w = activeNode->choicesList[i]->text.Length() * fontSize * 0.5 + 10;
		int h = fontSize + fontSize / 4;
		SDL_Rect bounds = { app->win->GetWidth() - w, pos.y - (h + fontSize) * (i + 1), w, h};

		button = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, i, ch_option, bounds, fontSize, mod);
		button->state = GuiControlState::NORMAL;
		listDialogueButtons.Add(button);
	}
```

### TODO 4: handle click events

Set the next node as the active node depending on the clicked choice. In case the decision has to be saved, call the _SaveDialogueState()_ function. 
**Remember to delete the current buttons** to avoid having unnecessary ones that may mess with the IDs.

```
LOG("Event by %d ", control->id);

	// TODO 4: Buttons ID match the choice ID. Use it to access to its attributes
	playerInput = activeTree->activeNode->choicesList[control->id];

	// TODO 4: Save important choices
	if (playerInput->eventReturn == DIALOGUE_SAVE)
	{
		activeTree->activeNode->playerAnswer = control->id;
		SaveDialogueState();
	}

	// Check if last node
	if (playerInput->nextNode != -1)
	{
		// TODO 4: If not last node, set active node next node
		activeTree->activeNode = activeTree->nodeList[playerInput->nextNode];
		activeTree->updateOptions = false;
	} 
	else // If choice leads to the end of the conversation, change active node to last node
	{
		activeTree->activeNode = activeTree->nodeList.at(activeTree->nodeList.size() - 1);
	}
	
	app->guiManager->CleanUp();
```

### TODO 5: render text

The arrray _texts[ ]_ contains the dialogue divided by lines to make it visually more appealing when rendering.

```
// TODO 6: Render dialogue in text box
	size_t lines = activeNode->texts.size();
	for (size_t i = 0; i < lines; i++)
	{
		app->render->TextDraw(activeNode->texts[i].GetString(), pos.x + 100, pos.y + 20 + 50 * i, fontSize, { 255, 255, 255 });
	}
```

Sometimes you may need to trim the text so it fits the textbox...
 
```
int a, b, startIndex = 0;
		for (int j = 0; j <= line.length() / max_chars_line_; j++)	// <= -> in case of decimal, get the round up number 
		{
			a = max_chars_line_ + startIndex;
			b = line.find_first_of(" ", a);	// find first " " (space) from last trimmed to the end. 

			// If we reached the end of the word or the end of the input.
			string temp;
			temp.append(line, startIndex, b - startIndex);	// string text to append, int index start, int size of text to append
			texts.push_back(temp.c_str());
			startIndex = b;
		}
```

Or change a certain word for another based on a variable like the player's name if it can be changed or the amount of currency they have for example. 

```
// TODO 6: Substitute player's name in text and choices if needed
	if (!app->input->playerName.empty())
	{
		activeNode->text.Substitute("%x", app->input->playerName.c_str());
	}
```

### TODO 6: clean ups

Make sure to free everything used to make the dialogue.

```
// TODO 5: Clean Up 
	if (activeTree != nullptr)
	{
		activeTree->nodeList.clear();
		delete activeTree;
		activeTree = nullptr;
	}
```

```
void DialogueTree::CleanUp()
{
	// TODO 5: Clean Up
	for (int j = 0; j < nodeList.size(); j++)
	{
		nodeList[j]->CleanUp();
		delete nodeList[j];
	}
	
	nodeList.clear();
}
```

### TODO 7: save & load

Save

```
bool ret = true;

	// TODO 7: Save player's name and important choices
	pugi::xml_document* saveDoc = new pugi::xml_document();
	pugi::xml_node node = saveDoc->append_child("save_choices");


	pugi::xml_node player = node.append_child("player");

	// save player's name
	player.append_attribute("player_name") = app->input->playerName.c_str();

	// save important choices
	for (size_t i = 0; i < activeTree->nodeList.size(); i++)
	{
		for (int j = 0; j < activeTree->nodeList[i]->choicesList.size(); j++)
		{
			if (activeTree->nodeList[i]->playerAnswer > -1 && activeTree->nodeList[i]->choicesList[j]->eventReturn == 3)
			{
				player = node.append_child("node");
				player.append_attribute("id") = activeTree->nodeList[i]->nodeID;
				player.append_attribute("answer") = activeTree->nodeList[i]->playerAnswer;
				player.append_attribute("text") = activeTree->nodeList[i]->choicesList[activeTree->nodeList[i]->playerAnswer]->text.GetString();
				break;
			}
		}
	}

	ret = saveDoc->save_file("save_dialogue.xml");

	return ret;
```

Load

```
pugi::xml_document gameStateFile;
	pugi::xml_parse_result result = gameStateFile.load_file("save_dialogue.xml");
	pugi::xml_node node = gameStateFile.child("save_choices");
	
	bool ret = true;

	if (result == NULL)
	{
		LOG("Could not load xml file save_dialogue.xml. pugi error: %s", result.description());
		ret = false;
	}
	else
	{
		// TODO 7: Load player's name and important choices from xml
		string temp = node.child("player").attribute("player_name").as_string();
		app->input->playerName = temp.c_str();
		app->input->nameEntered = true;

		for (size_t i = 0; i < activeTree->nodeList.size() && !node.child("node").empty(); i++)
		{
			for (int j = 0; j < activeTree->nodeList[i]->choicesList.size(); j++)
			{
				if (activeTree->nodeList[i]->choicesList[j]->eventReturn == 3)
				{
					activeTree->nodeList[i]->nodeID = node.child("node").attribute("id").as_int();
					activeTree->nodeList[i]->playerAnswer = node.child("node").attribute("answer").as_int();
				}
			}
		}
	}

	return ret;
```

> Have in mind that those functions will only be called when specified and NOT every time the game is saved like the other modules. 

## 5. Conclusions
There are two types of players: the vast majority who won't pay attention to the dialogue because they crave action, and the ones who will carefully read through every word. However, both groups expect the dialogue to be well done. To write good dialogue, keep in mind the tips outlined in part #3 and try to engage your audience in a unique way. This could involve using humor, implementing an original technique to showcase conversations, or anything that differentiates your game from others.


## 6. References
- [defining-dialogue-systems](https://www.gamedeveloper.com/design/defining-dialogue-systems)

- [successful-in-game-dialogue-should-carry-players-forward](https://www.polygon.com/2014/3/17/5519270/successful-in-game-dialogue-should-carry-players-forward#:~:text=%22Conversations%20are%20a%20hallmark%20of,to%20new%20characters%20and%20locations)

- [video-game-dialogue-writing](https://gamedesignlounge.com/video-game-dialogue-writing/)

- [Realistic Dialogue Engine for Video Games](https://ir.lib.uwo.ca/cgi/viewcontent.cgi?referer=https://www.google.co.uk/&httpsredir=1&article=4141&context=etd)

- [A Summary of Research on Intelligent Dialogue Systems](https://iopscience.iop.org/article/10.1088/1742-6596/1651/1/012020/pdf#:~:text=Classification%20of%20dialogue%20systems&text=According%20to%20the%20purpose%20of,and%20small%2Dtalk%20dialogue%20system)

Other projects
- [Marckitus](https://github.com/Marckitus/Dialog-Systems)

- [Xymaru](https://github.com/Xymaru/DialogSystem)

- [Bookfan97](https://github.com/Bookfan97/DialogSystem)


> Link to my github: [lSara-MM](https://github.com/lSara-MM/Dialogue-System)
