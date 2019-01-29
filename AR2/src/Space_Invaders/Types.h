#pragma once
#include <string>

using Rect = struct  Rect { int  x; int y; int w; int h; };

using Color = struct Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };

struct Vector2 { int x; int y; };

using Font = struct {
	std::string id;
	std::string path;
	int size;
};

using Text = struct {
	std::string id;
	std::string text;
	Color color;
	int w;
	int h;
};

enum class Key { A, D, SPACE, P, ESC, NONE };