#include "raylibSystemInterface.h"
#include "raylib.h"
#include <map>

static std::map<KeyboardKey, Rml::Input::KeyIdentifier> keyMap;
double timer = 0.0;

bool initialized = false;

void Initialize() {
    if (initialized) {
        return;
    }

    initialized = true;

	keyMap = {
		{ KEY_COMMA, Rml::Input::KI_OEM_COMMA },
		{ KEY_APOSTROPHE, Rml::Input::KI_OEM_7 },
		{ KEY_MINUS, Rml::Input::KI_OEM_MINUS },
		{ KEY_PERIOD, Rml::Input::KI_OEM_PERIOD },
		{ KEY_SLASH, Rml::Input::KI_OEM_2 },
		{ KEY_ZERO, Rml::Input::KI_0 },
		{ KEY_ONE, Rml::Input::KI_1 },
		{ KEY_TWO, Rml::Input::KI_2 },
		{ KEY_THREE, Rml::Input::KI_3 },
		{ KEY_FOUR, Rml::Input::KI_4 },
		{ KEY_FIVE, Rml::Input::KI_5 },
		{ KEY_SIX, Rml::Input::KI_6 },
		{ KEY_SEVEN, Rml::Input::KI_7 },
		{ KEY_EIGHT, Rml::Input::KI_8 },
		{ KEY_NINE, Rml::Input::KI_9 },
		{ KEY_SEMICOLON, Rml::Input::KI_OEM_1 },
		{ KEY_EQUAL, Rml::Input::KI_OEM_PLUS },
		{ KEY_A, Rml::Input::KI_A },
		{ KEY_B, Rml::Input::KI_B },
		{ KEY_C, Rml::Input::KI_C },
		{ KEY_D, Rml::Input::KI_D },
		{ KEY_E, Rml::Input::KI_E },
		{ KEY_F, Rml::Input::KI_F },
		{ KEY_G, Rml::Input::KI_G },
		{ KEY_H, Rml::Input::KI_H },
		{ KEY_I, Rml::Input::KI_I },
		{ KEY_J, Rml::Input::KI_J },
		{ KEY_K, Rml::Input::KI_K },
		{ KEY_L, Rml::Input::KI_L },
		{ KEY_M, Rml::Input::KI_M },
		{ KEY_N, Rml::Input::KI_N },
		{ KEY_O, Rml::Input::KI_O },
		{ KEY_P, Rml::Input::KI_P },
		{ KEY_Q, Rml::Input::KI_Q },
		{ KEY_R, Rml::Input::KI_R },
		{ KEY_S, Rml::Input::KI_S },
		{ KEY_T, Rml::Input::KI_T },
		{ KEY_U, Rml::Input::KI_U },
		{ KEY_V, Rml::Input::KI_V },
		{ KEY_W, Rml::Input::KI_W },
		{ KEY_X, Rml::Input::KI_X },
		{ KEY_Y, Rml::Input::KI_Y },
		{ KEY_Z, Rml::Input::KI_Z },
		{ KEY_LEFT_BRACKET, Rml::Input::KI_OEM_4 },
		{ KEY_BACKSLASH, Rml::Input::KI_OEM_5 },
		{ KEY_RIGHT_BRACKET, Rml::Input::KI_OEM_6 },
		{ KEY_GRAVE, Rml::Input::KI_OEM_3 },
		{ KEY_SPACE, Rml::Input::KI_SPACE },
		{ KEY_ESCAPE, Rml::Input::KI_ESCAPE },
		{ KEY_ENTER, Rml::Input::KI_RETURN },
		{ KEY_TAB, Rml::Input::KI_TAB },
		{ KEY_BACKSPACE, Rml::Input::KI_BACK },
		{ KEY_INSERT, Rml::Input::KI_INSERT },
		{ KEY_DELETE, Rml::Input::KI_DELETE },
		{ KEY_RIGHT, Rml::Input::KI_RIGHT },
		{ KEY_LEFT, Rml::Input::KI_LEFT },
		{ KEY_DOWN, Rml::Input::KI_DOWN },
		{ KEY_UP, Rml::Input::KI_UP },
		{ KEY_PAGE_UP, Rml::Input::KI_PRIOR },
		{ KEY_PAGE_DOWN, Rml::Input::KI_NEXT },
		{ KEY_HOME, Rml::Input::KI_HOME },
		{ KEY_END, Rml::Input::KI_END },
		{ KEY_CAPS_LOCK, Rml::Input::KI_CAPITAL },
		{ KEY_SCROLL_LOCK, Rml::Input::KI_SCROLL },
		{ KEY_NUM_LOCK, Rml::Input::KI_NUMLOCK },
		{ KEY_PRINT_SCREEN, Rml::Input::KI_PRINT },
		{ KEY_PAUSE, Rml::Input::KI_PAUSE },
		{ KEY_F1, Rml::Input::KI_F1 },
		{ KEY_F2, Rml::Input::KI_F2 },
		{ KEY_F3, Rml::Input::KI_F3 },
		{ KEY_F4, Rml::Input::KI_F4 },
		{ KEY_F5, Rml::Input::KI_F5 },
		{ KEY_F6, Rml::Input::KI_F6 },
		{ KEY_F7, Rml::Input::KI_F7 },
		{ KEY_F8, Rml::Input::KI_F8 },
		{ KEY_F9, Rml::Input::KI_F9 },
		{ KEY_F10, Rml::Input::KI_F10 },
		{ KEY_F11, Rml::Input::KI_F11 },
		{ KEY_F12, Rml::Input::KI_F12 },
		{ KEY_LEFT_SHIFT, Rml::Input::KI_LSHIFT },
		{ KEY_LEFT_CONTROL, Rml::Input::KI_LCONTROL },
		{ KEY_LEFT_ALT, Rml::Input::KI_LMETA },
		{ KEY_LEFT_SUPER, Rml::Input::KI_LWIN },
		{ KEY_RIGHT_SHIFT, Rml::Input::KI_RSHIFT },
		{ KEY_RIGHT_CONTROL, Rml::Input::KI_RCONTROL },
		{ KEY_RIGHT_ALT, Rml::Input::KI_RMETA },
		{ KEY_RIGHT_SUPER, Rml::Input::KI_RWIN },
		{ KEY_KB_MENU, Rml::Input::KI_RMENU },
		{ KEY_KP_0, Rml::Input::KI_NUMPAD0 },
		{ KEY_KP_1, Rml::Input::KI_NUMPAD1 },
		{ KEY_KP_2, Rml::Input::KI_NUMPAD2 },
		{ KEY_KP_3, Rml::Input::KI_NUMPAD3 },
		{ KEY_KP_4, Rml::Input::KI_NUMPAD4 },
		{ KEY_KP_5, Rml::Input::KI_NUMPAD5 },
		{ KEY_KP_6, Rml::Input::KI_NUMPAD6 },
		{ KEY_KP_7, Rml::Input::KI_NUMPAD7 },
		{ KEY_KP_8, Rml::Input::KI_NUMPAD8 },
		{ KEY_KP_9, Rml::Input::KI_NUMPAD9 },
		{ KEY_KP_DECIMAL, Rml::Input::KI_DECIMAL },
		{ KEY_KP_DIVIDE, Rml::Input::KI_DIVIDE },
		{ KEY_KP_MULTIPLY, Rml::Input::KI_MULTIPLY },
		{ KEY_KP_SUBTRACT, Rml::Input::KI_SUBTRACT },
		{ KEY_KP_ADD, Rml::Input::KI_ADD },
		{ KEY_KP_ENTER, Rml::Input::KI_RETURN },
		{ KEY_KP_EQUAL, Rml::Input::KI_RETURN },
		{ KEY_VOLUME_UP, Rml::Input::KI_VOLUME_UP },
		{ KEY_VOLUME_DOWN, Rml::Input::KI_VOLUME_DOWN },
	};
}

