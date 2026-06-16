#include <iostream>
#include <stack>
#include <string>

class AutomatoPilha {
private:
    std::stack<char> pilha;
    enum Estado { Q0, Q1, REJEITADO };
    Estado estadoAtual;

public:
    AutomatoPilha() {
        reset();
    }

    void reset() {
        while (!pilha.empty()) {
            pilha.pop();
        }
        estadoAtual = Q0;
    }

    bool processarString(const std::string& str) {
        reset();
        
        std::cout << "\nProcessando string: \"" << str << "\"\n";
        std::cout << "Estado Inicial: q0 | Pilha: [vazia]\n";

        for (char ch : str) {
            switch (estadoAtual) {
                case Q0:
                    if (ch == 'a') {
                        pilha.push('A');
                        std::cout << "Leu 'a': Empilha 'A'. ";
                    } else if (ch == 'b' && !pilha.empty()) {
                        pilha.pop();
                        estadoAtual = Q1;
                        std::cout << "Leu 'b': Desempilha 'A', vai para q1. ";
                    } else {
                        estadoAtual = REJEITADO;
                    }
                    break;

                case Q1:
                    if (ch == 'b' && !pilha.empty()) {
                        pilha.pop();
                        std::cout << "Leu 'b': Desempilha 'A'. ";
                    } else {
                        estadoAtual = REJEITADO;
                    }
                    break;

                case REJEITADO:
                    break;
            }

            if (estadoAtual == REJEITADO) {
                std::cout << "Caractere '" << ch << "' invalido no estado atual. Transicao para REJEITADO.\n";
                return false;
            }
            
            std::cout << "Tamanho da Pilha: " << pilha.size() << "\n";
        }

        if (estadoAtual == Q1 && pilha.empty()) {
            return true;
        }
        
        return false;
    }
};

int main() {
    AutomatoPilha ap;
    
    std::string testes[] = {"ab", "aabb", "aaabbb", "aab", "abb", "ba", "a"};

    for (const std::string& teste : testes) {
        if (ap.processarString(teste)) {
            std::cout << ">> ACEITA <<\n";
        } else {
            std::cout << ">> REJEITADA <<\n";
        }
        std::cout << "---------------------------------------------\n";
    }

    return 0;
}
