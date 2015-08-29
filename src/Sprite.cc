#include "Sprite.h"


Sprite::Sprite(std::string path, SDL_Surface* screen_surface) : sprite_surface_(nullptr) {
  SDL_Surface* temp_surface = SDL_LoadBMP(path.c_str());

  if (temp_surface == nullptr) {
    throw;
  }

  sprite_surface_ = SDL_ConvertSurface(temp_surface, screen_surface->format, NULL);

  if (sprite_surface_ == nullptr) {
    throw;
  }

  SDL_FreeSurface(temp_surface);

  rectangle_.x = 0;
  rectangle_.y = 0;
  rectangle_.w = sprite_surface_->w;
  rectangle_.h = sprite_surface_->h;
}


Sprite::~Sprite() {
  SDL_FreeSurface(sprite_surface_);
}


void Sprite::Blit(SDL_Surface* surface) {
  SDL_BlitScaled(sprite_surface_, nullptr, surface, &rectangle_);
}

