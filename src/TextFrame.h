#ifndef TEXTFRAME_H_
#define TEXTFRAME_H_

#include <string>
#include <utility>

#include "Display.h"
#include "Player.h"
#include "ButtonFrame.h"

class TextFrame : public ButtonFrame
{
public:
    static const unsigned int kTextRow = 1;
    static const unsigned int kKeyboardRow = 2;
    static const unsigned int kMaxLength = 16;

    static const std::string keyboard;

    TextFrame(Player *player);
    virtual ~TextFrame();

    void enter();
    void exit();

    std::string getText();
    void setText(const std::string& text);
protected:
    void initializeButtons();

    void toggleShift();

    state_t upButtonPressed(state_t currentState);
    state_t downButtonPressed(state_t currentState);

    virtual state_t doneButtonClicked(state_t currentState, const std::string&);
    state_t letterButtonClicked(state_t currentState, const std::string& label);
    state_t backspaceButtonClicked(state_t currentState, const std::string&);
    state_t shiftButtonClicked(state_t currentState, const std::string&);
    state_t spaceButtonClicked(state_t currentState, const std::string&);
private:
    std::string text_;
    bool shift_;
};

#endif /* TEXTFRAME_H_*/
