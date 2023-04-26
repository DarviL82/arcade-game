#include <iostream>
#include <csignal>

#include "src/Game.hpp"
#include "src/entities/bases/BaseHealthEntity.cpp"

Game game;

int main() {
	std::signal(SIGINT, [](int) {
		game.stop_loop();
	});

	game.start_loop();
}

