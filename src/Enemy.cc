#include "Enemy.h"


Enemy::Enemy(const std::shared_ptr<ScreenResource> resource,
             SDL_Renderer* renderer,
             int16_t x, int16_t y, int16_t vx, int16_t vy) :
  Actor(resource, renderer, x, y, vx, vy) {
}


void Enemy::HandleEvent(const SDL_Event& e) {
}
