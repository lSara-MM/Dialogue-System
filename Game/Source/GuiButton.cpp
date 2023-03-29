#include "GuiButton.h"

GuiButton::GuiButton(uint32 id, SDL_Rect bounds, const char* text, int fontSize) : GuiControl(GuiControlType::BUTTON, id)
{
	this->bounds = bounds;
	this->text = text;
	this->fontSize = fontSize;
}

GuiButton::~GuiButton()
{
}

bool GuiButton::Update(float dt)
{
	if (state != GuiControlState::DISABLED)
	{
		app->input->GetMousePosition(mouseX, mouseY);
		//LOG("Mouse x: %d Mouse y: %d", mouseX, mouseY);
		//LOG("bounds.x: %d bounds.h: %d", bounds.x, bounds.y);

		GuiControlState previousState = state;

		if (mouseX >= bounds.x && mouseX <= bounds.x + bounds.w &&
			mouseY >= bounds.y && mouseY <= bounds.y + bounds.h) {
		
			state = GuiControlState::FOCUSED;
			
			if (previousState != state) 
			{
				//LOG("Change state from %d to %d", previousState, state);
			}

			if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KeyState::KEY_REPEAT)
			{
				state = GuiControlState::PRESSED;
			}

			// If mouse button pressed -> Generate event!
			if (app->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KeyState::KEY_UP)
			{
				NotifyObserver();
			}
		}
		else 
		{
			state = GuiControlState::NORMAL;
		}
	}

	return false;
}

bool GuiButton::Draw(Render* render)
{
	SDL_Rect rect = { 90, 0, 172, 40 };
	int offsetX = 50; int offsetY = 10;

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
		render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 255, 0, 255, 255, true, false);

	} break;

	case GuiControlState::PRESSED:
	{
		render->DrawRectangle({ bounds.x * 2, bounds.y * 2, bounds.w * 2, bounds.h * 2 }, 0, 255, 0, 255, true, false);
		//rect = { 343, 0, 210, 80 };

	} break;

	case GuiControlState::SELECTED:
		break;
	}

	int size = fontSize;
	int x = rect.w - text.Length() * size / 2 - offsetX;
	int y = rect.h - size / 2 + offsetY;

	app->render->TextDraw(text.GetString(), bounds.x + x / 4, bounds.y + y / 4, size);

	return false;
}