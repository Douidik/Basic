#ifndef BASIC_KEYCODE_H
#define BASIC_KEYCODE_H

namespace Basic
{
	enum class KeyCode : int
	{
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348,
	};
}

#define BSC_KEY_SPACE           ::Basic::KeyCode::Space
#define BSC_KEY_APOSTROPHE      ::Basic::KeyCode::Apostrophe    /* ' */
#define BSC_KEY_COMMA           ::Basic::KeyCode::Comma         /* , */
#define BSC_KEY_MINUS           ::Basic::KeyCode::Minus         /* - */
#define BSC_KEY_PERIOD          ::Basic::KeyCode::Period        /* . */
#define BSC_KEY_SLASH           ::Basic::KeyCode::Slash         /* / */
#define BSC_KEY_0               ::Basic::KeyCode::D0
#define BSC_KEY_1               ::Basic::KeyCode::D1
#define BSC_KEY_2               ::Basic::KeyCode::D2
#define BSC_KEY_3               ::Basic::KeyCode::D3
#define BSC_KEY_4               ::Basic::KeyCode::D4
#define BSC_KEY_5               ::Basic::KeyCode::D5
#define BSC_KEY_6               ::Basic::KeyCode::D6
#define BSC_KEY_7               ::Basic::KeyCode::D7
#define BSC_KEY_8               ::Basic::KeyCode::D8
#define BSC_KEY_9               ::Basic::KeyCode::D9
#define BSC_KEY_SEMICOLON       ::Basic::KeyCode::Semicolon     /* ; */
#define BSC_KEY_EQUAL           ::Basic::KeyCode::Equal         /* = */
#define BSC_KEY_A               ::Basic::KeyCode::A
#define BSC_KEY_B               ::Basic::KeyCode::B
#define BSC_KEY_C               ::Basic::KeyCode::C
#define BSC_KEY_D               ::Basic::KeyCode::D
#define BSC_KEY_E               ::Basic::KeyCode::E
#define BSC_KEY_F               ::Basic::KeyCode::F
#define BSC_KEY_G               ::Basic::KeyCode::G
#define BSC_KEY_H               ::Basic::KeyCode::H
#define BSC_KEY_I               ::Basic::KeyCode::I
#define BSC_KEY_J               ::Basic::KeyCode::J
#define BSC_KEY_K               ::Basic::KeyCode::K
#define BSC_KEY_L               ::Basic::KeyCode::L
#define BSC_KEY_M               ::Basic::KeyCode::M
#define BSC_KEY_N               ::Basic::KeyCode::N
#define BSC_KEY_O               ::Basic::KeyCode::O
#define BSC_KEY_P               ::Basic::KeyCode::P
#define BSC_KEY_Q               ::Basic::KeyCode::Q
#define BSC_KEY_R               ::Basic::KeyCode::R
#define BSC_KEY_S               ::Basic::KeyCode::S
#define BSC_KEY_T               ::Basic::KeyCode::T
#define BSC_KEY_U               ::Basic::KeyCode::U
#define BSC_KEY_V               ::Basic::KeyCode::V
#define BSC_KEY_W               ::Basic::KeyCode::W
#define BSC_KEY_X               ::Basic::KeyCode::X
#define BSC_KEY_Y               ::Basic::KeyCode::Y
#define BSC_KEY_Z               ::Basic::KeyCode::Z
#define BSC_KEY_LEFT_BRACKET    ::Basic::KeyCode::LeftBracket   /* [ */
#define BSC_KEY_BACKSLASH       ::Basic::KeyCode::Backslash     /* \ */
#define BSC_KEY_RIGHT_BRACKET   ::Basic::KeyCode::RightBracket  /* ] */
#define BSC_KEY_GRAVE_ACCENT    ::Basic::KeyCode::GraveAccent   /* ` */
#define BSC_KEY_WORLD_1         ::Basic::KeyCode::World1        /* non-US #1 */
#define BSC_KEY_WORLD_2         ::Basic::KeyCode::World2        /* non-US #2 */

