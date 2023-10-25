#pragma once

class ScoreController
{
public:
	const unsigned getScore() const noexcept;
	void addScore(unsigned value);
private:
	unsigned score;
};

