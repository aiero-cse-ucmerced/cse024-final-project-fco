// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef ENUMS_H
#define ENUMS_H

enum TOOL {
    // core tools
    PAINT_BRUSH,
    ERASER,
    SELECTOR,

    // shape tools
    SHAPE_CIRCLE,
    SHAPE_PENTAGON,
    SHAPE_RECTANGLE,
    SHAPE_STAR,
    SHAPE_DIAMOND,
    SHAPE_TRIANGLE,

    // default tool
    UNKNOWN
};

enum BASE_COLORS {
    BASE_RED,
    BASE_ORANGE,
    BASE_PURPLE,
    BASE_GREEN,
    BASE_BLUE,
    BASE_YELLOW,
    BASE_BLACK,
};

enum CANVAS_RECORD_ACTION {
    CANVAS_RECORD_CREATE_SHAPE,
    CANVAS_RECORD_DELETE_SHAPE,
    CANVAS_RECORD_DELETE_GROUP_SHAPES,
};

#endif