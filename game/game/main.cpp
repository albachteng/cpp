
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include "../ecs/Game.cpp"
#include <memory>
#include <vector>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

using namespace std::chrono;

int main(int, char const **) {
  Game g("");
  g.run();
  return EXIT_SUCCESS;
}
