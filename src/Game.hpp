#pragma once

#include <chrono>
#include <memory>
#include "render/Renderable.hpp"
#include "Tickable.hpp"
#include "Scene.hpp"
#include "input/InputSystem.hpp"
#include "RenderUtils.hpp"

namespace input {
	class InputSystem;
}

class Game {
	std::unique_ptr<render::Renderer> renderer;
	Scene* current_scene = nullptr;
	bool running = false;
	input::InputSystem* input_system;

	void tick(float delta);
	void render(const RenderUtils& render_utils) const;
	void main_loop();
	void init();
	void end();

public:
	Game();

	void start_loop();
	void stop_loop();
};
