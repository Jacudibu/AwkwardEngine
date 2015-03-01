#include "Headers\RenderLayer.h"

void RenderLayer::Render()
{
	if (!enabled)
		return;

	for (Renderer* object : renderList)
	{
		object->draw();
	}
}

void RenderLayer::addRenderer(Renderer* object)
{
	renderList.push_back(object);
}
void RenderLayer::removeRenderer(Renderer* object)
{
	renderList.remove(object);
}