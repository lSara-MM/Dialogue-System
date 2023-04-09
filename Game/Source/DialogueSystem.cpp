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

	// TODO 4: Buttons ID match the choice ID. Use it to access to its attributes
	

	// TODO 4: Save important choices
	

	// Check if last node
	if (playerInput->nextNode != -1)
	{
		// TODO 4: If not last node, set active node next node
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
	// TODO 5: Clean Up 

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
		// TODO 1: Load the dialogue tree
		
	}

	return dialogueID;
}

DialogueNode* DialogueSystem::LoadNodes(pugi::xml_node& xml_trees, DialogueTree* tree)
{
	DialogueNode* first_node = new DialogueNode;

	// TODO 1: Load tree nodes and save first node. Add all nodes to the list in tree
	

	return first_node;
}

void DialogueSystem::LoadChoices(pugi::xml_node& xml_node, DialogueNode* node)
{
	// TODO 1: Load all choices and add them to the list in node

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

		app->input->playerName = temp.c_str();
		app->input->nameEntered = true;

		
	}

	return ret;
}

bool DialogueSystem::SaveDialogueState()
{
	bool ret = true;

	// TODO 1: Save player's name and important choices
	
	return ret;
}