#pragma once
#include "Element.h"
#include "Head.h"
#include "Types.h"
#include "UIItem.h"
#include "UIStatus.h"
#include "UISystem.h"

class UI : public Element
{
private:
    UI();
    ~UI();
    //UI菜单单例即可，无需重复创建
    int current_head_ = 0;
    int current_button_ = 0;

public:
    virtual void onEntrance() override;
    virtual void draw() override;
    virtual void dealEvent(BP_Event& e) override;

    static UI* getInstance()
    {
        static UI ui;
        return &ui;
    }

    std::shared_ptr<Menu> heads_;
    std::vector<std::shared_ptr<Button>> buttons_;

    std::shared_ptr<Button> button_status_, button_item_, button_system_;
    std::shared_ptr<UIStatus> ui_status_;
    std::shared_ptr<UIItem> ui_item_;
    std::shared_ptr<UISystem> ui_system_;
    int item_id_ = -1;

    virtual void onPressedOK() override;
    DEFAULT_CANCEL_EXIT;
    Item* getUsedItem() { return ui_item_->getCurrentItem(); }
};
