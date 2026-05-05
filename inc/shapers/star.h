void Rectangle::draw() {
    const BaseColor b = _color.toBase();
    glColor3f(b.r, b.g, b.b);
    
    glBegin(GL_POLYGON);
    glVertex2f(_x - width/2, _y + height/2);
        glVertex2f(_x + width/2, _y + height/2);
        glVertex2f(_x + width/2, _y - height/2);
        glVertex2f(_x - width/2, _y - height/2);
    glEnd();
}

void Star::draw() {
    const BaseColor bColor = _color.toBase();
    
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    const int VERTICES = 10;
    const float PI = 3.141592;
    const float TWO_PI = 2 * PI;

    const float startAngle = PI * 0.5;

    //Fill star
    glBegin(GL_POLYGON);
    for(int i = 0; i < VERTICES; i ++){
        float r;
        if(i % 2 ==0){
            r = outerRadius;
        } else {
            r = innerRadius;
        }
        //converted deg to rad
        float angle = startAngle + i * (TWO_PI / float(VERTICES)); 
        float vx = _x + r * cos(angle);
        float vy = _y + r * sin(angle);
        glVertex2f(vx, vy);  
    }
    glEnd();

    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < VERTICES; ++i) {
         float r;
        if(i % 2 ==0){
            r = outerRadius;
        } else {
            r = innerRadius;
        }
        //converted deg to rad
        float angle = startAngle + i * (TWO_PI / float(VERTICES)); 
        float vx = _x + r * cos(angle);
        float vy = _y + r * sin(angle);
        glVertex2f(vx, vy);
    }
    glEnd();
}
