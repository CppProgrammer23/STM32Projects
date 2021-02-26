#ifndef SCREEN_TIC_TAOVIEW_HPP
#define SCREEN_TIC_TAOVIEW_HPP

#include <gui_generated/screen_tic_tao_screen/Screen_TIC_TAOViewBase.hpp>
#include <gui/screen_tic_tao_screen/Screen_TIC_TAOPresenter.hpp>
#include <string>

class Screen_TIC_TAOView : public Screen_TIC_TAOViewBase
{
public:
    Screen_TIC_TAOView();
    virtual ~Screen_TIC_TAOView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent()override;

    void B1_Pushed()override;
    void B2_Pushed()override;
    void B3_Pushed()override;
    void B4_Pushed()override;
    void B5_Pushed()override;
    void B6_Pushed()override;
    void B7_Pushed()override;
    void B8_Pushed()override;
    void B9_Pushed()override;

    void SetDraName(std::string t);
    void Send26IName(std::string t);
    void SetXO_Ver(bool);
    void SetColored_Ver(bool);

    /* Extra Functions */
    void Dra();
    void _26I();
protected:
    int player;
    int tab[9] { 12,3,4,5,6,7,8,9,10 };
    bool win, set_player;
    static bool color;
    static std::string name;
};

#endif // SCREEN_TIC_TAOVIEW_HPP
