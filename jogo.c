// A # representam diretivas que especificam como o compilador deve processar o código fonte

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    //Cabeçalho do jogo
    printf("\n\n");
    printf("   _______________________________________     \n");
    printf("  /                                       \\   \n");
    printf(" /   _   _   _                 _   _   _   \\  \n");
    printf(" |  | |_| |_| |   _   _   _   | |_| |_| |  |   \n");
    printf(" |   \\   _   /   | |_| |_| |   \\   _   /   | \n");
    printf(" |    | | | |     \\       /     | | | |    |  \n");
    printf(" |    | |_| |______|     |______| |_| |    |   \n");
    printf(" |    |              ___              |    |   \n");
    printf(" |    |  _    _    (     )    _    _  |    |   \n");
    printf(" |    | | |  |_|  (       )  |_|  | | |    |   \n");
    printf(" |    | |_|       |       |       |_| |    |   \n");
    printf(" |   /            |_______|            \\   |  \n");
    printf(" |  |___________________________________|  |   \n");
    printf(" |         Seja bem vindo ao nosso         |   \n");
    printf("  \\           jogo de adivinhação!        /   \n");
    printf("   \\_____________________________________/    \n");

    //variáveis de escopo global
    int chute;
    int nivel;
    int acertou;
    int tentativas; // é uma variável que vai contar a quantidade de tentativas que o usuário utiliza para tentar adivinhar o jogo
    double pontos = 1000; //quantidade de pontos iniciais no jogo

    //gerador de números secretos aleatório
    srand(time(0));
    int numerosecreto = rand() % 100;
    printf("%d \n", numerosecreto);

    //escolha do nível de dificuldade do jogo
    printf("Escolha o nível de dificuldade: \n");
    printf("(1) Fácil   (2) Médio   (3) Difícil \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel); //o & indica o ponteiro (endereço) da variável 

    switch(nivel)
    {
        case 1:
            tentativas = 15;
            break; 
        case 2:
            tentativas = 10;
            break;
        default:
            tentativas = 5;
            break;
    }


    //parte principal do jogo 
    for(int i = 1; i <= tentativas; i++)
    {    
        printf("-> Tentativa %d de %d\n", i, tentativas);
       
        printf("Qual seu chute? ");
        scanf("%d", &chute);

        
       
        //Resolvendo o problema de chutarem números negativos
        if(chute < 0) 
        {
            printf("Nãe é possível chutar números negativos! \n");
            i--; //para não contar como tentativa
            continue;
        }

        //checagem do número
        acertou = chute == numerosecreto;
        if(acertou)
        {


            break; // caso o usuário acerte a gente não quer que o loop continue e o break serve para justamente interromper o loop
        }
        else if(chute > numerosecreto)
        {
            printf("Seu chute foi maior que o número secreto. \n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto. \n");
        }

        //calculo da quantidade de pontos
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;    
    }  

    //mensagem final do jogo
    printf("Fim de jogo!\n");
    printf("\n");
    if(acertou)
    {
        printf("\n\n");
        printf("                          ______                    \n");
        printf(" _________      .------'''      '''-----.           \n");  
        printf(":______.-':     :  .-----------------.  :           \n");  
        printf("| ______  |     | :                   : |           \n");  
        printf("|:______B:|     | |      0     0      | |           \n");  
        printf("|:______B:|     | |                   | |           \n"); 
        printf("|:______B:|     | |         -         | |           \n");  
        printf("|         |     | |     \\      /      | |           \n");
        printf("|:_____:  |     | |      \\____/       | |           \n");  
        printf("|    ==   |     | :                   : |           \n");
        printf("|       O |     :  '-----------------'  :           \n");  
        printf("|       o |     :'-----...______...-----'           \n");
        printf("|       o |-._.-i____/'             \\.__             \n");
        printf("|'-.____o_|   '-.   '-...______...-'  `-._          \n");
        printf(":_________:      `.____________________   `-.___.-. \n");
        printf("                .'.eeeeeeeeeeeeeeeeee.'.      :___: \n");
        printf("            .'.eeeeeeeeeeeeeeeeeeeeee.'.            \n");
        printf("            :____________________________:          \n");
        printf("Parabéns, você acertou! \n");
        printf("Você fez %.2f pontos. Até a próxima! \n\n", pontos);
    } else 
    {
        printf("\n\n");
        printf("                         ______                     \n");
        printf("_________       .-----'''      '''------.            \n");
        printf(":______.-':     :  .-----------------.  :           \n");   
        printf("| ______  |     | :                   : |           \n");   
        printf("|:______B:|     | |      0     0      | |           \n");
        printf("|:______B:|     | |             `     | |           \n");
        printf("|:______B:|     | |         -         | |           \n");
        printf("|         |     | |       ______      | |           \n");
        printf("|:_____:  |     | |      /      \\     | |           \n");
        printf("|    ==   |     | :                   : |           \n");
        printf("|       O |     :  '-----------------'  :           \n");
        printf("|       o |     :'-----...______...-----'           \n");
        printf("|       o |-._.-i____/'             \\.__            \n");
        printf("|'-.____o_|   '-.   '-...______...-'  `-._          \n");
        printf(":_________:      `.____________________   `-.___.-. \n");
        printf("                .'.eeeeeeeeeeeeeeeeee.'.      :___: \n");
        printf("            .'.eeeeeeeeeeeeeeeeeeeeee.'.            \n");
        printf("            :____________________________:          \n");
        printf("\n\n");
        printf("\nVocê perdeu! Tente novamente!\n\n");
    }
}