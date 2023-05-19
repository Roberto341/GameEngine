#include "font.h"

namespace Engine { namespace Graphics {

	Font::Font(std::string name, std::string filename, int size)
		: m_Name(name), m_Filename(filename), m_Size(size)
	{
		m_FTAtlas = ftgl::texture_atlas_new(512, 512, 2);
		m_FTFont = ftgl::texture_font_new_from_file(m_FTAtlas, size, filename.c_str());
	}

	Font::~Font()
	{

	}
}}