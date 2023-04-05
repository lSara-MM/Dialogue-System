#include "DialogueTree.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"
#include "Window.h"

using namespace std;

void DialogueNode::SplitText(SString text_, int fontSize_, int max_chars_line_)
{
	string line = text_.GetString();

	if (text_.Length() > max_chars_line_)
	{
		int i, startIndex = 0;
		for (int j = 0; j <= line.length() / max_chars_line_; j++)
		{
			i = max_chars_line_ + startIndex;
			int x = line.find_first_of(" ", i);

			// If we reached the end of the word or the end of the input.
			if (line[x])
			{
				string temp;
				temp.append(line, startIndex, x);
				texts.push_back(temp.c_str());
				startIndex = i;
			}
		}
	}
	else
	{
		texts.push_back(line.c_str());
	}

	trimmed = true;
}

void DialogueNode::CleanUp()
{
	for (int j = 0; j < choicesList.size(); j++) { delete choicesList[j]; }
	choicesList.clear();
}


DialogueTree::DialogueTree(bool a)
{
	active = a;
}

bool DialogueTree::UpdateTree(float dt, Module* mod, iPoint pos)
{
	fontSize = 24;
	max_chars_line = fontSize * 3;

	if (!activeNode->trimmed) { activeNode->SplitText(activeNode->text, fontSize, max_chars_line); }

	size_t lines = activeNode->texts.size();
	for (size_t i = 0; i < lines; i++)
	{
		app->render->TextDraw(activeNode->texts[i].GetString(), pos.x + 100, pos.y + 20 + 50 * i, fontSize, { 255, 255, 255 });
	}


	ChoiceInput(mod, pos);

	if (!updateOptions) { updateOptions = UpdateNodes(mod, pos, fontSize); }

	return true;
}

bool DialogueTree::UpdateNodes(Module* mod, iPoint pos, int fontSize)
{
	GuiButton* button;

	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		const char* ch_option = activeNode->choicesList[i]->text.GetString();	// SString to const char*	
		int w = activeNode->choicesList[i]->text.Length() * fontSize * 0.5 + 10;
		int h = fontSize + fontSize / 4;
		SDL_Rect bounds = { app->win->GetWidth() - w, pos.y - (h + fontSize) * (i + 1), w, h};

		button = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, i + GUI_id, ch_option, bounds, fontSize, mod);
		button->state = GuiControlState::NORMAL;
		listDialogueButtons.Add(button);
	}

	return true;
}

bool DialogueTree::ChoiceInput(Module* mod, iPoint pos)
{
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		if (activeNode->choicesList[i]->eventReturn == 2)
		{
			if (!app->input->getInput)
			{
				// Get player's input
				app->input->getInput = true;
				updateOptions = true;

				if (app->input->nameEntered)
				{
					activeNode->choicesList[i]->text.Substitute("%s", app->input->playerName.c_str());	// Change %s for player's name - (const char* current word, const char* new word)
					updateOptions = UpdateNodes(mod, pos, fontSize);
				}
			}

			app->render->TextDraw("Player's name:", app->win->GetWidth() / 3, 100, fontSize, { 255, 255, 255 });
			if (!app->input->playerName.empty())
			{
				const char* ch_name = app->input->playerName.c_str();	// SString to const char*	
				app->render->TextDraw(ch_name, app->win->GetWidth() / 3 + fontSize * 7, 100, fontSize, { 255, 255, 255 });
			}
		}
		else
		{
			return false;
		}
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