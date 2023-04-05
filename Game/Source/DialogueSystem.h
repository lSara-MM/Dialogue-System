#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "DialogueSystem.h"
#include "DialogueTree.h"

#include "App.h"
#include "GuiManager.h"
#include "Module.h"
#include "GuiButton.h"


class DialogueSystem : public Module
{
public:
	DialogueSystem();
	~DialogueSystem();

	// Called before render is available
	bool Awake(pugi::xml_node& config);
	bool Start();
	bool Update(float dt);
	bool OnGuiMouseClickEvent(GuiControl* control);
	bool CleanUp();

	void PerformDialogue(int treeId);

	int LoadDialogue(const char* file, int dialogueID);
	DialogueNode* LoadNodes(pugi::xml_node& xml_trees, DialogueTree* tree);
	void LoadChoices(pugi::xml_node& xml_node, DialogueNode* node);

public:

	//int activeTreeID = 0;
	int playerInput = 0;

	DialogueTree* activeTree;
	//vector <DialogueTree*> treeList;

	SDL_Texture* textBox_tex;
	const char* textBox_path;
private:
	pugi::xml_document dialogues;
};

#endif // __DIALOGSYSTEM_H__
