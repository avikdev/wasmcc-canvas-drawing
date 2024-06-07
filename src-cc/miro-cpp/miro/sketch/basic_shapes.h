#pragma once


namespace miro {

struct BasicShape {
  enum ShapeType {
    RECTANGLE = 0,
    ELLIPSE = 0,
  };

  ShapeType type = RECTANGLE;
};

}  // namespace miro
