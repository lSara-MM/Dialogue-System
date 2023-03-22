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
	if (activeNode) 
	{
		for (int i = 0; i < treesList[activeTreeID]->nodeList.size(); i++)
		{
			if (activeNode->choicesList[playerInput]->nextNode == treesList[activeTreeID]->nodeList[i]->nodeID)
			{
				activeNode = treesList[activeTreeID]->nodeList[i];
				break;
			}
		}
	}

	app->guiManager->Draw();
	return true;
}

bool DialogueSystem::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Event by %d ", control->id);

	app->audio->PlayFx(control->fxControl);

	switch (control->id)
	{
	case 1:
		LOG("Button Close settings click");
		
		break;
	case 2:
		LOG("Slider music click");
		break;
	case 3:
		LOG("Slider fx click");
		break;
	case 10:
		LOG("Button Exit game click");
		//exit = true;
		break;
	}

	return true;
}

bool DialogueSystem::CleanUp()
{
	return true;
}


DialogueTree* DialogueSystem::LoadDialogue(const char* file, int dialogueID)
{
	pugi::xml_parse_result result = dialogues.load_file(file);

	DialogueTree* tree = new DialogueTree;

	if (result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file, result.description());
		return nullptr;
	}
	else
	{
		pugi::xml_node pugiNode = dialogues.first_child();

		for (int i = 1; i < dialogueID && pugiNode != NULL; i++)
		{
			 if (pugiNode.attribute("ID").as_int() == dialogueID)
			 {
				 tree->treeID = pugiNode.attribute("ID").as_int();
				 LoadNodes(pugiNode, tree);
				 treesList.push_back(tree);
				 break;
			 }
			 else
			 {
				 pugiNode = pugiNode.next_sibling("Dialogue");
			 }
		}
	}

	return tree;
}

bool DialogueSystem::LoadNodes(pugi::xml_node& trees, DialogueTree* ptrTree)
{
	for (pugi::xml_node pugiNode = trees.child("node"); pugiNode != NULL; pugiNode = pugiNode.next_sibling("node"))
	{
		DialogueNode* node = new DialogueNode;
		node->text = pugiNode.attribute("text").as_string();
		node->nodeID = pugiNode.attribute("id").as_int();
		LoadChoices(pugiNode, node);
		ptrTree->nodeList.push_back(node);
	}

	return true;
}

bool DialogueSystem::LoadChoices(pugi::xml_node& response, DialogueNode* answers)
{
	for (pugi::xml_node option = response.child("dialogue"); option != NULL; option = option.next_sibling("dialogue"))
	{
		DialogueChoice* selection = new DialogueChoice;
		selection->text = option.attribute("option").as_string();
		selection->nextNode = option.attribute("nextNode").as_int();
		answers->choicesList.push_back(selection);
		answers->answersList.push_back((option.attribute("option").as_string()));
	}

	return true;
}