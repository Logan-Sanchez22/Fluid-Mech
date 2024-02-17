#include <stdio.h> 
#include <math.h> 

int main(){

    float w = 5.886;
    float d = 0.15; 
    float y[6]; 
    float Fm[6]; 

    printf("\n");

    for(int i=0;i<6;i++)
    {
        printf("Please enter Y for trail no.%d:   ", i);
        scanf("%f", &y[i]);
    }

    printf("\nMeasured-force = (weight-jockey)*(jockey-distance-from-level)/(vain-distance-from-level)");


     for(int i=0;i<6;i++)
    {
        printf("\n\n----------------- Trail no.%d----------------------------", i);
        Fm[i]= (w*(y[i])/d);
        printf("\nFm = %f*%f/%f", w, y[i], d);
        printf("\nFm = %f", Fm[i]);
        printf("\n---------------------------------------------------------");
    }

    printf("\n\n\n");

    float times[6];
    float t1,t2;

    for(int i=0;i<6;i++)
    {
        printf("Enter the times to be averaged for trail no.%d: ",i);
        scanf("%f", &t1);
        scanf("%f", &t2);
        times[i] = (t1+t2)/2; 
    }

    float mflow[6];

    for(int i=0;i<6;i++)
    {
        if(i<=2)
        {
            mflow[i] = (24/times[i]);
        }
        
        else 
        {
            mflow[i] = (18/times[i]);
        }
    } 

    float h = 0.035;
    float di = 0.01;
    double a = 0.00007854;
    float density = 998;
    float exVel[6];

    printf("\nExit-velocity = (mass-flow)/(rho*cross-sectional-area)");

    for(int i=0;i<6;i++)
    {
        exVel[i] = mflow[i]/(density*a);
        printf("\n\n----------------- Trail no.%d----------------------------", i);
        printf("\nu = %f/(%f*%lf)", mflow[i], density, a);
        printf("\nu = %f", exVel[i]);
        printf("\n---------------------------------------------------------");
    }

    float Uo[6];

    printf("\nJet-velocity = [(exit-velocity)^2] - 2(gravity)(distance-between-plate-and-nossle) ");

    for(int i=0;i<6;i++)
    {
        Uo[i] = sqrt((pow(exVel[i],2) - (2)*(9.81)*(h)));
        printf("\n\n----------------- Trail no.%d----------------------------", i);
        printf("\nUo = root( (%f^2) - 2(9.81)(%f) )", exVel[i], h);
        printf("\nUo = %f", Uo[i]);
        printf("\n---------------------------------------------------------");
    }

    int pick; 
    float Ft[6];

    printf("\n\nFlat(1), Semi(2), Hemi(3):  ");
    scanf("%d", &pick);

    if(pick==1)
    {
        printf("\nTherotical-force = (mass-flow)(jet-velocity)");
        for(int i=0;i<6;i++)
        {
            Ft[i] = mflow[i]*Uo[i];
            printf("\n\n----------------- Trail no.%d----------------------------", i);
            printf("\nF = %f*%f", mflow[i], exVel[i] );
            printf("\nF = %f", Ft[i]);
            printf("\n---------------------------------------------------------");
        }
       
    }

    else if(pick==2)
    {
        printf("\nTherotical-force = (mass-flow)(jet-velocity - exit-velocity*(cos120))");
        for(int i=0;i<6;i++)
        {
            Ft[i] = mflow[i]*(Uo[i] + exVel[i]*(0.5));
            printf("\n\n----------------- Trail no.%d----------------------------", i);
            printf("\nF = %f*(%f - %f*cos(135)", mflow[i], Uo[i], exVel[i]);
            printf("\nF = %f", Ft[i]);
            printf("\n---------------------------------------------------------");
        }
       
    }

    else if(pick==3)
    {
        printf("\nTherotical-force = (mass-flow)(2)(jet-velocity)");
        for(int i=0;i<6;i++)
        {
            Ft[i] = mflow[i]*(2*Uo[i]);
            printf("\n\n----------------- Trail no.%d----------------------------", i);
            printf("\nF = %f*(%f + %f)", mflow[i], exVel[i], Uo[i] );
            printf("\nF = %f", Ft[i]);
            printf("\n---------------------------------------------------------");
        }
       
    }

    return 0; 
}