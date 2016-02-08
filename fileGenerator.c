#include "fileGenerator.h"

#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"

word16 x;
struct mt19937p mt; // Pour Mersenne-Twister
int tmp;
u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES

void generateFile(int nbr_of_value)
{
    init();
    writeFile(nbr_of_value);
}

void init()
{
    x=1111; // nombre entre 1000 et 9999 pour Von Neumann
    tmp = rand(); // Pour Mersenne-Twister

    // initialisation des graines des generateurs
    srand(rdtsc());  // rand du C
    sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
    // Initialisation de la clé et du plaintext pour l'AES
    // 45 est un paramètre qui doit changer à chaque initialisation
    init_rand(Kx, Px, NK, NB, 45);
    KeyExpansion(Kex,Kx); // AES : sous-clefs
}

void writeFile(int nbr_of_value)
{
    int i=0;

    int output_rand; // sortie du rand du C
    word32 output_AES; // sortie pour l'AES
    word16 output_VN; // sortie pour pour Von Neumann
    word32 output_MT; // sortie pour Mersenne-Twister

    ///init files
    FILE* rand_file = fopen("output/rand_value.m","w");
    FILE* VN_file = fopen("output/VN_value.m","w");
    FILE* MT_file = fopen("output/MT_value.m","w");
    FILE* AES_file = fopen("output/AES_value.m","w");

    fprintf(rand_file,"function [x] = randValue()\nx = [");
    fprintf(VN_file,"function [x] = vnValue()\nx = [");
    fprintf(MT_file,"function [x] = mtValue()\nx = [");
    fprintf(AES_file,"function [x] = aesValue()\nx = [");

    for( i = 0 ; i < nbr_of_value-1 ; i++)
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
}
