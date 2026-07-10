#pragma peephole off
#include "font/FontLoader.hpp"
#include "app/Application.hpp"

namespace font {
    FontLoader::FontLoader(FontKind kind) : mKind(kind) {
        app::Application::Instance->fontManager().font(mKind).load();
    }

    FontLoader::~FontLoader() {
        app::Application::Instance->fontManager().font(mKind).unload();
    }

}
