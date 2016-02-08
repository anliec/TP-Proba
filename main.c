#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"

#define ARRAY_MAX_SIZE 1000


int rdtsc()
{
    // cette fonction cree un warning : c'est normal.
    __asm__ __volatile__("rdtsc");
}


int main()
{
    word16 x=1111; // nombre entre 1000 et 9999 pour Von Neumann
    struct mt19937p mt; // Pour Mersenne-Twister
    int tmp = rand(); // Pour Mersenne-Twister
    u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES

    int output_rand; // sortie du rand du C
    word32 output_AES; // sortie pour l'AES
    word16 output_VN; // sortie pour pour Von Neumann
    word32 output_MT; // sortie pour Mersenne-Twister


    // initialisation des graines des generateurs
    srand(rdtsc());  // rand du C
    sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
    // Initialisation de la clé et du plaintext pour l'AES
    // 45 est un paramètre qui doit changer à chaque initialisation
    init_rand(Kx, Px, NK, NB, 45);
    KeyExpansion(Kex,Kx); // AES : sous-clefs

    ///init files
    FILE* rand_file = fopen("output/rand_value.m","w");
    FILE* VN_file = fopen("output/VN_value.m","w");
    FILE* MT_file = fopen("output/MT_value.m","w");
    FILE* AES_file = fopen("output/AES_value.m","w");

    fprintf(rand_file,"function [x] = randValue()\nx = [");
    fprintf(VN_file,"function [x] = vnValue()\nx = [");
    fprintf(MT_file,"function [x] = mtValue()\nx = [");
    fprintf(AES_file,"function [x] = aesValue()\nx = [");

    int nbr_ite = 10;
	int i;
	
    for( i=0 ; i<nbr_ite-1 ; i++)
    {
        // sorties des generateurs
        output_rand = rand(); // rand du C
        output_VN = Von_Neumann(&x); // Von Neumann
        output_MT = genrand(&mt); // Mersenne-Twister
        output_AES = AES(Px, Kex); // AES

        // affichage
        fprintf(rand_file," %u;",output_rand);
        fprintf(VN_file, " %u;",output_VN);
        fprintf(MT_file," %u;",output_MT);
        fprintf(AES_file," %u;",output_AES);
    }

    // sorties des generateurs
    output_rand = rand(); // rand du C
    output_VN = Von_Neumann(&x); // Von Neumann
    output_MT = genrand(&mt); // Mersenne-Twister
    output_AES = AES(Px, Kex); // AES

    // affichage
    fprintf(rand_file," %u",output_rand);
    fprintf(VN_file, " %u",output_VN);
    fprintf(MT_file," %u",output_MT);
    fprintf(AES_file," %u",output_AES);

    fprintf(rand_file,"]\nend");
    fprintf(VN_file,"]\nend");
    fprintf(MT_file,"]\nend");
    fprintf(AES_file,"]\nend");

    return 0;
}
