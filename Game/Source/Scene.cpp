#include "Scene.h"

#include "App.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Textures.h"
#include "Window.h"

#include "GuiManager.h"

#include "Defs.h"
#include "Log.h"

#include <iostream>
using namespace std;
#include <sstream>

Scene::Scene() : Module()
{
	name.Create("scene");
}

Scene::~Scene()
{}

bool Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

bool Scene::Start()
{
	// Settings
	pSettings->GUI_id = 0;
	pSettings->CreateSettings(this);

	// Pause 
	pPause->GUI_id = pSettings->GUI_id;
	pPause->CreatePause(this);

	return true;
}

bool Scene::PreUpdate()
{
	return true;
}

bool Scene::Update(float dt)
{
	pPause->pause = true;
	return true;
}

bool Scene::PostUpdate()
{
	bool ret = true;

	if (exit) return false;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;
	
	if (pSettings->settings) { pSettings->OpenSettings(); }
	if (pPause->pause) { pPause->OpenPause(); }
	app->guiManager->Draw();

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	app->render->camera.x = 0;
	app->render->camera.y = 0;

	pSettings->CleanUp();
	pPause->CleanUp();
	app->guiManager->CleanUp();
	return true;
}

bool Scene::InitEntities()
{

	return true;
}

bool Scene::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Event by %d ", control->id);

	app->audio->PlayFx(control->fxControl);

	switch (control->id)
	{
	case 1:
		LOG("Button Close settings click");
		pPause->OpenPause();
		pSettings->CloseSettings();
		break;
	case 2:
		LOG("Slider music click");
		app->audio->ChangeMusicVolume(pSettings->music->volume100);
		break;
	case 3:
		LOG("Slider fx click");
		app->audio->ChangeFxVolume(pSettings->fx->volume100);
		break;
	case 4:
		LOG("Checkbox Fullscreen click");
		app->win->changeScreen = !app->win->changeScreen;
		app->win->ResizeWin();
		break;
	case 5:
		LOG("Checkbox Vsync click");
		(control->state == GuiControlState::NORMAL) ? app->render->flags = SDL_RENDERER_ACCELERATED : app->render->flags |= SDL_RENDERER_PRESENTVSYNC;
		break;
	case 6:
		LOG("Button Close pause click");
		pPause->ClosePause(); 
		break;
	case 7:
		LOG("Button Resume click");
		pPause->ClosePause();
		break;
	case 8:
		LOG("Button Return to Title click");
		break;
	case 9:
		LOG("Button settings click");
		pPause->ClosePause();

		pSettings->settings = !pSettings->settings;
		if (!pSettings->settings) { pSettings->CloseSettings();}
		break;
	case 10:
		LOG("Button Exit game click");
		exit = true;
		break;
	}

	return true;
}