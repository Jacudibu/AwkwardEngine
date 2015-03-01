#include "Headers\TextRenderer.h"
#include "Headers\ResourceManager.h"

TTF_Font* TextRenderer::font = nullptr;

TextRenderer::TextRenderer(std::string newText, RenderLayer* layer, SDL_Color color)
{
	Layer = layer;
	Layer->addRenderer(this);
	Color = color;
	setText(newText);
}

TextRenderer::~TextRenderer()
{
	Layer->removeRenderer(this);
	ResourceManager::unloadTexture(texture->path);
}

void TextRenderer::draw()
{
	if (!enabled || !gameObject->enabled)
		return;

	Transform* pos = gameObject->transform->getWorldTransform();

	texture->render((int)(pos->Position.x - Offset.x + Layer->camera->transform->Position.x), // X-POS
					(int)(pos->Position.y - Offset.y + Layer->camera->transform->Position.y), // Y-POS
					Layer->renderer,				 // Renderer
					nullptr,						 // Position in SpriteSheet
					pos->Rotation,                   // Rotation
					nullptr,                         // Rotation Anchor (Null => Center)
					flip                             // SDL FLIP Tags
					);
}

void TextRenderer::generate()
{
	texture = ResourceManager::loadTextureFromText(text, Layer->renderer, Color, font);
	Offset = { texture->getWidth() / 2.0f, texture->getHeight() / 2.0f, 0.0f };
}

void TextRenderer::setText(std::string newText)
{
	if (newText.compare(text) != 0)
	{
		text = newText;
		generate();
	}
}

std::string TextRenderer::getText()
{
	return text;
}