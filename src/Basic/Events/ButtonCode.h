#ifndef BASIC_BUTTONCODE_H
#define BASIC_BUTTONCODE_H

namespace Basic
{
	enum class ButtonCode : int
	{
		Left = 0,
		Right = 1,
		Middle = 2,
	};
}

#define BSC_BUTTON_LEFT   ::Basic::ButtonCode::Left
#define BSC_BUTTON_RIGHT  ::Basic::ButtonCode::Right
#define BSC_BUTTON_MIDDLE ::Basic::ButtonCode::Left

#define BSC_BUTTON_3      ::Basic::ButtonCode::Three
#define BSC_BUTTON_4      ::Basic::ButtonCode::Four
#define BSC_BUTTON_5      ::Basic::ButtonCode::Five
#define BSC_BUTTON_6      ::Basic::ButtonCode::Six
#define BSC_BUTTON_7      ::Basic::ButtonCode::Seven

#endif //BASIC_BUTTONCODE_H
