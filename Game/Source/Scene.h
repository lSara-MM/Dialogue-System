#ifndef __SCENE_H__
#define __SCENE_H__

#include "App.h"

#include "Module.h"
#include "GuiButton.h"
#include "DialogueSystem.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool InitEntities();

public:

	bool frcap;

private:

	DialogueSystem* dialogueSystem;

	bool exit;
};

#endif // __SCENE_H__