#include "./File/Header/Easing.h"
#include <Novice.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

float easeInSine(float x) {
	return 1 - cosf((x * float(M_PI)) / 2);
}
float easeOutSine(float x) {
	return sinf((x * float(M_PI)) / 2);
}
float easeInOutSine(float x) {
	return -(cosf(float(M_PI) * x) - 1) / 2;
}
float easeInQuad(float x) {
	return x * x;
}
float easeOutQuad(float x) {
	return 1 - (1 - x) * (1 - x);
}
float easeInOutQuad(float x) {
	return x < 0.5 ? 2 * x * x : 1 - powf(-2 * x + 2, 2) / 2;
}
float easeInCubic(float x) {
	return x * x * x;
}
float easeOutCubic(float x) {
	return 1 - powf(1 - x, 3);
}
float easeInOutCubic(float x) {
	return x < 0.5 ? 4 * x * x * x : 1 - powf(-2 * x + 2, 3) / 2;
}
float easeInQuart(float x) {
	return x * x * x * x;
}
float easeOutQuart(float x) {
	return 1 - powf(1 - x, 4);
}
float easeInOutQuart(float x) {
	return x < 0.5 ? 8 * x * x * x * x : 1 - powf(-2 * x + 2, 4) / 2;
}
float easeInQuint(float x) {
	return x * x * x * x * x;
}
float easeOutQuint(float x) {
	return 1 - powf(1 - x, 5);
}
float easeInOutQuint(float x) {
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - powf(-2 * x + 2, 5) / 2;
}
float easeInExpo(float x) {
	return x == 0 ? 0 : powf(2, 10 * x - 10);
}
float easeOutExpo(float x) {
	return x == 1 ? 1 : 1 - powf(2, -10 * x);
}
float easeInOutExpo(float x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5 ? powf(2, 20 * x - 10) / 2
		: (2 - powf(2, -20 * x + 10)) / 2;
}
float easeInCirc(float x) {
	return 1 - sqrtf(1 - powf(x, 2));
}
float easeOutCirc(float x) {
	return  sqrtf(1 - powf(x - 1, 2));
}
float easeInOutCirc(float x) {
	return x < 0.5
		? (1 - sqrtf(1 - powf(2 * x, 2))) / 2
		: (sqrtf(1 - powf(-2 * x + 2, 2)) + 1) / 2;
}
float easeInBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}
float easeOutBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1;

	return 1 + c3 * powf(x - 1, 3) + c1 * powf(x - 1, 2);
}
float easeInOutBack(float x) {
	const float  c1 = 1.70158f;
	const float  c2 = c1 * 1.525f;

	return x < 0.5
		? (powf(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (powf(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}
float easeInElastic(float x) {
	const float  c4 = (2 * float(M_PI)) / 3;

	return x == 0
		? 0
		: x == 1
		? 1
		: -powf(2, 10 * x - 10) * sinf((x * 10 - 10.75f) * c4);
}
float easeOutElastic(float x) {
	const float  c4 = (2 * float(M_PI)) / 3;

	return x == 0
		? 0
		: x == 1
		? 1
		: powf(2, -10 * x) * sinf((x * 10 - 0.75f) * c4) + 1;
}
float easeInOutElastic(float x) {
	const float  c5 = (2 * float(M_PI)) / 4.5f;

	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? -(powf(2, 20 * x - 10) * sinf((20 * x - 11.125f) * c5)) / 2
		: (powf(2, -20 * x + 10) * sinf((20 * x - 11.125f) * c5)) / 2 + 1;
}
float easeOutBounce(float x) {
	const float  n1 = 7.5625f;
	const float  d1 = 2.75f;

	if (x < 1 / d1) {
		return n1 * x * x;
	}
	else if (x < 2 / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}
float easeInBounce(float x) {
	return 1 - easeOutBounce(1 - x);
}
float easeInOutBounce(float x) {
	return x < 0.5
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}

void EaseingX(easename &EaseName, float &PlayerPosX, const float &StartPosX, const float &EndPosX, float &x) {
	switch (EaseName) {
	case InSine:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInSine(x));
		break;
	case OutSine:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutSine(x));
		break;
	case InOutSine:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutSine(x));
		break;
	case InQuad:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInQuad(x));
		break;
	case OutQuad:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutQuad(x));
		break;
	case InOutQuad:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutQuad(x));
		break;
	case InCubic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInCubic(x));
		break;
	case OutCubic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutCubic(x));
		break;
	case InOutCubic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutCubic(x));
		break;
	case InQuart:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInQuart(x));
		break;
	case OutQuart:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutQuart(x));
		break;
	case InOutQuart:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutQuart(x));
		break;
	case InQuint:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInQuint(x));
		break;
	case OutQuint:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutQuint(x));
		break;
	case InOutQuint:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutQuint(x));
		break;
	case InExpo:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInExpo(x));
		break;
	case OutExpo:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutExpo(x));
		break;
	case InOutExpo:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutExpo(x));
		break;
	case InCirc:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInCirc(x));
		break;
	case OutCirc:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutCirc(x));
		break;
	case InOutCirc:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutCirc(x));
		break;
	case InBack:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInBack(x));
		break;
	case OutBack:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutBack(x));
		break;
	case InOutBack:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutBack(x));
		break;
	case InElastic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInElastic(x));
		break;
	case OutElastic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutElastic(x));
		break;
	case InOutElastic:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutElastic(x));
		break;
	case InBounce:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInBounce(x));
		break;
	case OutBounce:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeOutBounce(x));
		break;
	case InOutBounce:
		PlayerPosX = StartPosX + (EndPosX - StartPosX) * float(easeInOutBounce(x));
		break;
	}
}
void EaseingY(easename &EaseName, float &PlayerPosY, const float &StartPosY, const float &EndPosY, float &x) {
	switch (EaseName) {
	case InSine:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInSine(x));
		break;
	case OutSine:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutSine(x));
		break;
	case InOutSine:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutSine(x));
		break;
	case InQuad:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInQuad(x));
		break;
	case OutQuad:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutQuad(x));
		break;
	case InOutQuad:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutQuad(x));
		break;
	case InCubic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInCubic(x));
		break;
	case OutCubic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutCubic(x));
		break;
	case InOutCubic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutCubic(x));
		break;
	case InQuart:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInQuart(x));
		break;
	case OutQuart:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutQuart(x));
		break;
	case InOutQuart:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutQuart(x));
		break;
	case InQuint:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInQuint(x));
		break;
	case OutQuint:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutQuint(x));
		break;
	case InOutQuint:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutQuint(x));
		break;
	case InExpo:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInExpo(x));
		break;
	case OutExpo:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutExpo(x));
		break;
	case InOutExpo:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutExpo(x));
		break;
	case InCirc:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInCirc(x));
		break;
	case OutCirc:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutCirc(x));
		break;
	case InOutCirc:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutCirc(x));
		break;
	case InBack:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInBack(x));
		break;
	case OutBack:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutBack(x));
		break;
	case InOutBack:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutBack(x));
		break;
	case InElastic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInElastic(x));
		break;
	case OutElastic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutElastic(x));
		break;
	case InOutElastic:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutElastic(x));
		break;
	case InBounce:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInBounce(x));
		break;
	case OutBounce:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeOutBounce(x));
		break;
	case InOutBounce:
		PlayerPosY = StartPosY + (EndPosY - StartPosY) * float(easeInOutBounce(x));
		break;
	}
}