#include "DialogueSystem.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"

DialogueSystem::DialogueSystem() : Module()
{
	name.Create("dialogue");
}

DialogueSystem::~DialogueSystem()
{
}

bool DialogueSystem::Start()
{
	LoadDialogue("dialogue.xml", 1);

	return true;
}

bool DialogueSystem::Update(float dt)
{
	for (int i = 0; i < treesList.size(); i++)
	{
		if (treesList[i]->active) { treesList[i]->UpdateTree(dt, this); }
	}
	
	app->guiManager->Draw();

	return true;
}

bool DialogueSystem::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Event by %d ", control->id);


	switch (control->id)
	{
	case -1:
		LOG("Button Exit game click");
		//playerInput = -1;
		//exit = true;
		break;
	case 0:
		LOG("Button Close settings click");
		playerInput = 0;
		break;

	case 1:
		LOG("Button Close settings click");
		playerInput = 1;
		break;
	case 2:
		LOG("Slider music click");
		playerInput = 2;
		break;
	}

	return true;
}

bool DialogueSystem::CleanUp()
{
	for (int i = 0; i < treesList.size(); i++)
	{
		treesList[i]->CleanUp();
		delete treesList[i];
	}

	treesList.clear();

	return true;
}


int DialogueSystem::LoadDialogue(const char* file, int dialogueID)
{
	pugi::xml_parse_result result = dialogues.load_file(file);

	DialogueTree* tree = new DialogueTree;

	if (result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file, result.description());
		return -1;
	}
	else
	{
		pugi::xml_node pugiNode = dialogues.first_child();

		for (int i = 0; i < dialogueID && pugiNode != NULL; i++)
		{
			 if (pugiNode.attribute("ID").as_int() == dialogueID)
			 {
				 tree->treeID = pugiNode.attribute("ID").as_int();
				 treesList.push_back(tree);

				 tree->activeNode = LoadNodes(pugiNode, tree);
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
	DialogueNode* node = new DialogueNode;
	DialogueNode* first_node = new DialogueNode;

	for (pugi::xml_node pugiNode = xml_trees.child("node"); pugiNode != NULL; pugiNode = pugiNode.next_sibling("node"))
	{
		node->text = pugiNode.attribute("text").as_string();
		node->nodeID = pugiNode.attribute("id").as_int();
		tree->nodeList.push_back(node);

		if (node->nodeID == 0) { first_node = node; }	// return the first node to set as the active one
	}

	return first_node;
}

DialogueChoice* DialogueSystem::LoadChoices(pugi::xml_node& xml_node, DialogueNode* node)
{
	DialogueChoice* option = new DialogueChoice;
	for (pugi::xml_node choice = xml_node.child("dialogue"); choice != NULL; choice = choice.next_sibling("dialogue"))
	{
		option->text = choice.attribute("option").as_string();
		option->nextNode = choice.attribute("nextNode").as_int();
		option->eventReturn = choice.attribute("eventReturn").as_int();

		node->choicesList.push_back(option);
	}

	return option;
}