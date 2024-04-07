#include <Geode/Geode.hpp>
#include <Geode/modify/CCMouseDispatcher.hpp>

using namespace geode::prelude;

float scrollSpeedModifier = 0.0f;
bool ctrlPressed = false;

class $modify(FasterCCMouseDispatcher, CCMouseDispatcher) {
	bool dispatchScrollMSG(float x, float y) {
		ctrlPressed = CCKeyboardDispatcher::get()->getControlKeyPressed();

		scrollSpeedModifier = ctrlPressed ? Mod::get()->getSettingValue<double>("scroll-speed-modifier") : 1.0f;

		if (!CCMouseDispatcher::dispatchScrollMSG(x * scrollSpeedModifier, y * scrollSpeedModifier)) return false;
		return true;
	}
};