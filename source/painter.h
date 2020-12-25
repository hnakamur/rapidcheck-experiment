#ifndef PAINTER_H_
#define PAINTER_H_

class Painter {
  public:
    Painter(Turtle* turtle): turtle_(turtle) {}
  
    int DrawCircle(int x, int y, int r) {
      turtle_->PenDown();
      return 1;
    }
  
  private:
    Turtle* turtle_;
};

#endif // PAINTER_H_
