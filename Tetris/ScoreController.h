#pragma once
#include "WorldProperties.h"
#include <iostream>

class ScoreController
{
public:
	ScoreController(const WorldProperties& worldProperties);
	const unsigned getScore() const noexcept;
	void addScore(unsigned value);
	void addScoreWithDestroyedRowsCount(size_t destroyedRowsCount);
private:
	unsigned score;
	const unsigned mapWidth;
};

