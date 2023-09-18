#include "Car_Car_Res.h"


int Car_Car_Res::Collide(Car c1, Car c2)
{
    //add in sequence of conditions and effects here
    bool collision = true; //just a filler for now until tie in coll_detection

    if (collision)  //may be able to remove this condition later
    {
        //c1 hits c2 in center while c2 at rest
        float c1_y_center = (c1.getPos_FD().getY() + c1.getPos_FP().getY())/2.0f;
        float c1_x_center = c1.getPos_FD().getX();
        float c2_y_center = (c2.getPos_FD().getY() + c2.getPos_FP().getY())/2.0f;
        float c2_x_center = c2.getPos_FD().getX();
        printf("Car 1 Center: %f, %f; Car 2 Center: %f, %f\n", c1_x_center, c1_y_center, c2_x_center, c2_y_center);
        if (c1_x_center==c2_x_center && c1_y_center==c2_y_center)
        {
            //effect on c2 by c1
            //c2.Update(2, c1.getMass(), c1.getAccel());
            //effect on c1 by c2
            //c1.Update(2, c2.getMass(), c2.getAccel());  //c2's acceleration sohuld be (0,0,0,1) because it's at rest

            printf("Car collision occured at (%f, %f, %f)!\n\n", c1_x_center, c1_y_center, c1.getPos_FD().getZ());
            int i = 0;
            while (i < 3)
            {
                c2.MoveForward(15.0f);
                i++;
            }
            float c2_post_coll_x = c2.getPos_FD().getX();
            printf("Car 2's new center-front position is: (%f, %f)\n", c2_post_coll_x, c2_y_center);
            return 1;

        }
        else
        {
            printf("No car collisions in this frame\n");
            return 0;
        }

        //c1 hits c2 in center while c2 not at rest
            //c1 has greater velocity
            //c2 has greater velocity
            //equal velocity
        
        //c1 hits c2 from bottom angle while c2 at rest

        //c1 hits c2 from top angle while c2 at rest


    }
}