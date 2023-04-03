#include "DialogueTree.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"

#include <sstream>

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
	GuiButton* button;
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		const char* ch_option = activeNode->choicesList[i]->text.GetString();

		button = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, i + GUI_id, ch_option, { 180, 130 + 50 * i, 172, 40 }, 10, mod);
		button->state = GuiControlState::NONE;
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