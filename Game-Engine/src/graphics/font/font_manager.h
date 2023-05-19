#pragma once
#include <vector>
#include "font.h"

namespace Engine { namespace Graphics {
		class FontManager
		{
		public:
			FontManager();
			~FontManager();
			static void add(Font* font);
			static Font* get(const std::string& name);
			static Font* get(const std::string& name, unsigned int size);
			static void clean();
		private:
			static std::vector<Font*> m_Fonts;
		};
}}