#ifndef SL_TIME_H_
#define SL_TIME_H_

class Game;

class Time {
  /*
    This is so that only the Game class can modify
    the values in this class
  */
  friend class Game;
  
 public:
  /*
    Gets the time elapsed this frame
  */
  static float getDeltaTime() {
    return _deltaTime;
  }

  /*
    Gets the time elapsed since the beginning of the game
   */
  static float getTime() {
    return _time;
  }

 private:
  static void updateTime(float deltaTime) {
    _deltaTime = deltaTime;
    _time += _deltaTime;
  }
  
 private:
  static float _deltaTime;
  static float _time;
};

#endif
