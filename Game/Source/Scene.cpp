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
	//dialogueID = app->dialogueSystem->LoadDialogue("dialogues.xml", 0);
	return true;
}

bool Scene::PreUpdate()
{
	return true;
}

bool Scene::Update(float dt)
{

	return true;
}

bool Scene::PostUpdate()
{
	bool ret = true;

	if (exit) return false;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;
	
	if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && app->dialogueSystem->activeTree == nullptr)
	{
		// Que es millor, carregar-ho abans i activar-ho a quan x event o carregar-ho quan sigui necessari?
		dialogueID = app->dialogueSystem->LoadDialogue("dialogues.xml", 0);
		//app->dialogueSystem->treeList[dialogueID]->active = true;
	}


	if (app->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		app->dialogueSystem->CleanUp();
		dialogueID = app->dialogueSystem->LoadDialogue("dialogues.xml", 0);
	}

	if (app->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		app->dialogueSystem->CleanUp();
		dialogueID = app->dialogueSystem->LoadDialogue("dialogues.xml", 1);
	}


	if (app->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		app->SaveGameRequest();
	}

	if (app->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)
	{
		app->LoadGameRequest();
	}

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	app->render->camera.x = 0;
	app->render->camera.y = 0;

	app->guiManager->CleanUp();
	return true;
}

bool Scene::InitEntities()
{

	return true;
}