double RaylibSystemInterface::GetElapsedTime() {
    return GetTime();
}

bool RaylibSystemInterface::LogMessage(Rml::Log::Type type, const Rml::String &message) {
    auto output = TextFormat("[RmlUi] %s", message.c_str());
    switch (type) {
        case Rml::Log::LT_ERROR:
            TraceLog(TraceLogLevel::LOG_ERROR, output);
            break;
        case Rml::Log::LT_ASSERT:
            TraceLog(TraceLogLevel::LOG_TRACE, output);
            break;
        case Rml::Log::LT_WARNING:
            TraceLog(TraceLogLevel::LOG_WARNING, output);
            break;
        case Rml::Log::LT_INFO:
            TraceLog(TraceLogLevel::LOG_INFO, output);
            break;
        case Rml::Log::LT_DEBUG:
            TraceLog(TraceLogLevel::LOG_DEBUG, output);
            break;
        case Rml::Log::LT_ALWAYS:
        case Rml::Log::LT_MAX:
            break;
    }

    return true;
}

Rml::Input::KeyIdentifier RaylibSystemInterface::ConvertKey(KeyboardKey key) {
    if (keyMap.contains(key)) {
        return keyMap[key];
    }

    return Rml::Input::KI_UNKNOWN;
}

int RaylibSystemInterface::ConvertKeyModifiers() {
    int keyModifier = 0;

    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
        keyModifier |= Rml::Input::KM_SHIFT;
    }

    if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
        keyModifier |= Rml::Input::KM_CTRL;
    }

    if (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)) {
        keyModifier |= Rml::Input::KM_ALT;
    }

    if (IsKeyDown(KEY_CAPS_LOCK)) {
        keyModifier |= Rml::Input::KI_CAPITAL;
    }

    if (IsKeyDown(KEY_SCROLL_LOCK)) {
        keyModifier |= Rml::Input::KI_SCROLL;
    }

    if (IsKeyDown(KEY_NUM_LOCK)) {
        keyModifier |= Rml::Input::KI_NUMLOCK;
    }

    return keyModifier;
}

