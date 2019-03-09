#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams *pParams) : GameObject(pParams),
                                                            m_position(pParams->getX(), pParams->getY()),
                                                            m_velocity(0, 0),
                                                            m_acceleration(0, 0)
{
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureId = pParams->getTextureId();
  m_currentRow = 1;
  m_currentFrame = 1;
}

void SDLGameObject::draw()
{
  if (m_velocity.getX() > 0)
  {
    if (m_velocity.getX() > 0)
    {
      TextureManager::getInstance()->drawFrame(
          m_textureId,
          (Uint32)m_position.getX(),
          (Uint32)m_position.getY(),
          m_width,
          m_height,
          m_currentRow,
          m_currentFrame,
          TheGame::getInstance()->getRenderer(),
          SDL_FLIP_HORIZONTAL);
    }
    else
    {
      TextureManager::getInstance()->drawFrame(
          m_textureId,
          (Uint32)m_position.getX(),
          (Uint32)m_position.getY(),
          m_width,
          m_height,
          m_currentRow,
          m_currentFrame,
          TheGame::getInstance()->getRenderer());
    }
  }
}

void SDLGameObject::update()
{
  m_velocity += m_acceleration;
  m_position += m_velocity;
}

void SDLGameObject::clean()
{
}