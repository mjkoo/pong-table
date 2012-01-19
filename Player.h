#ifndef PLAYER_H_
#define PLAYER_H_

#include <map>

#include "Display.h"

class Frame;

enum state_t
{
    kIdleState,
    kLoginState,
    kCreateState,
    kViewState,
    kMusicState,
    kPasswordState,
    kWaitingState,
    kLosingState,
    kTiedState,
    kWinningState,
    kOverState,
    kNoneState
};

class Player
{
public:
    static const unsigned int kUpMask = 0x4000;
    static const unsigned int kDownMask = 0x2000;
    static const unsigned int kLeftMask = 0x1000;
    static const unsigned int kRightMask = 0x0800;
    static const unsigned int kEnterMask = 0x0400;
    static const unsigned int kCupMask = 0x03ff;

    Player(Display *display);
    virtual ~Player();

    void run();
private:
    void changeState(state_t nextState);

    state_t currentState_;
    Frame *currentFrame_;
    std::map<state_t, Frame *> stateMap_;
};

#endif /* Player_H_ */