void RaylibSystemInterface::HandleKeyboardEvents(Rml::Context* context) {
    Initialize();
    auto delta = GetFrameTime();

    if (timer > 0) {
        timer -= delta;
    }

    for (auto &key: keyMap) {
        if (IsKeyPressed(key.first)) {
            context->ProcessKeyDown(key.second, ConvertKeyModifiers());
            timer = 0.5;
            break;
        }

        if (IsKeyDown(key.first) && timer <= 0) {
            context->ProcessKeyDown(key.second, ConvertKeyModifiers());
        }

        if (IsKeyReleased(key.first)) {
            context->ProcessKeyUp(key.second, ConvertKeyModifiers());
            timer = 0.5;
        }
    }

    auto input = GetCharPressed();

    if (input != 0) {
        context->ProcessTextInput(input);
        input = GetCharPressed();
    }
}

void RaylibSystemInterface::HandleMouseEvents(Rml::Context* context) {
    if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT)) {
        context->ProcessMouseButtonDown(0, 0);
    }

    if (IsMouseButtonReleased(MouseButton::MOUSE_BUTTON_LEFT)) {
        context->ProcessMouseButtonUp(0, 0);
    }
}

void RaylibSystemInterface::GetClipboardText(Rml::String &text) {
    text = ::GetClipboardText();
}

void RaylibSystemInterface::SetClipboardText(const Rml::String &text) {
    ::SetClipboardText(text.c_str());
}

void RaylibSystemInterface::SetMouseCursor(const Rml::String &cursor_name) {
    if (cursor_name.empty() || cursor_name == "arrow") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_ARROW);
    } else if (cursor_name == "move" || cursor_name == "pointer") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_POINTING_HAND);
    } else if (cursor_name == "resize") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_RESIZE_ALL);
    } else if (cursor_name == "cross") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_CROSSHAIR);
    } else if (cursor_name == "text") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_IBEAM);
    } else if (cursor_name == "unavailable") {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_NOT_ALLOWED);
    } else if (Rml::StringUtilities::StartsWith(cursor_name, "rmlui-scroll")) {
        ::SetMouseCursor(MouseCursor::MOUSE_CURSOR_ARROW);
    }
}
