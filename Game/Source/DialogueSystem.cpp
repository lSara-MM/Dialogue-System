#include "DialogueSystem.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"
#include "Window.h"

DialogueSystem::DialogueSystem() : Module()
{
	name.Create("dialogue");
}

DialogueSystem::~DialogueSystem()
{
}

bool DialogueSystem::Awake(pugi::xml_node& config)
{
	LOG("Loading Dialogue System");
	bool ret = true;
	textBox_path = config.attribute("textBoxBg").as_string();

	return ret;
}

bool DialogueSystem::Start()
{
	textBox_tex = app->tex->Load(textBox_path);
	return true;
}

bool DialogueSystem::Update(float dt)
{
	//for (int i = 0; i < treeList.size(); i++)
	//{
	//	if (treeList[i]->active)
	//	{
	//		// Text box
	//		iPoint pos = { 0, (app->win->GetHeight() - 353) };
	//		app->render->DrawTexture(textBox_tex, pos.x, pos.y);

	//		treeList[i]->UpdateTree(dt, app->dialogueSystem, pos);
	//	}
	//}

	if (activeTree != nullptr)
	{
		//Text box
		iPoint pos = { 0, (app->win->GetHeight() - 353) };
		app->render->DrawTexture(textBox_tex, pos.x, pos.y);

		activeTree->UpdateTree(dt, app->dialogueSystem, pos);
		app->guiManager->Draw();
	}

	return true;
}

bool DialogueSystem::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Event by %d ", control->id);

	// TODO: Buttons ID match the choice ID. Use it to access to its attributes
	playerInput = activeTree->activeNode->choicesList[control->id];

	// TODO: Save important choices
	if (playerInput->eventReturn == DIALOGUE_SAVE)
	{
		activeTree->activeNode->playerAnswer = control->id;
		SaveDialogueState();
	}

	// Check if last node
	if (playerInput->nextNode != -1)
	{
		activeTree->activeNode = activeTree->nodeList[playerInput->nextNode];
		activeTree->updateOptions = false;
	} 
	else // If choice leads to the end of the conversation, change active node to last node
	{
		activeTree->activeNode = activeTree->nodeList.at(activeTree->nodeList.size() - 1);
	}
	
	app->guiManager->CleanUp();

	return true;
}

bool DialogueSystem::CleanUp()
{
	// TODO: Clean Up 
	if (activeTree != nullptr)
	{
		activeTree->nodeList.clear();
		delete activeTree;
		activeTree = nullptr;
	}

	app->input->getInput = false;
	app->input->nameEntered = false;
	app->input->playerName.clear();

	app->guiManager->CleanUp();

	return true;
}


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
		// TODO: Load the dialogue tree
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

DialogueNode* DialogueSystem::LoadNodes(pugi::xml_node& xml_trees, DialogueTree* tree)
{
	DialogueNode* first_node = new DialogueNode;

	// TODO: Load tree nodes and save first node. Add all nodes to the list in tree
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

void DialogueSystem::LoadChoices(pugi::xml_node& xml_node, DialogueNode* node)
{
	// TODO: Load all choices and add them to the list in node
	for (pugi::xml_node choice = xml_node.child("choice"); choice != NULL; choice = choice.next_sibling("choice"))
	{
		DialogueChoice* option = new DialogueChoice;
		option->nextNode = choice.attribute("nextNode").as_int();
		option->text = choice.attribute("option").as_string();
	
		option->eventReturn = choice.attribute("eventReturn").as_int();

		node->choicesList.push_back(option);
	}
}


bool DialogueSystem::LoadDialogueState()
{
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
		// TODO: Load player's name and important choices
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
}

bool DialogueSystem::SaveDialogueState()
{
	bool ret = true;

	// TODO: Save player's name and important choices
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
}