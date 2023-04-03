#ifndef __DIALOGTREE_H__
#define __DIALOGTREE_H__

#include "GuiManager.h"
#include "Module.h"
#include "GuiButton.h"

#include "List.h"
#include "Log.h"
#include "Point.h"
#include "SString.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DialogueChoice
{
public:
	DialogueChoice() {};
	~DialogueChoice() {};

public:
	SString text;
	int nextNode;
	int eventReturn;
};


class DialogueNode
{
public:
	DialogueNode() {};
	~DialogueNode() {};
	
	void CleanUp();

public:
	SString text;
	int nodeID;
	vector <DialogueChoice*> choicesList;
};


class DialogueTree
{
public:
	DialogueTree() {};
	DialogueTree(bool a);
	~DialogueTree() {};

	bool UpdateTree(float dt, Module* mod);
	void CleanUp();

public:
	int treeID;
	bool active = false;
	vector <DialogueNode*> nodeList;


	DialogueNode* activeNode;

	List <GuiButton*> listDialogueButtons;
	int GUI_id = 0;
};

#endif //__DIALOGTREE_H__