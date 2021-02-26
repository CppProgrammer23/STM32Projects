#ifndef CUSTOMCONTAINER_EVENT_HPP
#define CUSTOMCONTAINER_EVENT_HPP


#include <gui_generated/containers/CustomContainer_eventBase.hpp>
#include <string>
#include <memory>

//class Screen_agendaView;
class CustomContainer_event : public CustomContainer_eventBase
{
public:
    CustomContainer_event();
    //CustomContainer_event(Screen_agendaView& sc);
    virtual ~CustomContainer_event() {}

    virtual void initialize();

    void Return_to_Agenda()override;
    void Save_Note()override;
    void Add_point()override;
    void Add_plus()override;
    void Add_Underscore()override;
    void Add_minus()override;
    void Add_zero()override;
    void Add_space()override;
    void Add_A()override;
    void Add_Z()override;
    void Add_NewLine()override;
    void Add_Delete()override;
    void Add_E()override;
    void Add_R()override;
    void Add_T()override;
    void Add_Y()override;
    void Add_U()override;
    void Add_I()override;
    void Add_O()override;
    void Add_P()override;
    void Add_Q()override;
    void Add_N()override;
    void Add_V()override;
    void Add_X()override;
    void Add_W()override;
    void Add_S()override;
    void Add_B()override;
    void Add_H()override;
    void Add_L()override;
    void Add_M()override;
    void Add_C()override;
    void Add_K()override;
    void Add_F()override;
    void Add_G()override;
    void Add_J()override;
    void Add_D()override;
    void Add_1()override;
    void Add_2()override;
    void Add_3()override;
    void Add_4()override;
    void Add_5()override;
    void Add_6()override;
    void Add_7()override;
    void Add_8()override;
    void Add_9()override;
    void Add_shift()override;
    void Add_Excla()override;
    void Add_Intero()override;
    void Add_comma()override;
    void Add_ComPoint()override;
    void Add_Percent()override;
    void Add_at()override;
    void Add_Chap()override;
    void Add_slash()override;
    void Add_Anpersand()override;
    void Add_dollar_pound()override;
    void Add_equal()override;
    void Add_apos()override;
    void Add_Virg()override;


protected:
    int pos_cursor = 0, shif = 1;
    std::string text ;
};

#endif // CUSTOMCONTAINER_EVENT_HPP
