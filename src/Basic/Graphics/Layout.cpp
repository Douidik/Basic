#include "Layout.h"
#include "Utility/Utility.h"

namespace Basic
{

	Layout::Layout(std::initializer_list<Attribute> attributes)
		: m_Attributes(attributes)
	{
		/* Calculating the offset of each attributes */
		size_t offset = 0;

		for (auto &attribute : m_Attributes)
		{
			attribute.offset = offset;
			offset += SizeOfGLType(attribute.type) * attribute.count;
		}

		m_Stride = offset;
	}

	void Layout::Bind() const
	{
		for (const auto &attribute : m_Attributes)
		{
			GLCall(glEnableVertexAttribArray(attribute.index));
		}
	}

	void Layout::UnBind() const
	{
		for (const auto &attribute : m_Attributes)
		{
			GLCall(glDisableVertexAttribArray(attribute.index));
		}
	}

}