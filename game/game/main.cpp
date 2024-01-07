
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const **) {
  // Create the main window
  const int wWidth = 1280;
  const int wHeight = 720;

  sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML window");

  // int r = 0;
  // int g = 255;
  // int b = 255;
  std::vector<float> shapeMoveSpeedX;
  std::vector<float> shapeMoveSpeedY;
  int sign = -1;

  std::vector<std::shared_ptr<sf::Shape>> shapes;
  for (float x = 0.0f; x < 10.0f; x++) {
    for (float y = 0.0f; y < 10.0f; y++) {
      // std::shared_ptr<sf::Shape> circle =
      //     std::make_shared<sf::CircleShape>(50.0f);
      // circle->setFillColor(sf::Color(y * 10, x * 10, 0));
      // circle->setPosition(wHeight - (x * 10), wWidth - (y * 10));
      // circle->setOrigin(50.0f, 50.0f);
      std::shared_ptr<sf::Shape> rect =
          std::make_shared<sf::RectangleShape>(sf::Vector2f(50.0f, 50.0f));
      rect->setOrigin(25.0f, 25.0f);
      rect->setFillColor(sf::Color(x * 10, y * 10, 0));
      rect->setPosition(x * 100.0f, y * 100.0f);
      // shapes.push_back(circle);
      shapes.push_back(rect);
      shapeMoveSpeedX.push_back((x + 2 * y) / 10.0f * sign);
      shapeMoveSpeedY.push_back((2 * x - y) / 10.0f);
      sign *= -1;
    }
  }

  // sf::CircleShape circle(50); 
  // circle.setFillColor(sf::Color(r, g, b));
  // circle.setPosition(300.0f, 300.0f);
  // float circleMoveSpeedX = 0.1f;
  // float circleMoveSpeedY = 0.1f;
  // circle.setOrigin(50.0f, 50.0f);

  // Set the Icon
  sf::Image icon;
  if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    return EXIT_FAILURE;
  }
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  // Load a sprite to display
  // sf::Texture texture;
  // if (!texture.loadFromFile(resourcePath() + "background.jpg")) {
  //   return EXIT_FAILURE;
  // }
  // sf::Sprite sprite(texture);

  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile(resourcePath() + "tuffy.ttf")) {
    return EXIT_FAILURE;
  }
  sf::Text text("Hello SFML", font, 50);
  text.setFillColor(sf::Color::Black);

  // Load a music to play
  // sf::Music music;
  // if (!music.openFromFile(resourcePath() + "doodle_pop.ogg")) {
  //   return EXIT_FAILURE;
  // }

  // Play the music
  // music.play();

  // Start the game loop
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Escape pressed: exit
      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Escape) {
        window.close();
      }
    }

    // bounce off walls
    for (int i = 0; i < shapes.size(); i++) {

      auto x = shapes[i]->getPosition().x;
      auto y = shapes[i]->getPosition().y;

      if (x <= 50.0f || x >= (float)wWidth - 50.0f) {
        shapeMoveSpeedX[i] *= -1.0f;
      }

      if (y <= 50.0f || y >= (float)wHeight - 50.0f) {
        shapeMoveSpeedY[i] *= -1.0f;
      }
    }
    // Clear screen
    window.clear();

    // Draw the sprite
    for (int i = 0; i < shapes.size(); i++) {
      window.draw(*shapes[i] /* sprite */);
      shapes[i]->move(shapeMoveSpeedX[i], shapeMoveSpeedY[i]);
    }

    // Draw the string
    window.draw(text);

    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}
