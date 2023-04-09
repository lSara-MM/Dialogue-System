#include "DialogueTree.h"

#include "Input.h"
#include "Render.h"
#include "Textures.h"
#include "Window.h"

using namespace std;

void DialogueNode::SplitText(SString text_, int fontSize_, int max_chars_line_)
{
	string line = text_.GetString();

	// TODO: adapt text to the text box
	

	trimmed = true;
}


DialogueTree::DialogueTree(bool a)
{
	active = a;
}

bool DialogueTree::UpdateTree(float dt, Module* mod, iPoint pos)
{
	fontSize = 24;
	max_chars_line = fontSize * 3;

	// TODO: Substitute player's name in text and choices if needed
	

	if (!activeNode->trimmed)
	{
		activeNode->SplitText(activeNode->text, fontSize, max_chars_line);
	}

	// TODO: Render dialogue in text box
	

	EventReturn(mod, pos);

	if (!updateOptions)
	{
		updateOptions = UpdateChoices(mod, pos, fontSize);
	}

	return true;
}

bool DialogueTree::UpdateChoices(Module* mod, iPoint pos, int fontSize)
{
	GuiButton* button;

	// TODO: Create buttons for choices
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		
		int h = fontSize + fontSize / 4;
		SDL_Rect bounds = { app->win->GetWidth() - w, pos.y - (h + fontSize) * (i + 1), w, h};
	}

	return true;
}

bool DialogueTree::EventReturn(Module* mod, iPoint pos)
{
	for (int i = 0; i < activeNode->choicesList.size(); i++)
	{
		switch (activeNode->choicesList[i]->eventReturn)
		{
		case DIALOGUE_INPUT:

			if (!app->input->getInput)
			{
				// Get player's input
				app->input->getInput = true;
				updateOptions = true;

				if (app->input->nameEntered)
				{
					activeNode->choicesList[i]->text.Substitute("%x", app->input->playerName.c_str());	// Change %x for player's name - (const char* current word, const char* new word)
					updateOptions = UpdateChoices(mod, pos, fontSize);
				}
			}

			app->render->TextDraw("Player's name:", app->win->GetWidth() / 3, 100, fontSize, { 255, 255, 255 });
			if (!app->input->playerName.empty())
			{
				const char* ch_name = app->input->playerName.c_str();	// SString to const char*	
				app->render->TextDraw(ch_name, app->win->GetWidth() / 3 + fontSize * 7, 100, fontSize, { 255, 255, 255 });
			}

			break;

		case DIALOGUE_SAVE:
			// see on DialogueSystem::OnGuiMouseClickEvent();
			break;
		case DIALOGUE_IF:


			break;
		default:
			return false;
			break;
		}
	}

	return true;
}

void DialogueTree::CleanUp()
{
	// TODO: Clean Up Nodes and choices
}