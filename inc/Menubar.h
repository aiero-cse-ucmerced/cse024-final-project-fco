#ifndef MENUBAR_H
#define MENUBAR_H

#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>

namespace aiero {
    class Menubar : public bobcat::Group {
        bobcat::Menu* _obj;
        std::vector<bobcat::MenuItem*> _items;

        virtual void onSelection(bobcat::Widget* sender);
        
        public:
            Menubar(bobcat::Window* parent) : Group(0, 0, parent->w(), parent->h()) {
                _obj = new bobcat::Menu();
                _obj->parent(parent);            
                _obj->show();
            };

            ~Menubar() {
                for (bobcat::MenuItem* mitem : _items)
                    delete mitem;

                _items.clear();

                delete _obj;
                delete this;
            }

            bobcat::MenuItem* operator[](int index) {
                if (index < 0 || _items.size() < index+1) throw "Non existent index";
                return _items[index];
            };

            bobcat::MenuItem* operator[](std::string menuName) {
                for (bobcat::MenuItem* mitem : _items) {
                    if (mitem->label() == menuName)
                        return mitem;
                }
                
                throw "Non existent menu item " + menuName;
            };

            bobcat::MenuItem* addItem(std::string itemName) {
                bobcat::MenuItem* mitem = new bobcat::MenuItem(itemName);
                _obj->addItem(mitem);

                ON_CLICK(mitem, Menubar::onSelection);
                
                return mitem;
            }
            
    };

}

#endif
