#include <stdio.h> 
#include <math.h> 

int main(){

    float rho, u, D, mew;
    float nLam = 1;
    float nTurb;
    float g = 9.81;
    float f; 
    mew = 0.0010016; 
    rho = 998; 
    float length = 0.524;
    D = 0.003; 
    float lowA[8] = {0}; 
    float lowB[8] = {0};
    float lowAv[8]; 
    float heights[8];
    float HydGrad[16];
    float volA[16];
    float volB[16];
    float timeA[16];
    float timeB[16];
    float volAv[16];
    float timeAv[16];
    float volFlow[16];


    printf("\n");

    for(int i=0;i<8;i++)
    {
        printf("Please enter heights A and B for low flow trail no.%d:   ", i+1);
        scanf("%f %f", &lowA[i], &lowB[i]);
    }

    for(int i=0;i<8;i++)
    {
        lowAv[i] = ((lowA[i]/1000)+(lowB[i]/1000))/2;
    }

    for(int i=0;i<8;i++)
    {
        printf("Please enter heights for high flow trail no.%d:   ", i+1);
        scanf("%f", &heights[i]);
    }


     for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        HydGrad[i] = lowAv[i]/length;
        printf("\nHydrGrad = %f", HydGrad[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        HydGrad[i+8] = (heights[i]/1000)/length;
        printf("\nHydrGrad = %f", HydGrad[i+8]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("Please enter volumes A and B for low flow trail no.%d:   ", i+1);
        scanf("%f %f", &volA[i], &volB[i]);
    }

    for(int i=0;i<8;i++)
    {
        printf("Please enter volumes A and B for high flow trail no.%d:   ", i+1);
        scanf("%f %f", &volA[i+8], &volB[i+8]);
    }

        for(int i=0;i<8;i++)
    {
        printf("Please enter times A and B for low flow trail no.%d:   ", i+1);
        scanf("%f %f", &timeA[i], &timeB[i]);
    }

    for(int i=0;i<8;i++)
    {
        printf("Please enter times A and B for high flow trail no.%d:   ", i+1);
        scanf("%f %f", &timeA[i+8], &timeB[i+8]);
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        volAv[i] = ((volA[i]/1000000)+(volB[i]/1000000))/2;
        printf("\nvolAv = %f", volAv[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        volAv[i+8] = ((volA[i+8]/1000000)+(volB[i+8]/1000000))/2;
        printf("\nvolAv = %f", volAv[i+8]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        timeAv[i] = (timeA[i]+timeB[i])/2;
        printf("\ntimeAv = %f", timeAv[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        timeAv[i+8] = (timeA[i+8]+timeB[i+8])/2;
        printf("\ntimeAv = %f", timeAv[i+8]);
        printf("\n---------------------------------------------------------");
    }


    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        volFlow[i] = volAv[i]/timeAv[i];
        printf("\nvolFlow = %f", volFlow[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        volFlow[i+8] = volAv[i+8]/timeAv[i+8];
        printf("\nvolFlow = %f", volFlow[i+8]);
        printf("\n---------------------------------------------------------");
    }

    float area = (D*D)*3.14/4;

    float vel[16];

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        vel[i] = volFlow[i]/area;
        printf("\nvel = %f", vel[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        vel[i+8] = volFlow[i+8]/area;
        printf("\nvel = %f", vel[i+8]);
        printf("\n---------------------------------------------------------");
    }



    float Re[16];

        for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- Low flow Trail no.%d----------------------------", i+1);
        Re[i] = vel[i]*rho*D/mew;
        printf("\nRe = %f", Re[i]);
        printf("\n---------------------------------------------------------");
    }

    for(int i=0;i<8;i++)
    {
        printf("\n\n---------------- high flow Trail no.%d----------------------------", i+1);
        Re[i+8] = vel[i+8]*rho*D/mew;
        printf("\nRe = %f", Re[i+8]);
        printf("\n---------------------------------------------------------");
    }


   
    printf("\n\n\n");


    return 0; 
}