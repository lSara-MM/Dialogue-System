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
	return true;
}

bool DialogueSystem::Update(float dt)
{
	for (int i = 0; i < treeList.size(); i++)
	{
		if (treeList[i]->active) { treeList[i]->UpdateTree(dt, app->dialogueSystem); }
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
	for (int i = 0; i < treeList.size(); i++)
	{
		treeList[i]->CleanUp();
		delete treeList[i];
	}

	treeList.clear();

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
				 treeList.push_back(tree);
				 //activeTree = tree;	 
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