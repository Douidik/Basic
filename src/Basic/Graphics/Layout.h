#ifndef BASIC_LAYOUT_H
#define BASIC_LAYOUT_H

namespace Basic
{

	class VertexBuffer;

	// properties of an vertex attribute
	struct Attribute
	{
		Attribute(int _index, size_t _count, GLenum _type, bool _normalized = false)
			: index(_index), count(_count), type(_type), normalized(_normalized), offset(0)
		{
		}

		size_t count;
		bool normalized;
		int index;
		GLenum type;
		// Number of bytes between the stride beginning and this attribute
		size_t offset;
	};

	class Layout
	{
	public:
		Layout() = default;
		Layout(std::initializer_list<Attribute> attributes);

		void Bind() const;
		void UnBind() const;

		inline size_t GetStride() const
		{
			return m_Stride;
		}

		inline std::vector<Attribute> &GetAttributes()
		{
			return m_Attributes;
		}

	private:

		size_t m_Stride;
		std::vector<Attribute> m_Attributes;
	};

}

#endif //BASIC_LAYOUT_H
