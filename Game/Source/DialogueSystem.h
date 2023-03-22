#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "DialogueSystem.h"

#include "App.h"
#include "GuiManager.h"
#include "Module.h"

#include "GuiButton.h"
#include "DialogueTree.h"

#include "List.h"
#include <vector>
using namespace std;

class DialogueSystem : public Module
{
public:
	DialogueSystem();
	~DialogueSystem();

	bool Start();
	bool Update(float dt);
	bool OnGuiMouseClickEvent(GuiControl* control);
	bool CleanUp();

	void PerformDialogue(int treeId);

	DialogueTree* LoadDialogue(const char* file, int dialogueID);
	bool LoadNodes(pugi::xml_node& trees, DialogueTree* oak);
	bool LoadChoices(pugi::xml_node& text_node, DialogueNode* npc);

private:
	pugi::xml_document	dialogues;
	int activeTreeID = 0;

	DialogueNode* activeNode;
	vector <DialogueTree*> treesList;
	List <GuiButton*> listDialogueButtons;
};

#endif // __DIALOGSYSTEM_H__
