#include "example.h"
#include "raylibRmlUi.h"
#include "samples/basic/databinding/basicExample.h"
#include "samples/basic/databinding/eventsExample.h"
#include "samples/basic/databinding/formsExample.h"
#include "samples/basic/databinding/invadersExample.h"
#include "samples/event.h"
#include "samples/sample.h"

Rml::ElementDocument* document;

Rml::Vector2i Example::GetWindowSize()
{
	return Rml::Vector2i{1600, 900};
}

void Example::Initialize()
{
	Rml::Log::Message(Rml::Log::LT_INFO, "Initializing databinding example\n");
	Sample::runGame = RaylibRmlUi::Initialize(1600, 900);

	if (!Sample::runGame)
	{
		return;
	}

	RaylibRmlUi::LoadFont("LatoLatin-Bold.ttf");
	RaylibRmlUi::LoadFont("LatoLatin-BoldItalic.ttf");
	RaylibRmlUi::LoadFont("LatoLatin-Italic.ttf");
	RaylibRmlUi::LoadFont("LatoLatin-Regular.ttf");
	RaylibRmlUi::LoadFont("NotoEmoji-Regular.ttf");

	ExampleEventInstancer eventListenerInstancer;
	Rml::Factory::RegisterEventListenerInstancer(&eventListenerInstancer);

	if (!BasicExample::Initialize(RaylibRmlUi::Context) || !EventsExample::Initialize(RaylibRmlUi::Context) ||
		!InvadersExample::Initialize(RaylibRmlUi::Context) || !FormsExample::Initialize(RaylibRmlUi::Context))
	{
		Sample::runGame = false;
		return;
	}

	RaylibRmlUi::LoadRml("samples/basic/databinding.rml", "dataBinding", true);

	document = RaylibRmlUi::GetPage("dataBinding");

	document->GetElementById("title")->SetInnerRML("Data binding");
}

void Example::DeInitialize()
{
	RaylibRmlUi::DeInitialize();
}

const char* Example::GetWindowTitle()
{
	return "- Data binding";
}

void Example::ToggleDebugger()
{
	RaylibRmlUi::ToggleDebugger();
}

void Example::Update(float delta)
{
	EventsExample::Update();
	InvadersExample::Update(delta);
	RaylibRmlUi::Update();
}

void Example::Render()
{
	RaylibRmlUi::Draw();
}

bool Example::RunProgram()
{
	return Sample::runGame;
}

void Example::StopProgram()
{
	Sample::runGame = false;
}