#include "GuiButton.h"

GuiButton::GuiButton(uint32 id, SDL_Rect bounds, ButtonType bType, const char* text, int fontSize) : GuiControl(GuiControlType::BUTTON, id)
{
	this->bounds = bounds;
	this->text = text;
	this->fontSize = fontSize;
	
	buttonType = bType;

	switch (bType)
	{
	case ButtonType::NONE:
		break;
	case ButtonType::EXTRA_LARGE:
		buttonTex = app->tex->Load("Assets/Textures/extra_long_button.png");
		break;
	case ButtonType::LARGE:
		buttonTex = app->tex->Load("Assets/Textures/long_button.png");
		break;
	case ButtonType::SMALL:
		buttonTex = app->tex->Load("Assets/Textures/small_button.png");
		break;
	default:
		buttonTex = app->tex->Load("Assets/Textures/small_button.png");
		break;
	}		
}

GuiButton::~GuiButton()
{
	delete buttonTex;
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
	SDL_Rect rect = { 0, 0, 0, 0 };
	int offsetX = 0; int offsetY = 0;

	if (GUI_debug)
	{
		if (buttonType == ButtonType::EXTRA_LARGE) { rect = { 90, 0, 172, 40 }; offsetX = 50;	offsetY = 10; }
		if (buttonType == ButtonType::LARGE) { rect = { 90, 0, 90, 27 }; offsetX = 20;	offsetY = 3; }
		if (buttonType == ButtonType::SMALL) { rect = { 90, 0, 26, 28 }; offsetX = -15;	offsetY = 6; }


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
			if (buttonType == ButtonType::EXTRA_LARGE) { rect = { 343, 0, 210, 80 }; }
			if (buttonType == ButtonType::LARGE) { rect = { 180, 0, 120, 40 }; }
			if (buttonType == ButtonType::SMALL) { rect = { 0, 0, 56, 41 }; }

		} break;

		case GuiControlState::SELECTED:
			break;

		default:
			break;
		}
	}
	else
	{
		if (buttonType == ButtonType::EXTRA_LARGE)
		{
			// Draw the right button depending on state
			switch (state)
			{

			case GuiControlState::DISABLED:
			{
				rect = { 528, 0, 172, 40 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::NORMAL:
			{
				rect = { 0, 0, 172, 40 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::FOCUSED:
			{
				rect = { 172, 0, 172, 40 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::PRESSED:
			{
				rect = { 343, 0, 185, 40 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);
				rect = { 343, 0, 210, 80 };

			} break;

			case GuiControlState::SELECTED: //render->DrawRectangle(bounds, 0, 255, 0, 255);
				break;

			default:
				break;
			}

			offsetX = 50;	offsetY = 10;
		}

		if (buttonType == ButtonType::LARGE)
		{
			// Draw the right button depending on state
			switch (state)
			{

			case GuiControlState::DISABLED:
			{
				rect = { 277, 0, 90, 27 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::NORMAL:
			{
				rect = { 0, 0, 90, 27 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::FOCUSED:
			{
				rect = { 90, 0, 90, 27 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::PRESSED:
			{
				rect = { 180, 0, 97, 27 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);
				rect = { 180, 0, 120, 40 };

			} break;

			case GuiControlState::SELECTED: //render->DrawRectangle(bounds, 0, 255, 0, 255);
				break;

			default:
				break;
			}

			offsetX = 20;	offsetY = 3;
		}

		if (buttonType == ButtonType::SMALL)
		{
			// Draw the right button depending on state
			switch (state)
			{

			case GuiControlState::DISABLED:
			{
				rect = { 85, 0, 26, 28 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::NORMAL:
			{
				rect = { 0, 0, 26, 28 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::FOCUSED:
			{
				rect = { 26, 0, 26, 28 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);

			} break;

			case GuiControlState::PRESSED:
			{
				rect = { 52, 0, 33, 28 };
				render->DrawTexture(buttonTex, bounds.x, bounds.y, &rect);
				rect = { 0, 0, 56, 41 };

			} break;

			case GuiControlState::SELECTED: //render->DrawRectangle(bounds, 0, 255, 0, 255);
				break;

			default:
				break;
			}

			offsetX = -15;	offsetY = 6;
		}
	}



	int size = fontSize;
	int x = rect.w - text.Length() * size / 2 - offsetX;
	int y = rect.h - size / 2 + offsetY;

	app->render->TextDraw(text.GetString(), bounds.x + x / 4, bounds.y + y / 4, size);

	return false;
}