#include "../ecs/Vec2.cpp"
#include <SFML/Graphics.hpp>
#include <_types/_uint32_t.h>
#include <cstddef>
#include <iostream>
#include <ostream>

// todo mass?
typedef struct object {
  Vec2 pos, prev, acc;
  float radius;
  sf::Color color;
} Object;

void updatePosition(Object &state, float dt) {
  Vec2 v = state.pos - state.prev;
  state.prev = state.pos;
  state.pos += v;
  state.pos += state.acc * dt * dt;
  state.acc = {};
};

void accelerate(Object &state, Vec2 acc) { state.acc += acc; }

struct Solver {
  double t = 0.0;
  Vec2 gravity = {0.0f, 100.0f};
  std::vector<Object> objects;

  void update(float dt) {
    const uint32_t sub_steps = 8;
    const float sub_dt = dt / (float)(sub_steps);
    for (uint32_t i = 0; i < sub_steps; i++) {
      applyGravity();
      applyConstraint();
      solveCollisions();
      updatePositions(sub_dt);
    }
  }

  void updatePositions(float dt) {
    for (auto &o : objects) {
      updatePosition(o, dt);
      std::cout << o.pos.x << ", " << o.pos.y << std::endl;
    }
    t += dt;
  }

  void applyGravity() {
    for (auto &o : objects) {
      accelerate(o, gravity);
    }
  }

  void applyConstraint() {

    // #define
    Vec2 pos = {300.0f, 300.0f};
    const float radius = 250.0f;
    for (auto &o : objects) {
      Vec2 to_obj = o.pos - pos;
      const float dist = std::sqrt(to_obj.x * to_obj.x + to_obj.y * to_obj.y);
      std::cout << "dist: " << dist << std::endl;
      if (dist > radius - o.radius * 2) {
        Vec2 n = to_obj / dist;
        o.pos = pos + n * (radius - o.radius);
      }
    }
  }

  void solveCollisions() {
    ptrdiff_t count = objects.size();
    for (ptrdiff_t i = 0; i < count; i++) {
      Object &first = objects[i];
      for (ptrdiff_t j = i + 1; j < count; j++) {
        Object &second = objects[j];
        Vec2 collision_axis = first.pos - second.pos; // ?
        float dist = std::sqrt(collision_axis.x * collision_axis.x +
                               collision_axis.y * collision_axis.y);
        if (dist < first.radius + second.radius) {
          Vec2 n = collision_axis / dist;
          float delta = first.radius + second.radius - dist;
          Vec2 diff = n * 0.5f * delta;
          first.pos += diff;
          second.pos -= diff;
        }
      };
    };
  };
};
