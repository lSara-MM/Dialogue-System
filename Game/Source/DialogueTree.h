#ifndef __DIALOGTREE_H__
#define __DIALOGTREE_H__

#include "App.h"
#include "Render.h"
#include "Textures.h"
#include "Module.h"
#include "Input.h"
#include "SDL/include/SDL.h"


#include "List.h"
#include "Log.h"
#include "Point.h"
#include "SString.h"
#include <vector>
#include <iostream>

using namespace std;

class DialogueChoice
{
	DialogueChoice() {};
	DialogueChoice(SString text, int nextNode) {};
	~DialogueChoice() {};

public:
	SString text;
	int nextNode;
};


class DialogueNode
{
public:
	DialogueNode() {};
	DialogueNode(SString text) {};
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

#endif // __DIALOGTREE_H__