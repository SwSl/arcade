/*
** EPITECH PROJECT, 2018
** a
** File description:
** ®§
*/

#ifndef INTERFACES_HPP_
	#define INTERFACES_HPP_

	#include <queue>

enum RenderDatas {
	Spot,
	Line,
	Rect,
	FilledRect,
	Circle,
	FilledCircle,
	Sprite
};

union Color {
	int c;
	char rgba[4];
};

struct RenderDatas {
	RenderDatas	type;
	Color		*colors;
	int		start[2];
	int		size[2];
};
typedef std::queue<RenderDatas> RenderData;

struct InputData {
	int mouse_pos[2];
	bool mouse_click[5];
	int mouse_scroll[2];
	int *keys_down; /* null-terminated */
	int *keys_pressed;
	int *keys_up;
	int window_size[2];
};

struct UpdateData {
	InputData *input;
	double deltaTime;
};

class IGames {
public:
	IGames() = default;
	~IGames();

	virtual RenderDatas *Update(UpdateData *) = 0;
	virtual char *Save(/* out */ std::size_t &size) = 0;
	virtual void Restore(char *data, std::size_t size) = 0;
};

class IGraph {
public:
	IGraph() = default;
	~IGraph();

	virtual InputData *Render(RenderDatas *) = 0;
};

#endif /* !INTERFACES_HPP_ */