/* Function keys */
#define BSC_KEY_ESCAPE          ::Basic::KeyCode::Escape
#define BSC_KEY_ENTER           ::Basic::KeyCode::Enter
#define BSC_KEY_TAB             ::Basic::KeyCode::Tab
#define BSC_KEY_BACKSPACE       ::Basic::KeyCode::Backspace
#define BSC_KEY_INSERT          ::Basic::KeyCode::Insert
#define BSC_KEY_DELETE          ::Basic::KeyCode::Delete
#define BSC_KEY_RIGHT           ::Basic::KeyCode::Right
#define BSC_KEY_LEFT            ::Basic::KeyCode::Left
#define BSC_KEY_DOWN            ::Basic::KeyCode::Down
#define BSC_KEY_UP              ::Basic::KeyCode::Up
#define BSC_KEY_PAGE_UP         ::Basic::KeyCode::PageUp
#define BSC_KEY_PAGE_DOWN       ::Basic::KeyCode::PageDown
#define BSC_KEY_HOME            ::Basic::KeyCode::Home
#define BSC_KEY_END             ::Basic::KeyCode::End
#define BSC_KEY_CAPS_LOCK       ::Basic::KeyCode::CapsLock
#define BSC_KEY_SCROLL_LOCK     ::Basic::KeyCode::ScrollLock
#define BSC_KEY_NUM_LOCK        ::Basic::KeyCode::NumLock
#define BSC_KEY_PRINT_SCREEN    ::Basic::KeyCode::PrintScreen
#define BSC_KEY_PAUSE           ::Basic::KeyCode::Pause
#define BSC_KEY_F1              ::Basic::KeyCode::F1
#define BSC_KEY_F2              ::Basic::KeyCode::F2
#define BSC_KEY_F3              ::Basic::KeyCode::F3
#define BSC_KEY_F4              ::Basic::KeyCode::F4
#define BSC_KEY_F5              ::Basic::KeyCode::F5
#define BSC_KEY_F6              ::Basic::KeyCode::F6
#define BSC_KEY_F7              ::Basic::KeyCode::F7
#define BSC_KEY_F8              ::Basic::KeyCode::F8
#define BSC_KEY_F9              ::Basic::KeyCode::F9
#define BSC_KEY_F10             ::Basic::KeyCode::F10
#define BSC_KEY_F11             ::Basic::KeyCode::F11
#define BSC_KEY_F12             ::Basic::KeyCode::F12
#define BSC_KEY_F13             ::Basic::KeyCode::F13
#define BSC_KEY_F14             ::Basic::KeyCode::F14
#define BSC_KEY_F15             ::Basic::KeyCode::F15
#define BSC_KEY_F16             ::Basic::KeyCode::F16
#define BSC_KEY_F17             ::Basic::KeyCode::F17
#define BSC_KEY_F18             ::Basic::KeyCode::F18
#define BSC_KEY_F19             ::Basic::KeyCode::F19
#define BSC_KEY_F20             ::Basic::KeyCode::F20
#define BSC_KEY_F21             ::Basic::KeyCode::F21
#define BSC_KEY_F22             ::Basic::KeyCode::F22
#define BSC_KEY_F23             ::Basic::KeyCode::F23
#define BSC_KEY_F24             ::Basic::KeyCode::F24
#define BSC_KEY_F25             ::Basic::KeyCode::F25

/* Keypad */
#define BSC_KEY_KP_0            ::Basic::KeyCode::KP0
#define BSC_KEY_KP_1            ::Basic::KeyCode::KP1
#define BSC_KEY_KP_2            ::Basic::KeyCode::KP2
#define BSC_KEY_KP_3            ::Basic::KeyCode::KP3
#define BSC_KEY_KP_4            ::Basic::KeyCode::KP4
#define BSC_KEY_KP_5            ::Basic::KeyCode::KP5
#define BSC_KEY_KP_6            ::Basic::KeyCode::KP6
#define BSC_KEY_KP_7            ::Basic::KeyCode::KP7
#define BSC_KEY_KP_8            ::Basic::KeyCode::KP8
#define BSC_KEY_KP_9            ::Basic::KeyCode::KP9
#define BSC_KEY_KP_DECIMAL      ::Basic::KeyCode::KPDecimal
#define BSC_KEY_KP_DIVIDE       ::Basic::KeyCode::KPDivide
#define BSC_KEY_KP_MULTIPLY     ::Basic::KeyCode::KPMultiply
#define BSC_KEY_KP_SUBTRACT     ::Basic::KeyCode::KPSubtract
#define BSC_KEY_KP_ADD          ::Basic::KeyCode::KPAdd
#define BSC_KEY_KP_ENTER        ::Basic::KeyCode::KPEnter
#define BSC_KEY_KP_EQUAL        ::Basic::KeyCode::KPEqual

#define BSC_KEY_LEFT_SHIFT      ::Basic::KeyCode::LeftShift
#define BSC_KEY_LEFT_CONTROL    ::Basic::KeyCode::LeftControl
#define BSC_KEY_LEFT_ALT        ::Basic::KeyCode::LeftAlt
#define BSC_KEY_LEFT_SUPER      ::Basic::KeyCode::LeftSuper
#define BSC_KEY_RIGHT_SHIFT     ::Basic::KeyCode::RightShift
#define BSC_KEY_RIGHT_CONTROL   ::Basic::KeyCode::RightControl
#define BSC_KEY_RIGHT_ALT       ::Basic::KeyCode::RightAlt
#define BSC_KEY_RIGHT_SUPER     ::Basic::KeyCode::RightSuper
#define BSC_KEY_MENU            ::Basic::KeyCode::Menu

#endif //BASIC_KEYCODE_H
