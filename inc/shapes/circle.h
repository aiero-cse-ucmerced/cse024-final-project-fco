// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Tool.h"
#include "../Enums.h"

class CircleTool : public aiero::Tool {
    TOOL _name = SHAPE_CIRCLE;
    
    public:
        CircleTool() {
            
        };

        // optional
        void onClick() {};
        void onMouseDown() {};
        void onMouseUp();

        // required
        void _activate() {
            
        };
        
        void _deactivate() {
            
        };

};

#endif