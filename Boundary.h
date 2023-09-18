//
// Created by thisn on 5/23/2023.
//

#ifndef PEOT_BOUNDARY_H
#define PEOT_BOUNDARY_H


class Boundary {
public:
    Boundary(float width, float height);
    ~Boundary();

    float getWidth() ;
    float getHeight() ;
    void setWidth(float width);
    void setHeight(float height);

private:
    float width;
    float height;
};


#endif //PEOT_BOUNDARY_H
