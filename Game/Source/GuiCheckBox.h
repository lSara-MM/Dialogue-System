#ifndef __GUICheckBox_H__
#define __GUICheckBox_H__

#include "GuiControl.h"

#include "Log.h"
#include "Point.h"
#include "SString.h"

class GuiCheckBox : public GuiControl
{
public:

	GuiCheckBox(uint32 id, SDL_Rect bounds);
	virtual ~GuiCheckBox();

	bool Update(float dt);
	bool Draw(Render* render);

	int mouseX, mouseY;

	SDL_Texture* checkBoxTex;
};

#endif // __GUICheckBox_H__