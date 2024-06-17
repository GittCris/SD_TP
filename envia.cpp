#include <iostream>
#include <string>
#include <csignal>  // Para manipulação de sinais

using namespace std;

const char signal_names[64][10] = {
    "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGTRAP", "SIGABRT", "SIGBUS", "SIGFPE",
    "SIGKILL", "SIGUSR1", "SIGSEGV", "SIGUSR2", "SIGPIPE", "SIGALRM", "SIGTERM", "SIGSTKFLT",
    "SIGCHLD", "SIGCONT", "SIGSTOP", "SIGTSTP", "SIGTTIN", "SIGTTOU", "SIGURG", "SIGXCPU",
    "SIGXFSZ", "SIGVTALRM", "SIGPROF", "SIGWINCH", "SIGIO", "SIGPWR", "SIGSYS"
};


string getSignalString(int signal_num) {
    if (signal_num >= 1 && signal_num <= 31) {
        return signal_names[signal_num - 1];
        
    } else {
        return "Sinal Desconhecido";
    }
}

int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <PID> <SINAL>" << endl;
        return 1; // Encerra o programa com código de erro
    }

    int pid, signal_num;
    pid = stoi(argv[1]); // PID do processo alvo
    signal_num = stoi(argv[2]); // Número do sinal a ser enviado


    // Tenta enviar o sinal para o processo alvo
    if (kill(pid, signal_num) != 0) {
        // Se não for possível enviar o sinal, exibe uma mensagem de erro
        cerr << "Erro: " << "PID " << to_string(pid) << " não encontrado" << endl;
        return 1; // Encerra o programa com código de erro
    }

    string signalString = getSignalString(signal_num);

    // Se tudo ocorrer bem, imprime uma mensagem indicando que o sinal foi enviado com sucesso
    cout << "Sinal enviado: " << signalString <<  " (" << signal_num << ") " "para o PID " << pid << endl;

    return 0; // Encerra o programa com sucesso
}
