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
		dialogueID = app->dialogueSystem->LoadDialogue("dialogues.xml", 0);
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
		app->dialogueSystem->LoadDialogueState();
	}


	if (app->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		app->dialogueSystem->SaveDialogueState();
	}

	if (app->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)
	{
		app->dialogueSystem->LoadDialogueState();
	}


	app->render->TextDraw("Space: start dialogue", 50, 25, 16, { 255, 255, 255 });
	app->render->TextDraw("F1: start dialogue 1", 50, 50, 16, { 255, 255, 255 });
	app->render->TextDraw("F2: start dialogue 2", 50, 75, 16, { 255, 255, 255 });
	app->render->TextDraw("F5: save dialogue state", 50, 100, 16, { 255, 255, 255 });
	app->render->TextDraw("F6: load dialogue state", 50, 125, 16, { 255, 255, 255 });

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
