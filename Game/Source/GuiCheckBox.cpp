#include "GuiCheckBox.h"

GuiCheckBox::GuiCheckBox(uint32 id, SDL_Rect bounds) : GuiControl(GuiControlType::CHECKBOX, id)
{
	this->bounds = bounds;

	checkBoxTex = app->tex->Load("Assets/Textures/checkbox.png");
}

GuiCheckBox::~GuiCheckBox()
{
	delete checkBoxTex;
}

bool GuiCheckBox::Update(float dt)
{
	if (state != GuiControlState::DISABLED)
	{
		app->input->GetMousePosition(mouseX, mouseY);
		//LOG("Mouse x: %d Mouse y: %d", mouseX, mouseY);
		//LOG("bounds.x: %d bounds.h: %d", bounds.x, bounds.y);

		GuiControlState previousState = state;

		if (mouseX >= bounds.x && mouseX <= bounds.x + bounds.w &&
			mouseY >= bounds.y && mouseY <= bounds.y + bounds.h) {

			//state = GuiControlState::FOCUSED;

			if (previousState != state)
			{
				LOG("Change state from %d to %d", previousState, state);
			}

			if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KeyState::KEY_DOWN)
			{
				(state == GuiControlState::NORMAL) ? state = GuiControlState::SELECTED : state = GuiControlState::NORMAL;
			}

			// If mouse button pressed -> Generate event!
			if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KeyState::KEY_UP)
			{
				NotifyObserver();
			}
		}
	}

	return false;
}

bool GuiCheckBox::Draw(Render* render)
{
	SDL_Rect rect = { 0, 0, 0, 0 };
	if (GUI_debug)
	{
		// Draw the right button depending on state
		switch (state)
		{

		case GuiControlState::DISABLED:
		{
			render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 200, 200, 200, 255, true, false);

		} break;

		case GuiControlState::NORMAL:
		{
			render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 0, 0, 255, 255, true, false);

		}	break;

		case GuiControlState::FOCUSED:
		{
			//render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 255, 0, 255, 255, true, false);

		} break;

		case GuiControlState::PRESSED:
		{
			//render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 0, 255, 0, 255, true, false);

		} break;

		case GuiControlState::SELECTED:
			render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 0, 255, 0, 255, true, false);
			break;

		default:
			break;
		}
	}
	else
	{
		// Draw the right CheckBox depending on state
		switch (state)
		{

		case GuiControlState::DISABLED:
		{

		} break;

		case GuiControlState::NORMAL:
		{
			rect = { 0, 0, 30, 30 };
			render->DrawTexture(checkBoxTex, bounds.x, bounds.y, &rect);

		} break;


		case GuiControlState::FOCUSED:
		{

		} break;
		case GuiControlState::PRESSED:
		{

		} break;

		case GuiControlState::SELECTED:
		{
			rect = { 30, 0, 30, 30 };
			render->DrawTexture(checkBoxTex, bounds.x, bounds.y, &rect);
		} break;

		default:
			break;
		}
	}

	return false;
}