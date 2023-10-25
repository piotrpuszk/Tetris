#include "ScoreController.h"

const unsigned ScoreController::getScore() const noexcept
{
    return score;
}

void ScoreController::addScore(unsigned value)
{
    score += value;
}
