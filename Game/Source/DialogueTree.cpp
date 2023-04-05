#include "DialogueTree.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"

using namespace std;

void DialogueNode::CleanUp()
{
	for (int j = 0; j < choicesList.size(); j++) { delete choicesList[j]; }
	choicesList.clear();
}


DialogueTree::DialogueTree(bool a)
{
	active = a;
}

bool DialogueTree::UpdateTree(float dt, Module* mod)
{
	// Buttons
	GuiButton* button;
	int fontSize = 16;

	
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		activeNode->choicesList[i]->text.Substitute( "%s", "hola");	// Change %s for player's name - (const char* current word, const char* new word)

		const char* ch_option = activeNode->choicesList[i]->text.GetString();	// SString to const char*	
		activeNode->choicesList[i]->text.Length();
		SDL_Rect bounds = { 0, 130 * i, activeNode->choicesList[i]->text.Length() * fontSize, fontSize + fontSize / 4 };

		button = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, i + GUI_id, ch_option, bounds, fontSize, mod);
		button->state = GuiControlState::NORMAL;
		listDialogueButtons.Add(button);
	}

	return true;
}

void DialogueTree::CleanUp()
{
	for (int j = 0; j < nodeList.size(); j++)
	{
		nodeList[j]->CleanUp();
		delete nodeList[j];
	}
	nodeList.clear();
}