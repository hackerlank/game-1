#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory>
#include <SDL.h>
#include "IEventHandler.h"
#include "RenderableObject.h"
#include "Actor.h"
#include "Player.h"


class Engine {
  public:
    Engine();
    Engine(const Engine&) = delete;
    ~Engine();

    void Init();
    void Main();

    uint16_t get_screen_width() const;
    uint16_t get_screen_height() const;
    SDL_Surface* get_screen_surface() const;

  private:
    static const uint16_t kScreenWidth;
    static const uint16_t kScreenHeight;
    SDL_Window* game_window_;
    SDL_Surface* screen_surface_;
    SDL_Renderer* renderer_;

    uint32_t score_;
    std::shared_ptr<RenderableObject> score_text_;

    bool quit_;
    std::shared_ptr<Player> player_;
    std::vector<std::shared_ptr<Actor>> new_objects_;
    std::vector<std::shared_ptr<Actor>> acting_objects_;
    std::vector<std::shared_ptr<RenderableObject>> static_objects_;
    std::vector<std::shared_ptr<IEventHandler>> event_handlers_;

    void InitializeRenderer();
    void InitializeScene();
    void GameLoop();
    void UpdateScene();
    void RenderScene();
    void RenderHUD();

    void SpawnPlayer();
    void SpawnEnemy();
    void SpawnBullets();
    void SpawnObject(std::shared_ptr<Actor> object);
    void DetectCollisions();
    void CleanupScene();
};

#endif // ENGINE_H
