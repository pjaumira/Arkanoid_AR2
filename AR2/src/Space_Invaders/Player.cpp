#include "Player.h"

float Player::getPlayerXVel() {
	return playerXVel;
}

string Player::getPlayerTextScore() {
	return playerTextScore;
}

string Player::getPlayerScore() {
	return playerScore2;
}

void Player::increaseScore(string type) {
	if (type == "Normal"){
		playerScore += normalPoints;
	}
	else if (type == "Heavy") {
		playerScore += heavyPoints;
	}
}

int Player::getScore() {
	return playerScore;
}

bool Player::hasPowerUp() {
	return (speedPowerUp || doubleShotPowerUp) ? true : false;
}
bool Player::doubleShot() {
	return doubleShotPowerUp;
}
bool Player::isFast() {
	return speedPowerUp;
}

void  Player::resetPowerUp() {
	if (speedPowerUp)
	{
		modSpeed = 1;
		speedPowerUp = false;
	}
	else if (doubleShotPowerUp) {
		doubleShotPowerUp = false;
	}
}

void Player::pickPowerUp(string type) {
	if (type == "speed")
	{
		modSpeed = 1.8f;
		speedPowerUp = true;
		Powerup.type = type;
		Powerup.time = clock();
	}
	else if (type == "doubleShot") {
		doubleShotPowerUp = true;
		Powerup.type = type;
		Powerup.time = clock();
	}
}