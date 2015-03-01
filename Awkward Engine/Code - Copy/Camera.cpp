#include "Headers\Camera.h"

Camera::Camera(Window* win, SDL_Rect* viewport)
{
	window = win;
	win->addCamera(this);

	viewPort = viewport;
	transform = new Transform(nullptr);
}

Camera::~Camera()
{
	if (window != nullptr)
		window->removeCamera(this);

	delete (viewPort); // TODO: Is this legit?
	delete (transform);
}

void Camera::setViewPort(SDL_Rect* port)
{
	viewPort = port;
}

void Camera::Render()
{
	if (!enabled)
		return;

	for (RenderLayer* layer : renderLayer)
	{
		layer->Render();
	}
}

void Camera::addLayer(RenderLayer* layer)
{
	renderLayer.push_back(layer);

	// #TODO: Sort layers here. Elsewise this is kinda pointless.
}

void Camera::removeLayer(RenderLayer* layer)
{
	renderLayer.remove(layer);
}

void Camera::setWindow(Window* win)
{
	if (win != nullptr)
		win->removeCamera(this);

	window = win;
	win->addCamera(this);
}