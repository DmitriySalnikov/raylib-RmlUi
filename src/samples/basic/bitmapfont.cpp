#include "example.h"
#include "raylibRmlUi.h"
#include "samples/sample.h"
#include "samples/event.h"
#include "samples/basic/bitmapfont/FontEngineInterfaceBitmap.h"

Rml::ElementDocument* document;
std::unique_ptr<FontEngineInterfaceBitmap> fontEngine;

Rml::Vector2i Example::GetWindowSize() {
    return Rml::Vector2i{ 1024, 768 };
}

void Example::Initialize() {
    Rml::Log::Message(Rml::Log::LT_INFO, "Initializing bitmapfont example\n");
    fontEngine = Rml::MakeUnique<FontEngineInterfaceBitmap>();
    Rml::SetFontEngineInterface(fontEngine.get());

    Sample::runGame = RaylibRmlUi::Initialize(1024, 768);

    if (!Sample::runGame) {
        return;
    }

    if (!Rml::LoadFontFace("samples/basic/bitmapfont/data/Comfortaa_Regular_22.fnt")) {
        Sample::runGame = false;
        return;
    }

    ExampleEventInstancer eventListenerInstancer;
    Rml::Factory::RegisterEventListenerInstancer(&eventListenerInstancer);

    RaylibRmlUi::LoadRml("samples/basic/bitmapfont/data/bitmapfont.rml", "bitmapfont", true);

    document = RaylibRmlUi::GetPage("bitmapfont");

    document->GetElementById("title")->SetInnerRML("Bitmap font");
}

void Example::DeInitialize() {
    fontEngine.reset();
    RaylibRmlUi::DeInitialize();
}

const char* Example::GetWindowTitle() {
    return "- Bitmap Font";
}

void Example::ToggleDebugger() {
    RaylibRmlUi::ToggleDebugger();
}

void Example::Update(float delta) {
    RaylibRmlUi::Update();
}

void Example::Render() {
    RaylibRmlUi::Draw();
}

bool Example::RunProgram() {
    return Sample::runGame;
}

void Example::StopProgram() {
    Sample::runGame = false;
}