#include <csignal>    // Para manipulação de sinais
#include <unistd.h>  // Para getpid()
#include <iostream>  // Para entrada/saída padrão
#include <cstring>   // Para manipulação de strings

using namespace std;

const char signal_names[64][10] = {
    "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGTRAP", "SIGABRT", "SIGBUS", "SIGFPE",
    "SIGKILL", "SIGUSR1", "SIGSEGV", "SIGUSR2", "SIGPIPE", "SIGALRM", "SIGTERM", "SIGSTKFLT",
    "SIGCHLD", "SIGCONT", "SIGSTOP", "SIGTSTP", "SIGTTIN", "SIGTTOU", "SIGURG", "SIGXCPU",
    "SIGXFSZ", "SIGVTALRM", "SIGPROF", "SIGWINCH", "SIGIO", "SIGPWR", "SIGSYS"
};

// Função de manipuladores de sinais
void signal_handler( int signal_num ) {
    if (signal_num == SIGINT) {
        cout << "Recebi um SIGINT (" << signal_num << "). Interrompendo o processo!" << endl;
        exit(2); // Encerra o processo com um código de saída 2
    }

    else if (signal_num >= 1 && signal_num <= 31) {
        cout << "Recebi o sinal " << signal_names[signal_num - 1] << " (" << signal_num << ")." << endl;
    } 
    
    else {
        cout << "Sinal desconhecido" << endl;
    }
}

int main(int argc, const char *argv[]) {
    // Verifica se o argumento de linha de comando foi fornecido
    if (argc < 2) {
        cerr << "Você deve especificar o tipo de espera: busy ou blocking\n";
        return 1; // Encerra o programa com código de erro
    }

    string wait_format = argv[1]; // Obtém o tipo de espera a partir do argumento de linha de comando
    cout << "PID atual do processo: " << getpid() << endl; // Imprime o PID do processo atual
    cout << "Sinais permitidos: 1 ao 31, com exceção do 9 e 19." << endl;


    // Configura manipuladores de sinal para os sinais do 1 ao 31, com exceção do 9 e 19 e ignora os outros
    for (int i = 1; i <= 64; i++) {
         signal(i, signal_handler);
    }
    
    if (wait_format == "blocking") {
        // Espera bloqueada: entra em um loop e espera por sinais
        while (true) {
            pause(); // Aguarda um sinal
        }
        
    } else if (wait_format == "busy") {
        // Espera ocupada: entra em um loop infinito
        while (true);

    } else {
        // Se o tipo de espera não for válido, lança uma exceção
        cerr << "Você deve especificar o tipo de espera: busy ou blocking" << endl;
        return 1;
    }

    return 0; // Encerra o programa com sucesso
}
