#include <stdio.h> 
#include <math.h> 

int main(){

    float rho = 998;
    float g = 9.81; 
    float HR[6] = {0.061, 0.054, 0.046, 0.043, 0.034, 0.026}; 
    float weightR[6] = {24, 24, 18, 18, 12 ,12};
    float timeAR[6] = {26.31, 32.95, 29.49, 35.06, 33.89, 47.18};
    float timeBR[6] = {27.48, 33.55, 30.85, 32.71, 33.03, 43.73};
    float timeAvR[6] = {0};

    float volFlowR[6];

    float HV1[6] = {0.087, 0.079, 0.065, 0.055, 0.050, 0.045}; 
    float weightV1[6] = {24, 24, 18, 12, 6, 6};
    float timeAV1[6] = {27.41, 37.92, 42.51, 43.71, 24.12, 40.40};
    float timeBV1[6] = {27.43, 38.41, 42.47, 43.37, 24.43, 41.96};
    float timeAvV1[6] = {0};

    float volFlowV1[6];

    float HV2[6] = {0.048, 0.045, 0.043, 0.040, 0.034, 0.029}; 
    float weightV2[6] = {24, 18, 18, 18, 12, 6};
    float timeAV2[6] = {26.87, 23.25, 26.21, 30.68, 29.59, 23.94};
    float timeBV2[6] = {27.61, 23.58, 26.29, 30.61, 28.12, 23.57};
    float timeAvV2[6] = {0};

    float volFlowV2[6];






    printf("\n");

//Rectangluar notch 

    for(int i=0;i<6;i++)
    {
        timeAvR[i] = (timeAR[i] + timeBR[i])/2.0;
    }


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        volFlowR[i] = weightR[i]/(timeAvR[i]*rho);
        printf("\nvolFlowR = %f", volFlowR[i]);
        printf("\n----------------------------------------------------");
    }

//V notch 30 degree


    for(int i=0;i<6;i++)
    {
        timeAvV1[i] = (timeAV1[i] + timeBV1[i])/2.0;
    }


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        volFlowV1[i] = weightV1[i]/(timeAvV1[i]*rho);
        printf("\nvolFlowV1 = %f", volFlowV1[i]);
        printf("\n----------------------------------------------------");
    }

//V notch 90 degree


    for(int i=0;i<6;i++)
    {
        timeAvV2[i] = (timeAV2[i] + timeBV2[i])/2.0;
    }


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        volFlowV2[i] = weightV2[i]/(timeAvV2[i]*rho);
        printf("\nvolFlowV2 = %f", volFlowV2[i]);
        printf("\n----------------------------------------------------");
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////

//rectangular 

    double QthyR[6]; 
    double term1 = 4.4294;
    float lenR = 0.030; 
    double term2; 
    float term3 = 2.0/3.0; 

    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        term2 = pow(HR[i],(3.0/2.0));
        QthyR[i] = (term1)*(lenR)*(term2)*(term3);
        printf("\nQthyR = %lf", QthyR[i]);
        printf("\n----------------------------------------------------");
    }

//V notch wit da 30 degrees 

    double QthyV1[6]; 
    float tanTerm = 0.267949; 
    term3 = 8.0/15.0; 

    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        term2 = pow(HV1[i],(5.0/2.0));
        QthyV1[i] = (term1)*(tanTerm)*(term2)*(term3);
        printf("\nQthyV1 = %lf", QthyV1[i]);
        printf("\n----------------------------------------------------");
    }


//notch with the 90 V

    double QthyV2[6]; 
    tanTerm = 1; 

    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        term2 = pow(HV2[i],(5.0/2.0));
        QthyV2[i] = (term1)*(tanTerm)*(term2)*(term3);
        printf("\nQthyV2 = %lf", QthyV2[i]);
        printf("\n----------------------------------------------------");
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////

//rectangular 

    double QexpR[6]; 


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        QexpR[i] = (0.0495)*pow(HR[i],1.4417);
        printf("\nQexpR = %lf", QexpR[i]);
        printf("\n----------------------------------------------------");
    }


//V notch wit da 30 degrees 

    double QexpV1[6]; 


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        QexpV1[i] = (1.382)*pow(HV1[i], 0.3927);
        printf("\nQexpV1 = %lf", QexpV1[i]);
        printf("\n----------------------------------------------------");
    }


//notch with the 90 V

    double QexpV2[6]; 


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        QexpV2[i] = (3.965)*pow(HV2[i], 2.7838);
        printf("\nQexpV2 = %lf", QexpV2[i]);
        printf("\n----------------------------------------------------");
    }







//////////////////////////////////////////////////////////////////////////////////////////////////////

//rectangular 

    double QpubR[6]; 
    double CdR; 
    double KR; 
    float nR = 1.4417; 


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        CdR = 0.564 + (0.0846*(HR[i]/0.1));
        KR = (2.0/3.0)*(CdR)*(sqrt(2*g))*(lenR);
        QpubR[i] = KR*pow(HR[i],nR);
        printf("\nQpubR = %lf", QpubR[i]);
        printf("\nCdR = %lf", CdR);
        printf("\n----------------------------------------------------");
    }

//V notch wit da 30 degrees 

    double QpubV1[6]; 
    float reynolds, webers; 
    double Cdv1; 
    double KV1; 
    float nV = 0.3927; 
    float mew = 0.001;
    float gamma = 0.0728; 
    float tan30 = 0.267949;


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        reynolds = rho*sqrt(g)*pow(HV1[i], 1.50)/mew;
        webers = rho*g*pow(HV1[i], 2)/gamma;
        Cdv1 = 0.44 + (0.9/pow(reynolds*webers, (1.0/6.0)));
        KV1 = (8.0/15.0)*(Cdv1)*(sqrt(2*g))*tan30;
        QpubV1[i] = KV1*pow(HV1[i],(5.0/2.0));
        printf("\nQpubV1 = %lf", QpubV1[i]);
        printf("\nCdv1 = %lf", Cdv1);
        printf("\n----------------------------------------------------");
    }


//notch with the 90 V

    double QpubV2[6]; 
    float nV2 = 2.8738;
    double Cdv2; 
    float tan90 = 1.0; 
    double KV2;


    for(int i=0;i<6;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        reynolds = rho*sqrt(g)*pow(HV2[i] , 1.50)/mew;
        webers = rho*g*pow(HV2[i], 2)/gamma;
        Cdv2 = 0.44 + (0.9/pow(reynolds*webers, (1.0/6.0)));
        KV2 = (8.0/15.0)*(Cdv2)*(sqrt(2*g))*tan90;
        QpubV2[i] = KV2*pow(HV2[i],(5.0/2.0));
        printf("\nQpubV2 = %lf", QpubV2[i]);
        printf("\nCdv2 = %lf", Cdv2);
        printf("\n----------------------------------------------------");
    }









    printf("\n\n\n");


    return 0; 
}