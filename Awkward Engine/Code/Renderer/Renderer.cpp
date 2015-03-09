#include "Renderer.h"

void Renderer::Update()
{
	// Do nothing. :3
}


void Renderer::setLayer(RenderLayer* layer)
{
	if (Layer != nullptr)
		Layer->removeRenderer(this);
	Layer = layer;
	Layer->addRenderer(this);
}