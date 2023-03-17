#ifndef __SCENE_H__
#define __SCENE_H__

#include "App.h"

#include "Module.h"

#include "GuiButton.h"
#include "GuiCheckBox.h"
#include "GuiSliderBar.h"

#include "Settings.h"

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

	// Settings
	bool OnGuiMouseClickEvent(GuiControl* control);

public:

	bool frcap;

private:

	// Settings
	Settings options;
	Settings* pSettings = &options;

	Pause pauseMenu;
	Pause* pPause = &pauseMenu;

	bool exit;
};

#endif // __SCENE_H__