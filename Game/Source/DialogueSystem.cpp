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

	switch (control->id)
	{
	case 0:
		LOG("Option 1 click");
		playerInput = activeTree->activeNode->choicesList[0]->nextNode;
		break;

	case 1:
		LOG("Option 2 click");
		playerInput = activeTree->activeNode->choicesList[1]->nextNode;
		break;
	case 2:
		LOG("Option 3 click");
		playerInput = activeTree->activeNode->choicesList[2]->nextNode;
		break;
	}

	if (playerInput != -1)
	{
		activeTree->activeNode = activeTree->nodeList[playerInput];
		activeTree->updateOptions = false;
	} 
	else
	{
		activeTree->activeNode = activeTree->nodeList.at(activeTree->nodeList.size() - 1);
	}
	
	app->guiManager->CleanUp();

	return true;
}

bool DialogueSystem::CleanUp()
{
	//for (int i = 0; i < treeList.size(); i++)
	//{
	//	treeList[i]->CleanUp();
	//	delete treeList[i];
	//}

	//treeList.clear();

	if (activeTree != nullptr)
	{
		activeTree->CleanUp();
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
		pugi::xml_node pugiNode = dialogues.first_child().first_child();

		for (int i = 0; i <= dialogueID && pugiNode != NULL; i++)
		{
			 if (pugiNode.attribute("ID").as_int() == dialogueID)
			 {
				 tree->treeID = pugiNode.attribute("ID").as_int();
			
				 tree->activeNode = LoadNodes(pugiNode, tree);	
				 //treeList.push_back(tree);
				 activeTree = tree;	 
				 break;
			 }
			 else
			 {
				 pugiNode = pugiNode.next_sibling("dialogue");
			 }
		}
	}
	return dialogueID;
}

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