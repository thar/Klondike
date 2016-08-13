#ifndef KLONDIKE_MENUENTRY_H
#define KLONDIKE_MENUENTRY_H

#include <string>

class MenuEntryVisitor;

class MenuEntry
{
public:
    MenuEntry(std::string menuName) : menuName_(menuName) {}
    virtual void accept(MenuEntryVisitor &menuEntryVisitor) = 0;
    virtual void doAction() = 0;
    std::string getName() const { return menuName_; }
protected:
    const std::string menuName_;
private:
};


#endif //KLONDIKE_MENUENTRY_H
