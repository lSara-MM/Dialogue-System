#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "DialogueSystem.h"

#include "App.h"
#include "GuiManager.h"
#include "Module.h"
#include "GuiButton.h"

#include "List.h"
#include "Log.h"
#include "Point.h"
#include "SString.h"
#include <vector>
#include <iostream>

using namespace std;

class DialogueChoice
{
public:
	DialogueChoice() {};
	DialogueChoice(SString text_, int nextNode_)
	{
		text = text_;
		nextNode = nextNode_;
	}
	~DialogueChoice() {};

public:
	SString text;
	int nextNode;
};


class DialogueNode
{
public:
	DialogueNode() {};
	DialogueNode(int id, SString text_)
	{

	}
	~DialogueNode() {};

public:
	SString text;
	vector <DialogueChoice*> choicesList;
	vector <SString> answersList;
	int nodeID;
};


class DialogueTree
{
public:
	DialogueTree() {};
	~DialogueTree() {};

public:
	int treeID;
	vector <DialogueNode*> nodeList;
};


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
	DialogueNode* LoadNodes(pugi::xml_node& trees);
	DialogueChoice* LoadChoices(pugi::xml_node& text_node);

private:
	pugi::xml_document dialogues;

	int activeTreeID = 0;
	int playerInput = 0;

	DialogueNode* activeNode;
	vector <DialogueTree*> treesList;
	List <GuiButton*> listDialogueButtons;
};

#endif // __DIALOGSYSTEM_H__
