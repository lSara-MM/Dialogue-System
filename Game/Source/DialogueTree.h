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
	
	void SplitText(SString text, int fontSize_, int max_chars_line_);

	void CleanUp();

public:
	SString text;
	int nodeID;
	vector <DialogueChoice*> choicesList;


	bool trimmed = false;
	vector<SString> texts;
};


class DialogueTree
{
public:
	DialogueTree() {};
	DialogueTree(bool a);
	~DialogueTree() {};

	bool UpdateTree(float dt, Module* mod, iPoint pos);
	bool UpdateNodes(Module* mod, iPoint pos, int fontSize);
	bool ChoiceInput(Module* mod, iPoint pos);
	void CleanUp();

public:
	int treeID;
	bool active = false;
	vector <DialogueNode*> nodeList;


	DialogueNode* activeNode;

	List <GuiButton*> listDialogueButtons;
	int GUI_id = 0;

	bool updateOptions;
	int fontSize;
	int max_chars_line;
};

#endif //__DIALOGTREE_H__