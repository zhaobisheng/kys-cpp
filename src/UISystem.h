#pragma once
#include "Element.h"
#include "Menu.h"

class UISystem : public Element
{
public:
    UISystem();
    ~UISystem();

    std::shared_ptr<MenuText> title_ = nullptr;

    virtual void onPressedOK() override;
    virtual void onPressedCancel() override { exitWithResult(-1); }

    static int askExit(int mode = 0);
};

