#include "ScoreController.h"

ScoreController::ScoreController(const WorldProperties& worldProperties)
	:
	mapWidth{ worldProperties.GetMapSize().x },
	score{}
{
}

const unsigned ScoreController::getScore() const noexcept
{
	return score;
}

void ScoreController::addScore(unsigned value)
{
	score += value;
}

void ScoreController::addScoreWithDestroyedRowsCount(size_t destroyedRowsCount)
{
	addScore(destroyedRowsCount * mapWidth);
}
