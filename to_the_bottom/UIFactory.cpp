#include "UIFactory.hpp"

#include "InputField.hpp"
#include "Button.hpp"

kp::InputField* kp::UIFactory::createInputField(sf::RenderWindow& window, sf::Event& event)
{
	kp::InputField* inputField = new kp::InputField;

	inputField->setWindow(window);
	inputField->setEvent(event);

	inputField->setInputArea(*(new sf::RectangleShape));
	inputField->setPlayerInput(*(new sf::String));
	inputField->setFont(*(new sf::Font));
	inputField->setDefaultText(*(new sf::Text));
	inputField->setPlayerText(*(new sf::Text));

	return inputField;
}

kp::Button* kp::UIFactory::createButton(sf::RenderWindow& window, sf::Event& event)
{
	kp::Button* button = new kp::Button;

	button->setWindow(window);
	button->setEvent(event);

	button->setButtonArea(*(new sf::RectangleShape));
	button->setButtonText(*(new sf::Text));

	return button;
}

kp::UIBase* kp::UIFactory::createUIElement(UIType type, sf::RenderWindow& window, sf::Event& event)
{
	switch (type)
	{
	case UIType::INPUT_FIELD:
		return createInputField(window, event);

	case UIType::BUTTON:
		return createButton(window, event);

	default:
		return nullptr;
	}
}