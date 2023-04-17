#pragma once

#include <cstdint>
#include <string>
#include "Renderer.hpp"

#define __DEFINE_SEQ(name) static constexpr const char* name = "\x1b"

namespace render {

	struct TerminalSequences final {
		TerminalSequences() = delete;

		static constexpr const char ESCAPE = '\x1b';
		static constexpr const char* ESCAPE_SEQUENCE_START = "\x1b[";

		// text formatting
		__DEFINE_SEQ(INVERT) "[7m";
		__DEFINE_SEQ(NO_INVERT) "[27m";
		__DEFINE_SEQ(UNDERLINE) "[4m";
		__DEFINE_SEQ(NO_UNDERLINE) "[24m";
		__DEFINE_SEQ(DIM) "[2m";
		__DEFINE_SEQ(NO_DIM) "[22m";
		__DEFINE_SEQ(STHROUGH) "[9m";
		__DEFINE_SEQ(NO_STHROUGH) "[29m";
		__DEFINE_SEQ(INVISIBLE) "[8m";
		__DEFINE_SEQ(NO_INVISIBLE) "[28m";
		__DEFINE_SEQ(BOLD) "[1m";
		__DEFINE_SEQ(NO_BOLD) "[22m";
		__DEFINE_SEQ(ITALIC) "[3m";
		__DEFINE_SEQ(NO_ITALIC) "[23m";
		__DEFINE_SEQ(BLINK) "[5m";
		__DEFINE_SEQ(NO_BLINK) "[25m";
		__DEFINE_SEQ(RESET) "[0m";

		// special
		__DEFINE_SEQ(CLEAR_LINE) "[2K";
		__DEFINE_SEQ(CLEAR_RIGHT) "[0K";
		__DEFINE_SEQ(CLEAR_LEFT) "[1K";
		__DEFINE_SEQ(CLEAR_DOWN) "[0J";
		__DEFINE_SEQ(CLEAR_ALL) "[2J";
		__DEFINE_SEQ(CLEAR_SCROLL) "[3J";
		__DEFINE_SEQ(CURSOR_SHOW) "[?25h";
		__DEFINE_SEQ(CURSOR_HIDE) "[?25l";
		__DEFINE_SEQ(CURSOR_SAVE) "7";
		__DEFINE_SEQ(CURSOR_LOAD) "8";
		__DEFINE_SEQ(BUFFER_NEW) "[?1049h";
		__DEFINE_SEQ(BUFFER_OLD) "[?1049l";
		__DEFINE_SEQ(CURSOR_HOME) "[H";
		__DEFINE_SEQ(INVERT_ALL) "[?5h";
		__DEFINE_SEQ(NO_INVERT_ALL)"[?5l";

		static RPoint get_terminal_size();
		static std::wstring cursor_set_pos(RPoint pos);
		static std::wstring cursor_set_pos_relative(RPoint offset);
		static std::wstring cursor_move_x(int16_t x);
		static std::wstring cursor_move_y(int16_t y);
		static std::wstring set_color(Color color, bool background = false);
	};
}