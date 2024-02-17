#include <stdio.h> 
#include <math.h> 

int main(){

    float rho, u, D;
    float g = 9.81; 
    rho = 998; 
    D = 0.003; 
    float lowA[10] = {0.308, 0.290, 0.280, 0.260, 0.256, 0.336, 0.320, 0.314, 0.310, 0.300}; 
    float lowB[10] = {0.160, 0.176, 0.198, 0.220, 0.244, 0.140, 0.158, 0.162, 0.170, 0.184};
    float lowC[10] = {0.286, 0.278, 0.266, 0.252, 0.250, 0.302, 0.290, 0.288, 0.288, 0.280}; 
    float lowD[10] = {0.290, 0.280, 0.268, 0.256, 0.252, 0.306, 0.294, 0.292, 0.288, 0.282};
    float lowE[10] = {0.298, 0.288, 0.272, 0.256, 0.254, 0.318, 0.302, 0.302, 0.294, 0.286}; 
    float lowF[10] = {0.114, 0.136, 0.168, 0.210, 0.240, 0.88, 0.118, 0.124, 0.132, 0.156};
    float lowG[10] = {0.138, 0.158, 0.188, 0.218, 0.240, 0.122, 0.148, 0.152, 0.160, 0.178}; 
    float lowH[10] = {0.136, 0.156, 0.184, 0.216, 0.240, 0.120, 0.144, 0.150, 0.158, 0.174};
    float lowI[10] = {0.020, 0.048, 0.080, 0.100, 0.138, 0.008, 0.038, 0.04, 0.05, 0.068};
    float weight[10] = {18, 18, 12, 12, 6, 24, 24, 24, 18, 18};
    float timeA[10] = {48.34, 56.78, 45.53, 68.78, 65.85, 60.74, 63.88, 68.56, 54.76, 58.89};
    float timeB[10] = {49.07, 56.53, 45.51, 67.20, 62.17, 62.11, 65.85, 69.66, 54.17, 60.68};
    float timeAv[10] = {0};
    float areaAC = 0.000531;
    float areaDG = 0.00213;
    float areaH = 0.00126;
    float areaE = 0.000314;

    float volFlow[10];

    float vAC[10];
    float vDG[10];
    float vH[10];
    float vE[10];

    float v_head_AC[10];
    float v_head_DG[10];
    float v_head_H[10];

    float head_L_AC[10]; 
    float head_L_CD[10]; 
    float head_L_EF[10];
    float head_L_GH[10]; 


    printf("\n");


    for(int i=0;i<10;i++)
    {
        timeAv[i] = (timeA[i] + timeB[i])/2;
    }


    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        volFlow[i] = weight[i]/(timeAv[i]*rho);
        printf("\nvolFlow = %f", volFlow[i]);
        printf("\n----------------------------------------------------");
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        vAC[i] = (volFlow[i]/areaAC);
        printf("\nvAC = %f", vAC[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        vDG[i] = (volFlow[i]/areaDG);
        printf("\nvDG = %f", vDG[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        vH[i] = (volFlow[i]/areaH);
        printf("\nvH = %f", vH[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        vE[i] = (volFlow[i]/areaE);
        printf("\nvE = %f", vE[i]);
        printf("\n----------------------------------------------------");
    }


////////////////////////////////////////////////////////////////////////////////////////


    float v_head_EF[10]; 

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        v_head_AC[i] = (vAC[i]*vAC[i])/(2*g);
        printf("\nv_head_AC = %f", v_head_AC[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        v_head_DG[i] = (vDG[i]*vDG[i])/(2*g);
        printf("\nv_head_DG = %f", v_head_DG[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        v_head_EF[i] = (vE[i]*vE[i])/(2*g);
        printf("\nv_head_EF = %f", v_head_EF[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        v_head_H[i] = (vH[i]*vH[i])/(2*g);
        printf("\nv_head_H = %f", v_head_H[i]);
        printf("\n----------------------------------------------------");
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Head loss 



    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        head_L_AC[i] = lowA[i] - lowC[i];
        printf("\nhead_L_AC = %f", head_L_AC[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        head_L_CD[i] = (lowC[i] - lowD[i]) + ( ( (vAC[i]*vAC[i]) - (vDG[i]*vDG[i]) ) / (2*g) ) ;
        printf("\nhead_L_CD = %f", head_L_CD[i]);
        printf("\n----------------------------------------------------");
    }


    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        head_L_EF[i] = (lowE[i] - lowF[i]) + (  ( ( (vE[i]*vE[i]) - (vDG[i]*vDG[i]) ) ) / (2*g) );
        printf("\nhead_L_EF = %f", head_L_EF[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        head_L_GH[i] = 0.001 + (lowG[i] - lowH[i]) + ( ( ( (vDG[i]*vDG[i]) - (vH[i]*vH[i]) ) ) / (2*g) );
        printf("\nhead_L_GH = %f", head_L_GH[i]);
        printf("\n----------------------------------------------------");
    }




/////////////////////////////////////////////////////////////////////////////////////////////////////
    // For finding K 

    float K_AC[10];
    float K_CD[10];
    float K_EF[10];
    float K_GH[10];



    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        K_AC[i] = head_L_AC[i]/v_head_AC[i];
        printf("\nK_AC = %f", K_AC[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        K_CD[i] = head_L_CD[i]/v_head_AC[i] ;
        printf("\nK_CD = %f", K_CD[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        K_EF[i] = head_L_EF[i]/v_head_EF[i];
        printf("\nK_EF = %f", K_EF[i]);
        printf("\n----------------------------------------------------");
    }

    for(int i=0;i<10;i++)
    {
        printf("\n\n---------------- Trail no.%d----------------------------", i+1);
        K_GH[i] = head_L_GH[i]/v_head_DG[i];
        printf("\nK_GH = %f", K_GH[i]);
        printf("\n----------------------------------------------------");
    }
   
    printf("\n\n\n");


    return 0; 
}