#include "Headers\SpriteRenderer.h"
#include "Headers\ResourceManager.h"

SpriteRenderer::SpriteRenderer(std::string path, RenderLayer* layer, int rows, int columns, int step)
{
	Layer = layer;
	Layer->addRenderer(this);

	texture = ResourceManager::loadTextureFromFile(path, Layer->renderer);

	spriteRows = rows;
	spriteColumns = columns;

	calculateSpriteClips();
	setCurrentClip(step);

	Offset = { (float)clipWidth / 2, (float)clipHeight / 2, 0.0f };
}

SpriteRenderer::~SpriteRenderer()
{
	Layer->removeRenderer(this);

	ResourceManager::unloadTexture(texture->path);
	delete (spriteClips);
}

void SpriteRenderer::draw()
{
	if (!enabled  || !gameObject->enabled)
		return;

	Transform* pos = gameObject->transform->getWorldTransform();

	texture->render((int)(pos->Position.x - Offset.x + Layer->camera->transform->Position.x), // X-POS
					(int)(pos->Position.y - Offset.y + Layer->camera->transform->Position.y), // Y-POS
					Layer->renderer,				 // Renderer
					spriteClips + (spriteClip - 1),  // Position in SpriteSheet
					pos->Rotation,                   // Rotation
					nullptr,                         // Rotation Anchor (Null => Center)
					flip                             // SDL FLIP Tags
				   );
}

void SpriteRenderer::setCurrentClip(int clip)
{
	spriteClip = clip;
}


void SpriteRenderer::calculateSpriteClips()
{
	delete(spriteClips);
	spriteClips = new SDL_Rect[spriteRows * spriteColumns];

	clipHeight = texture->getHeight() / spriteRows;
	clipWidth  = texture->getWidth()  / spriteColumns;

	for (int y = 0; y < spriteRows; y++)
	{
		for (int x = 0; x < spriteColumns; x++)
		{
			spriteClips[x + y * spriteColumns].x = x*clipWidth;
			spriteClips[x + y * spriteColumns].y = y*clipHeight;
			spriteClips[x + y * spriteColumns].w = clipWidth;
			spriteClips[x + y * spriteColumns].h = clipHeight;
		}
	}
}
