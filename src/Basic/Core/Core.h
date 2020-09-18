#ifndef BASIC_CORE_H
#define BASIC_CORE_H

namespace Basic
{

	/*
	 * The core ensure subsystems to be initialized and released at the proper order.
	 * The Engine will not work properly if the core isn't initialized before the application starts.
	 */
	class Core
	{
	public:
		static void Initialize();
		static void Release();
	};

}

#endif //BASIC_CORE_H
